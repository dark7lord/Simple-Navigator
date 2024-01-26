#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <climits>
#include <random>

#include "../Graph/s21_graph.h"
#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"

namespace s21 {
struct TsmResult {
  std::vector<size_t> vertices;    // массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
  double distance;  // длина этого маршрута
};

using AntWay = TsmResult;

struct Edge {
  int from;
  int to;
  int weight;

  Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

class GraphAlgorithms {
public:
  GraphAlgorithms() {};
  ~GraphAlgorithms() {};
  std::vector<size_t> visited;

  std::vector<size_t> DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<size_t> BreadthFirstSearch(Graph &graph, size_t start_vertex);
  std::vector<Edge> GetLeastSpanningTree(const Matrix& graph);
  Matrix GetShortestPathsBetweenAllVertices(Graph &graph);
  int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  AntWay SolveTravelingSalesmanProblem(Graph &graph);

private:
  void Print(std::set<unsigned> &);

};

bool HasElement(std::vector<size_t> visited, size_t elem);

class AntGraph {
  public:
  AntGraph() {};
  ~AntGraph() {};

  void FindBestWay(Graph &graph);
  AntWay GetBestWay() {return this->bestPath_;}

  private:
    size_t vCount_;
    size_t itCount_;
    size_t antCount_;
    const double basePheromone_ = 5;
    const double kEvaporatoin_ = 0.1;
    const double kAlpha_ = 1.2;
    const double kBeta_ = 1.0;
    const double kQ_ = 400.0;

    std::vector<std::vector<double>> pheromone_;
    std::vector<AntWay> ants_;
    AntWay bestPath_;

    void InitAntsAndPheromone(const Graph &graph);
    void UpdatePheromone(/*const Graph &graph*/);
    int RandomChoice();
    bool ChooseNextPoint(AntWay *ant, const Graph &graph);
    std::vector<double> ProbabilityScale(std::vector<std::size_t> variants, const Graph &graph, size_t currentPoint);
    size_t NextPointCalc(std::vector<std::size_t> variants, const Graph &graph, size_t currentPoint);
};

}
#endif
