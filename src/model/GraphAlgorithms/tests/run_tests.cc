#include <gtest/gtest.h>
#include "../s21_graph_algorithms.h"

// TEST(tempTest, sum) {
//   ASSERT_EQ(1 + 1, 2);
// }
namespace s21 {

// TEST(BFS, test1) {
//   s21::Graph graph;
//   s21::GraphAlgorithms test;
//   graph.LoadGraphFromFile("tests/files/graph_7x7.txt");
//   std::vector<size_t> solution = {1, 2, 3, 4, 5, 6, 7};
//   std::vector<size_t> arr = test.BreadthFirstSearch(graph, 1);
//   ASSERT_EQ(arr, solution);
//   solution = {3, 1, 6, 7, 2, 4, 5};
//   arr = test.BreadthFirstSearch(graph, 3);
//   ASSERT_EQ(arr, solution);
// }

// TEST(BFS, test2) {
//   s21::Graph graph;
//   s21::GraphAlgorithms test;
//   graph.LoadGraphFromFile("tests/files/graph_21x21.txt");
//   std::vector<size_t> solution = {1, 2, 3, 8, 4, 7, 9, 10, 5, 6, 11, 13, 21, 12, 14, 15, 20, 16, 17, 19, 18};
//   std::vector<size_t> arr = test.BreadthFirstSearch(graph, 1);
//   ASSERT_EQ(arr, solution);
//   solution = {15, 12, 17, 21, 11, 14, 16, 18, 19, 20, 5, 7, 10, 13, 4, 6, 3, 8, 9, 2, 1};
//   arr = test.BreadthFirstSearch(graph, 15);
//   ASSERT_EQ(arr, solution);
// }

// TEST(Dijkstra, test1) {
//   s21::Graph graph;
//   s21::GraphAlgorithms test;
//   graph.LoadGraphFromFile("tests/files/digraph_10x10.txt");  
//   int result = test.GetShortestPathBetweenVertices(graph, 1, 9);
//   int solution = 26;
//   ASSERT_EQ(result, solution);
//   result = test.GetShortestPathBetweenVertices(graph, 3, 5);
//   solution = 21;
//   ASSERT_EQ(result, solution);
//   result = test.GetShortestPathBetweenVertices(graph, 6, 10);
//   solution = 15;
//   ASSERT_EQ(result, solution);
// }

// TEST(AntAlgotythm, test1) {
//   s21::Graph graph;
//   s21::GraphAlgorithms test;
//   graph.LoadGraphFromFile("tests/files/digraph_6x6_AntAlg.txt");  
//   AntWay result = test.SolveTravelingSalesmanProblem(graph);
//   std::vector<size_t> way = {1, 2, 6, 3, 4, 5};
//   double length = 700;
//   // ASSERT_EQ(result.vertices, way);
//   ASSERT_EQ(result.distance, length);
// }

// TEST(AntAlgotythm, test2) {
//   s21::Graph graph;
//   s21::GraphAlgorithms test;
//   graph.LoadGraphFromFile("tests/files/digraph_16x16_AntAlg.txt");  
//   AntWay result = test.SolveTravelingSalesmanProblem(graph);
//   std::vector<size_t> way = {1, 7, 8, 9, 10, 2, 6, 3, 11, 12, 4, 13, 14, 5, 15, 16, 1};
//   double length = 1473;
  
//   ASSERT_EQ(result.distance, length);
//   ASSERT_EQ(result.vertices, way);
// }

// TEST(AntAlgotythm, test3) {
//   s21::Graph graph;
//   s21::GraphAlgorithms test;
//   graph.LoadGraphFromFile("tests/files/digraph_12x12_AntAlg.txt");  
//   AntWay result = test.SolveTravelingSalesmanProblem(graph);
//   std::vector<size_t> way = {1, 7, 8, 9, 10, 2, 6, 3, 11, 12, 4, 5, 1};
//   double length = 933;
  
//   ASSERT_EQ(result.distance, length);
//   ASSERT_EQ(result.vertices, way);
// }

TEST(AntAlgotythm, test4) {
  s21::Graph graph;
  s21::GraphAlgorithms test;
  graph.LoadGraphFromFile("tests/files/digraph_15x15_AntAlg.txt");  
  AntWay result = test.SolveTravelingSalesmanProblem(graph);
  std::vector<size_t> way = {1, 7, 8, 9, 10, 11, 2, 6, 3, 12, 15, 14, 13, 4, 5, 1};
  double length = 1073;
  
  ASSERT_EQ(result.distance, length);
  ASSERT_EQ(result.vertices, way);
}


}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
