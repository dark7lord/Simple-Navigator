#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include <string>

#include "../Graph/s21_graph.h"

#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"

#include <vector>
#include <set>

namespace s21 {

struct Edge {
  int from;
  int to;
  int weight;

  Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

class GraphAlgorithms {
public:
  GraphAlgorithms() {
    std::cout << "Creating Graph Algorithms" << std::endl;
  };
  ~GraphAlgorithms() {
    std::cout << "Deleting Graph" << std::endl;
  };

  std::vector<size_t> visited;
  std::vector<Edge> GetLeastSpanningTree(const Matrix& graph);



private:
  void Print(std::set<unsigned> &);
};

}
#endif
