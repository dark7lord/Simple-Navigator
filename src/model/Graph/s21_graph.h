#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

// #include "inc/s21_list.h"
// #include "inc/s21_queue.h"
// #include "inc/s21_stack.h"

namespace s21 {

class Graph {
public:
  Graph() {
    std::cout << "Creating Graph" << std::endl;
  };
  // Graph(const Graph&);
  // Graph(const Graph&);
  ~Graph() {
    std::cout << "Deleting Graph" << std::endl;
  };

  void LoadGraphFromFile(std::string ) {};
  void ExportGraphToDot(std::string ) {};
};

int sum (int a, int b);

}

#endif
