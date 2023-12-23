#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"

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

  void LoadGraphFromFile(const std::string& filename);
  void ExportGraphToDot(const std::string& filename);
  void PrintGraph();

private:
  std::vector<std::vector<size_t>> matrix_;
  std::size_t size_matrix_;
};

}
#endif
