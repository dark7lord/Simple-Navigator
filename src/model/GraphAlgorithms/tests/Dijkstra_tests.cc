#include <gtest/gtest.h>

#include "../s21_graph_algorithms.h"

namespace s21 {
TEST(Dijkstra, test1) {
  s21::Graph graph;
  s21::GraphAlgorithms test;
  graph.LoadGraphFromFile("tests/files/digraph_10x10.txt");
  int result = test.GetShortestPathBetweenVertices(graph, 1, 9);
  int solution = 26;
  ASSERT_EQ(result, solution);
  result = test.GetShortestPathBetweenVertices(graph, 3, 5);
  solution = 21;
  ASSERT_EQ(result, solution);
  result = test.GetShortestPathBetweenVertices(graph, 6, 10);
  solution = 15;
  ASSERT_EQ(result, solution);
}
}  // namespace s21
