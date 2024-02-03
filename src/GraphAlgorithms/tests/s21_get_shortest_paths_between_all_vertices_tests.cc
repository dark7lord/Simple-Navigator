#include <gtest/gtest.h>

#include "s21_graph_algorithms.h"

const std::size_t infinity = -1;

TEST(ShortPathsAllVertices, Test2x2) {
  s21::Graph graph;

  graph.LoadGraphFromFile("tests/files/graph_2x2.txt");

  s21::GraphAlgorithms algorithm;
  s21::Matrix distanceMatrix =
      algorithm.GetShortestPathsBetweenAllVertices(graph);

  s21::Matrix expected = {{1, 2}, {2, 1}};

  ASSERT_EQ(distanceMatrix, expected);
}

TEST(ShortPathsAllVertices, Test3x3) {
  s21::Graph graph;
  graph.LoadGraphFromFile("tests/files/digraph_3x3.txt");

  s21::GraphAlgorithms algorithm;
  s21::Matrix distanceMatrix =
      algorithm.GetShortestPathsBetweenAllVertices(graph);

  s21::Matrix expected = {
      {1, 2, infinity}, {infinity, 1, infinity}, {infinity, infinity, 1}};

  ASSERT_EQ(distanceMatrix, expected);
}

TEST(ShortPathsAllVertices, Test5x5WithLoops) {
  s21::Graph graph;
  graph.LoadGraphFromFile("tests/files/digraph_5x5_with_loops.txt");

  s21::GraphAlgorithms algorithm;
  s21::Matrix distanceMatrix =
      algorithm.GetShortestPathsBetweenAllVertices(graph);

  s21::Matrix expected = {{1, 3, 2, 1, 2},
                          {1, 0, 2, 1, 2},
                          {2, 1, 3, 2, 3},
                          {1, 2, 1, 2, 1},
                          {infinity, infinity, infinity, infinity, 0}};

  ASSERT_EQ(distanceMatrix, expected);
}
