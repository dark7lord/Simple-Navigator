#include <gtest/gtest.h>
#include "../s21_graph_algorithms.h"

TEST(tempTest, sum) {
  ASSERT_EQ(1 + 1, 2);
}

TEST(BFS, test1) {
  s21::Graph graph;
  s21::GraphAlgorithms test; 
  // graph.PrintGraph();
  graph.LoadGraphFromFile("tests/files/graph_7x7.txt");
  // std::vector<size_t> solution = {1, 2, 3, 5, 4, 6, 7};
  // std::vector<size_t> arr = test.BreadthFirstSearch(graph, 1);
  // ASSERT_EQ(arr, solution);

}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
