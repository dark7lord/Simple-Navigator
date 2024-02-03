#include <gtest/gtest.h>

#include "s21_graph_algorithms.h"

namespace s21 {

TEST(DFS, test1) {
  s21::Graph graph;
  s21::GraphAlgorithms test;
  graph.LoadGraphFromFile("tests/files/penta.txt");
  std::vector<size_t> expected = {3, 1, 2, 4, 5};
  std::vector<size_t> result = test.DepthFirstSearch(graph, 3);
  ASSERT_EQ(result, expected);
}

}  // namespace s21
