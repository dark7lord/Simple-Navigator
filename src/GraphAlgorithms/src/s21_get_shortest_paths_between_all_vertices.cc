#include "s21_graph_algorithms.h"

namespace s21 {

// static std::vector<size_t> GetShortestPathVertices(const Matrix& next, size_t
// start, size_t finish) {
//   std::vector<size_t> path;
//   size_t infinity = -1;
//   for (size_t v = start - 1;
//     ( start != finish && !hasElement(path, finish - 1) ) ||
//     ( start == finish && next[start - 1][finish - 1] != finish );
//     v = next[v][finish - 1]
//   ) {
//     if (v == (finish - 1) && hasElement(path, v)) {
//       path.push_back(v);
//       break;
//     }
//     if (v == infinity) {
//       path.clear();
//       break;
//     }
//     path.push_back(v);
//   }
//   return path;
// }

// static void PrintPath(const std::vector<size_t>& path) {
//   if (path.empty()) {
//     std::cout << "No path" << std::endl;
//     return;
//   }

//   for (size_t i = 0; i < path.size(); ++i) {
//     std::cout << (i == 0 ? "" : " - ") << path[i] + 1;
//   }
//   std::cout << std::endl;
// }

Matrix GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph& graph) {
  size_t infinity = -1;
  size_t size = graph.GetSize();
  Matrix distance_matrix = graph.GetMatrix();
  // Matrix next(size, std::vector<size_t>(size, infinity));

  for (size_t row = 0; row < size; ++row) {
    for (size_t col = 0; col < size; ++col) {
      if (row != col && distance_matrix[row][col] == 0) {
        distance_matrix[row][col] = infinity;
      }
      // else {
      //   next[row][col] = col;
      // }
    }
  }

  for (size_t middle = 0; middle < size; ++middle) {
    for (size_t src = 0; src < size; ++src) {
      for (size_t dest = 0; dest < size; ++dest) {
        size_t src_dest = distance_matrix[src][dest];
        size_t src_middle = distance_matrix[src][middle];
        size_t middle_dest = distance_matrix[middle][dest];
        size_t weight = src_middle + middle_dest;

        if (src_middle != infinity && middle_dest != infinity &&
            weight < src_dest) {
          distance_matrix[src][dest] = weight;
          // next[src][dest] = next[src][middle];
        }
      }
    }
  }

  // size_t start = 2, finish = 1;
  // auto path = GetShortestPathVertices(next, start, finish);
  // PrintPath(path);

  return distance_matrix;
}

}  // namespace s21
