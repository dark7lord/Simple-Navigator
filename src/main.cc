#include "model/Graph/s21_graph.h"

int main() {
  s21::Graph graph;

  try {
    graph.LoadGraphFromFile("files/matrix_5x5.txt");
    graph.PrintGraph();
  } catch (const s21::GraphException& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "All is OK" << std::endl;
  return (0);
}
