#include <gtest/gtest.h>
#include "../s21_graph_algorithms.h"

TEST(tempTest, sum) {
  ASSERT_EQ(1 + 1, 2);
}


//GetLeastSpanningTree
// TEST(GraphAlgorithmsTest, GetLeastSpanningTree) {
//   s21::Matrix matrix_graph = {
//       {0, 2, 0, 6, 0},
//       {2, 0, 3, 8, 5},
//       {0, 3, 0, 0, 7},
//       {6, 8, 0, 0, 9},
//       {0, 5, 7, 9, 0}
//   };

//   std::vector<s21::Edge> expected = {
//       s21::Edge(0, 1, 2),
//       s21::Edge(1, 2, 3),
//       s21::Edge(0, 3, 6),
//       s21::Edge(1, 4, 5)
//   };
  
//   s21::Graph graph;
//   s21::GraphAlgorithms algorithms;
//   std::vector<s21::Edge> result = algorithms.GetLeastSpanningTree(matrix_graph);

//   ASSERT_EQ(result.size(), expected.size());
//   for (size_t i = 0; i < result.size(); ++i) {
//     ASSERT_EQ(result[i].from, expected[i].from);
//     ASSERT_EQ(result[i].to, expected[i].to);
//     ASSERT_EQ(result[i].weight, expected[i].weight);
//   }
// }

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
