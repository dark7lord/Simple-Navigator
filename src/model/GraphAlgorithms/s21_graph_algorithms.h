#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include <string>

#include "../Graph/s21_graph.h"

// #include "inc/s21_list.h"
// #include "inc/s21_queue.h"
// #include "inc/s21_stack.h"

#include <queue>

namespace s21 {

class GraphAlgorithms {
public:
  GraphAlgorithms() {
    std::cout << "Creating Graph" << std::endl;
  };
  // Graph(const Graph&);
  // Graph(const Graph&);
  ~GraphAlgorithms() {
    std::cout << "Deleting Graph" << std::endl;
  };

  void DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<size_t> BreadthFirstSearch(Graph &graph, int start_vertex);
};

int sum (int a, int b);

}

#endif
