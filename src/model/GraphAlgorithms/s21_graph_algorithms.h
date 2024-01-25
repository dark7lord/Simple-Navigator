#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include <string>

#include "../Graph/s21_graph.h"

#include "../templates/s21_list.h"
#include "../templates/s21_queue.h"
#include "../templates/s21_stack.h"

namespace s21 {

class GraphAlgorithms {
public:
  GraphAlgorithms() {};
  ~GraphAlgorithms() {};

  std::vector<size_t> DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<size_t> BreadthFirstSearch(Graph &graph, size_t start_vertex);

  Matrix GetShortestPathsBetweenAllVertices(Graph &graph);
  // void PrintPath(const Matrix& next, size_t start, size_t end);
};

// void PrintPaths(const Matrix& adjacency_matrix, const Matrix& distance_matrix);
bool hasElement(std::vector<size_t> visited, size_t elem);

}

#endif
