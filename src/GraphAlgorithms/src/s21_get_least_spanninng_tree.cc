#include <iostream>

#include "../s21_graph_algorithms.h"

namespace s21 {

// void GraphAlgorithms::Print(std::set<unsigned>& set) {
//   for (auto it = set.begin(); it != set.end(); it++) {
//     std::cout << *it << std::endl;
//   }
// }

Matrix GraphAlgorithms::GetLeastSpanningTree(Graph& graph) {
  size_t numVertices = graph.GetSize();
  Matrix origin_matrix = graph.GetMatrix();
  size_t cheapestEdgeSize = numVertices - 1;
  // s21::Matrix matrix = std::vector<std::vector<size_t>>;
  Matrix matrix(numVertices, std::vector<size_t>(numVertices, 0));

  std::vector<size_t> cheapestCost(numVertices,
                                   std::numeric_limits<size_t>::max());
  std::vector<Edge> cheapestEdge(numVertices,
                                 Edge(-1, -1, std::numeric_limits<int>::max()));
  std::vector<bool> inTree(numVertices, false);

  size_t startVertex = 0;
  cheapestCost[startVertex] = 0;
  for (size_t i = 0; i < numVertices; ++i) {
    size_t currentVertex = numVertices;
    for (size_t v = 0; v < numVertices; ++v) {
      if (!inTree[v] && (currentVertex == numVertices ||
                         cheapestCost[v] < cheapestCost[currentVertex])) {
        currentVertex = v;
      }
    }
    inTree[currentVertex] = true;
    for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
      if (origin_matrix[currentVertex][neighbor] > 0 && !inTree[neighbor] &&
          origin_matrix[currentVertex][neighbor] < cheapestCost[neighbor]) {
        cheapestCost[neighbor] = origin_matrix[currentVertex][neighbor];
        cheapestEdge.at(neighbor) = Edge(
            currentVertex, neighbor, origin_matrix[currentVertex][neighbor]);
      }
    }
  }
  std::vector<Edge> spanning_tree(
      cheapestEdgeSize, Edge(-1, -1, std::numeric_limits<int>::max()));

  int key = 0;
  for (const s21::Edge& edge : cheapestEdge) {
    if (edge.from == -1) {
      continue;
    }
    spanning_tree.at(key) = edge;
    key++;
  }

  // for (auto& [from, to, weight] : spanning_tree) {
  //   matrix[from][to] = weight;
  // }

  for (const auto& [from, to, weight] : spanning_tree) {
    matrix[from][to] = weight;
  }

  // PrintMatrix(matrix);

  return matrix;
}

}  // namespace s21
