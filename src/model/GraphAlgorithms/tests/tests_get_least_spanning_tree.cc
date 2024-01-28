#include <gtest/gtest.h>
#include "../s21_graph_algorithms.h"

// TEST(tempTest, sum) {
//   ASSERT_EQ(1 + 1, 2);
// }


//GetLeastSpanningTree
TEST(GraphAlgorithmsTest, GetLeastSpanningTree) {
  s21::Matrix expected = {
    {0, 2, 0, 6, 0},
    {0, 0, 3, 0, 5},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  s21::Graph graph;
  s21::GraphAlgorithms algorithms;
  graph.LoadGraphFromFile("tests/files/digraph_5x5_least.txt");
  s21::Matrix result = algorithms.GetLeastSpanningTree(graph);

  ASSERT_EQ(result.size(), expected.size());

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 5; ++j) {
      ASSERT_EQ(result[i][j], expected[i][j]);
    }
  }
}

// int main(int argc, char* argv[]) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
