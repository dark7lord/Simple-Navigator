#include "../s21_graph_algorithms.h"

namespace s21 {

// AntWay GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
//     //AntWay path; // лучший путь
//  // проверка графа
//  // инициализация феромонов+
//     s21::AntGraph antGraph;
//     // if (BreadthFirstSearch(graph, 1).size() != graph.GetSize()) throw std::invalid_argument("Граф не является связным!\n");
//     std::cout << "4" << std::endl;
//     antGraph.FindBestWay(graph);
//     AntWay solution = antGraph.GetBestWay();
//     if (solution.vertices.size() >= graph.GetSize() || (solution.vertices.front() != solution.vertices.back())) throw std::invalid_argument("Задача не имеет решения!!\n");
//     return solution;
// }
AntWay GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
    //AntWay path; // лучший путь
 // проверка графа
 // инициализация феромонов+
    s21::AntGraph antGraph;

    antGraph.FindBestWay(graph);
    return antGraph.GetBestWay();
}

void AntGraph::FindBestWay(Graph &graph) {
    InitAntsAndPheromone(graph);
    // std::cout << "***" << std::endl;
 // кол во итераций
 size_t iteration = 0;
 // цикл { 
     while (iteration++ < itCount_) {
     //путь каждого муравья цикл {
         for (auto &ant : ants_) {
             //std::vector<size_t> visited;
             bool haveWay = true;
             while (ant.vertices.size() <= vCount_ && haveWay)
             {
                haveWay = ChooseNextPoint(&ant, graph); // Выбор следующего города
                //  std::cout << haveWay << std::endl;

             }
            //  std::cout << '!' << std::endl;
             if ((ant.vertices[1]) && ant.vertices.size() == (vCount_ + 1) && ant.vertices.front() == ant.vertices.back()) { // если верный путь построен
                
                // std::cout << "!!" << std::endl;
                //ChooseShortestPath(ant);
                std::cout << '+' << ant.distance << std::endl;
                std::cout << "+*";
                // for (size_t i = 0; i < ant.vertices.size(); i++) {
                //    ant.vertices[i] += 1;
                //     std::cout <<  ant.vertices[i] << " ";
                // }
                // std::cout <<  std::endl;
                if (ant.distance < bestPath_.distance) {       //нахождение кратчайшего пути
                    //  std::cout <<  std::endl;
                    bestPath_ = ant;
                    itCount_+= vCount_*5;
                }
            }
            // ant.distance = INT_MAX;
            // ant.vertices.clear();
         }
        std::cout << "UPH" << std::endl;
     // обновление феромонов+
    UpdatePheromone(/*graph*/);
 //}
 for (auto &ant : ants_) {
        ant.distance = 0;
        ant.vertices.clear();
 }
    // for (auto i : bestPath_.vertices) {
    //     i = i + 1;
    //     std::cout << i << " ";
        
    // }
    std::cout <<  std::endl;
    std::cout << "length " << bestPath_.distance << std::endl;
    std::cout << "it " << iteration << std::endl;
   
    }
    for (size_t i = 0; i < bestPath_.vertices.size(); i++) {
                   bestPath_.vertices[i] += 1;
                    std::cout <<  bestPath_.vertices[i] << " ";
                }
                std::cout <<  std::endl;

}

// void AntGraph::ChooseShortestPath(AntWay A) {
//     if (A.distance < bestPath_.distance) bestPath_ = A;
// }
 // инициализация феромонов
void AntGraph::InitAntsAndPheromone(const Graph &graph) { 
    vCount_ = graph.GetSize();
    itCount_ = vCount_;
    antCount_ = vCount_ * 3;
    std::vector<std::vector<double>> fMatrix(vCount_, std::vector<double>(vCount_));
    for (size_t row = 0; row < vCount_; row++) {
        for (size_t col = 0; col < vCount_; col++) {
            if (graph.GetMatrix()[row][col]) { fMatrix[row][col] = basePheromone_;}
        }
    }
    pheromone_ = std::move(fMatrix);
    ants_.resize(antCount_);
    bestPath_.distance = INT_MAX;
}

