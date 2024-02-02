#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "inc/GraphExceptions.h"

namespace s21 {

using Matrix = std::vector<std::vector<size_t>>;
using size_t = std::size_t;

class Graph {
 public:
  Graph() : size_matrix_(0){};
  ~Graph(){};

  void LoadGraphFromFile(const std::string& filename);
  void ExportGraphToDot(const std::string& filename);
  // void PrintGraph() const;
  // void PrintGraphInBrowser();
  size_t GetSize() const { return size_matrix_; }
  Matrix GetMatrix() const { return matrix_; }
  const std::string ToString() const;
  bool is_digraph = false;

 private:
  Matrix matrix_;
  size_t size_matrix_;
};

}  // namespace s21
#endif
