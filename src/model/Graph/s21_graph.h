#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"
#include "inc/GraphExceptions.h"

namespace s21 {

using Matrix = std::vector<std::vector<size_t>>;
using size_t = std::size_t;

class Graph {
public:
  Graph() {};
  // Graph(const Graph&);
  // Graph(const Graph&);
  ~Graph() {};

  void LoadGraphFromFile(const std::string& filename);
  void ExportGraphToDot(const std::string& filename);
  void PrintGraph();

private:
  Matrix matrix_;
  size_t size_matrix_;
};

}
#endif
