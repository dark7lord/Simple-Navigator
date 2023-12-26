#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"
#include "inc/GraphExceptions.h"

namespace s21 {

using Matrix = std::vector<std::vector<size_t>>;
using size_t = std::size_t;

class Graph {
public:
  Graph(): size_matrix_(0) {};
  ~Graph() {};

  void LoadGraphFromFile(const std::string& filename);
  void ExportGraphToDot(const std::string& filename);
  void PrintGraph();
  void PrintGraphInBrowser();
  size_t GetSize() { return size_matrix_; }
  bool is_digraph = false;

private:
  Matrix matrix_;
  size_t size_matrix_;

  const std::string ToString_() const;
};

}
#endif
