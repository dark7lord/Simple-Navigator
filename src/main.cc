#include "model/Graph/s21_graph.h"
#include "model/GraphAlgorithms/s21_graph_algorithms.h"

int main() {
  s21::Graph graph;

  try {
    graph.LoadGraphFromFile("files/digraph_5x5.txt");
    graph.ExportGraphToDot("test_example_graph");
    // graph.PrintGraphInBrowser();
    graph.PrintGraph();

    s21::GraphAlgorithms algs;
    s21::Matrix paths = algs.GetShortestPathsBetweenAllVertices(graph);

    s21::Matrix adjacency_matrix = graph.GetMatrix();
    s21::Matrix distance_matrix = paths;

    s21::PrintMatrix(distance_matrix);
    //  s21::PrintPaths(adjacency_matrix, distance_matrix);
    // s21::Matrix paths = algs.BreadthFirstSearch(graph);
    // std::cout << (paths);

  } catch (const s21::GraphException& e) {
    std::cerr << e.what() << std::endl;
  }

  return (0);
}

