#include "Graph/s21_graph.h"
#include "GraphAlgorithms/s21_graph_algorithms.h"
#include "cli/s21_cli.h"

int main() {
  s21::Graph CLI;
  s21::CLI& cli = s21::CLI::getInstance();
  cli.start();
}
