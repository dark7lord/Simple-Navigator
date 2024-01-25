#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "../Graph/s21_graph.h"
#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"

namespace s21 {

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

private:
  void Print(std::set<unsigned> &);
};

}
#endif
