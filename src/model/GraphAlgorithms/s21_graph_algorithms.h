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

  // std::vector<size_t> visited;
  // std::stack<size_t> myStack;

  std::vector<size_t> DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<size_t> BreadthFirstSearch(Graph &graph, int start_vertex);

private:
  Graph graph_{};
};

}
#endif