void AntGraph::UpdatePheromone(/*const Graph &graph*/) {
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
            std::cout << "777" << std::endl;
            std::cout << ants_[i].distance << std::endl;
        for (size_t j = 0; j < vCount_; j++) {
            size_t point1 = ants_[i].vertices[j];
            size_t point2 = ants_[i].vertices[j + 1];
            std::cout << "123-" << point1 << "-" << point2 << std::endl;
            std::cout << pheromone_[point1][point2] << std::endl;
            pheromone_[point1][point2] += (kQ_ / ants_[i].distance);
            std::cout << "888" << std::endl;
            //if (graph.GetMatrix()[point1][point2] == graph.GetMatrix()[point2][point1]) pheromone_[point2][point1] = pheromone_[point1][point2];
        }  
         std::cout << "666" << std::endl;
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
 // будем начинать с 0 элемента
        ant->vertices.push_back(0); 
        }
    currentPoint = ant->vertices.back();
    // std::cout << currentPoint << std::endl;
    for (size_t i = 0; i < vCount_; i++) {  // если есть путь до этого элемента и мы его не посещали, добавляем как вариант
        if ((graph.GetMatrix()[currentPoint][i]) && !HasElement(ant->vertices, i)) {variants.push_back(i);  /*std::cout << i << '-';*/ }
    }
    // std::cout << std::endl;
    
    if (variants.empty()) {
//   std::cout << '*' << "0000" << '*' << std::endl;
        size_t firstElement = ant->vertices[0];
         // если мы закончили и есть путь к первому элементу, возвращаемся в начало
        if (ant->vertices.size() == vCount_ &&  graph.GetMatrix()[currentPoint][firstElement])  {
             ant->vertices.push_back(firstElement); 
            //  std::cout << "firstelement-" << firstElement << std::endl;
             ant->distance += graph.GetMatrix()[currentPoint][firstElement];
        } else {
            ant->distance = INT_MAX;
        }
         
        return false; // в любом случае дальше путь не ищем
// std::cout << '*' << "0000" << '*' << std::endl;
    }
           // std::cout << "4" << std::endl;
    // // // Расчет вероятностей выбора следующего города
    size_t nextPoint = NextPointCalc(variants, graph, currentPoint);
    // std::cout << '*' << nextPoint << '*' << std::endl;
    ant->vertices.push_back(nextPoint);
    ant->distance += graph.GetMatrix()[currentPoint][nextPoint];
    return true;
 
}
std::vector<double> AntGraph::ProbabilityScale(std::vector<std::size_t> variants, const Graph &graph, size_t currentPoint) {
        // // Расчет вероятностей выбора следующего города
    std::vector<double> chance;
    std::vector<double> wish;
    double sumWish = 0.0;
    for (auto v : variants) {
        double t = pheromone_[currentPoint][v];
        double n = 1.0 / graph.GetMatrix()[currentPoint][v];
        wish.push_back(pow(t, kAlpha_) * (pow(n, kBeta_)));
        sumWish += wish.back();
        //  std::cout  << wish.back() << std::endl;
    }
    // std::cout << "sw" << sumWish << std::endl;
    for (auto w : wish) {
        chance.push_back(w / sumWish * 100);
        // std::cout << "///" << chance.back() << std::endl;
    }
    for (size_t i = 1; i < chance.size(); i++) {
        chance[i] = chance[i] + chance[i-1]; // чтобы отложить значения на отрезке вероятностей
        // std::cout << chance[i] << "-"; 
    } 
    // std::cout << std::endl;
    return chance;
}

size_t AntGraph::NextPointCalc(std::vector<std::size_t> variants, const Graph &graph, size_t currentPoint) {
    std::vector<double> chance = ProbabilityScale(variants, graph, currentPoint);
    size_t nextPoint;
     double choose = RandomChoice();
    //  std::cout << '/' << choose << std::endl;
    for (size_t i = 0; i < variants.size(); i++) {
                    // std::cout << chance[i] << '/' << std::endl;
        if (choose <= chance[i]) {

            nextPoint = variants[i];
            break;
        }
    }
    return nextPoint;
}


}

