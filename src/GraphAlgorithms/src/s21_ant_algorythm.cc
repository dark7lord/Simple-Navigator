#include "s21_graph_algorithms.h"

namespace s21 {

AntWay GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
  s21::AntGraph antGraph;
  antGraph.FindBestWay(graph);
  return antGraph.GetBestWay();
}

void AntGraph::FindBestWay(Graph &graph) {
  InitAntsAndPheromone(graph);
  size_t iteration = 0;
  while (iteration++ < itCount_) {
    for (auto &ant : ants_) {
      bool haveWay = true;
      while (ant.vertices.size() <= vCount_ && haveWay) {
        haveWay = ChooseNextPoint(&ant, graph);
      }
      if ((ant.vertices[1]) && ant.vertices.size() == (vCount_ + 1) &&
          ant.vertices.front() ==
              ant.vertices.back()) {  // если верный путь построен
        if (ant.distance < bestPath_.distance) {  //нахождение кратчайшего пути
          bestPath_ = ant;
          itCount_ += vCount_;
        }
      }
    }
    UpdatePheromone();
    for (auto &ant : ants_) {
      ant.distance = 0;
      ant.vertices.clear();
    }
  }
  for (size_t i = 0; i < bestPath_.vertices.size(); i++) {
    bestPath_.vertices[i] += 1;
  }
}

void AntGraph::InitAntsAndPheromone(const Graph &graph) {
  vCount_ = graph.GetSize();
  itCount_ = vCount_;
  antCount_ = vCount_ * 2;
  std::vector<std::vector<double>> fMatrix(vCount_,
                                           std::vector<double>(vCount_));
  for (size_t row = 0; row < vCount_; row++) {
    for (size_t col = 0; col < vCount_; col++) {
      if (graph.GetMatrix()[row][col]) {
        fMatrix[row][col] = basePheromone_;
      }
    }
  }
  pheromone_ = std::move(fMatrix);
  ants_.resize(antCount_);
  bestPath_.distance = INT_MAX;
}

void AntGraph::UpdatePheromone() {
  // испарение
  for (size_t i = 0; i < vCount_; i++) {
    for (size_t j = 0; j < vCount_; j++) {
      pheromone_[i][j] *= (1 - kEvaporatoin_);
      if (pheromone_[i][j] < 0.1) pheromone_[i][j] = 0.1;
    }
  }
  // обновление
  for (size_t i = 0; i < antCount_; i++) {
    if (ants_[i].distance != INT_MAX) {
      for (size_t j = 0; j < vCount_; j++) {
        size_t point1 = ants_[i].vertices[j];
        size_t point2 = ants_[i].vertices[j + 1];
        pheromone_[point1][point2] += (kQ_ / ants_[i].distance);
        // if (graph.GetMatrix()[point1][point2] ==
        // graph.GetMatrix()[point2][point1]) pheromone_[point2][point1] =
        // pheromone_[point1][point2];
      }
    }
  }
}

int AntGraph::RandomChoice() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);
  return dis(gen);
}

bool AntGraph::ChooseNextPoint(AntWay *ant, const Graph &graph) {
  size_t currentPoint;
  std::vector<std::size_t> variants;
  if (ant->vertices.empty()) {
    ant->vertices.push_back(0);
  }
  currentPoint = ant->vertices.back();
  for (size_t i = 0; i < vCount_;
       i++) {  // если есть путь до этого элемента и мы его не посещали,
               // добавляем как вариант
    if ((graph.GetMatrix()[currentPoint][i]) && !HasElement(ant->vertices, i))
      variants.push_back(i);
  }
  if (variants.empty()) {
    size_t firstElement = ant->vertices[0];
    // если мы закончили и есть путь к первому элементу, возвращаемся в начало
    if (ant->vertices.size() == vCount_ &&
        graph.GetMatrix()[currentPoint][firstElement]) {
      ant->vertices.push_back(firstElement);
      ant->distance += graph.GetMatrix()[currentPoint][firstElement];
    } else {
      ant->distance = INT_MAX;
    }
    return false;  // в любом случае дальше путь не ищем
  }
  size_t nextPoint = NextPointCalc(variants, graph, currentPoint);
  ant->vertices.push_back(nextPoint);
  ant->distance += graph.GetMatrix()[currentPoint][nextPoint];
  return true;
}
std::vector<double> AntGraph::ProbabilityScale(
    std::vector<std::size_t> variants, const Graph &graph,
    size_t currentPoint) {
  // // Расчет вероятностей выбора следующего города
  std::vector<double> chance;
  std::vector<double> wish;
  double sumWish = 0.0;
  for (auto v : variants) {
    double t = pheromone_[currentPoint][v];
    double n = 1.0 / graph.GetMatrix()[currentPoint][v];
    wish.push_back(pow(t, kAlpha_) * (pow(n, kBeta_)));
    sumWish += wish.back();
  }
  for (auto w : wish) {
    chance.push_back(w / sumWish * 100);
  }
  for (size_t i = 1; i < chance.size(); i++) {
    chance[i] =
        chance[i] +
        chance[i - 1];  // чтобы отложить значения на отрезке вероятностей
  }
  return chance;
}

size_t AntGraph::NextPointCalc(std::vector<std::size_t> variants,
                               const Graph &graph, size_t currentPoint) {
  std::vector<double> chance = ProbabilityScale(variants, graph, currentPoint);
  size_t nextPoint;
  double choose = RandomChoice();
  for (size_t i = 0; i < variants.size(); i++) {
    if (choose <= chance[i]) {
      nextPoint = variants[i];
      break;
    }
  }
  return nextPoint;
}

}  // namespace s21
