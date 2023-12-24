#include "model/Graph/s21_graph.h"
//"model/GraphAlgorithms/s21_graph_algorithms.h"

int main() {
  s21::Graph graph;

  try {
    graph.LoadGraphFromFile("files/depth_first_search.txt");
    graph.PrintGraph();
  } catch (const s21::GraphException& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "All is OK" << std::endl;
  return (0);
}

