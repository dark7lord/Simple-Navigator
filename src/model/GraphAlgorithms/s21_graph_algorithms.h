#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include <string>

#include "../Graph/s21_graph.h"

#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"

//#include <queue>
//#include <stack>

#include <set>
#include <vector>

namespace s21 {

class GraphAlgorithms {
public:
  GraphAlgorithms(Graph graph) : graph_(graph) {
    std::cout << "Creating Graph Algorithms" << std::endl;
  };
  // Graph(const Graph&);
  ~GraphAlgorithms() {
    std::cout << "Deleting Graph" << std::endl;
  };

  std::vector<size_t> visited;
  struct Edge {
    int from;
    int to;
    int weight;

      // Конструктор для удобного создания ребра
      //Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
  };

  using Matrix = std::vector<std::vector<size_t>>;
  //std::vector<size_t> DepthFirstSearch(Graph &graph, int start_vertex);
  //std::vector<size_t> BreadthFirstSearch(Graph &graph, int start_vertex);

  Matrix GetLeastSpanningTree(Graph &graph);


private:
  Graph graph_{};
};

}
#endif
