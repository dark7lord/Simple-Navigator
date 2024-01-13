#include "model/Graph/s21_graph.h"
#include  "model/GraphAlgorithms/s21_graph_algorithms.h"

int main() {
  s21::Graph graph{};
  //Graph &graph
  int start_vertex = 2;

  

  try {
    // graph.LoadGraphFromFile("files/depth_first_search.txt");
    graph.LoadGraphFromFile("/Users/madamkyl/A2_SimpleNavigator_v1.0-1/src/files/digraph_4x4.txt");
    s21::GraphAlgorithms GA(graph);
    // graph.LoadGraphFromFile("files/graph_2x2.txt");
    // graph.LoadGraphFromFile("files/pentagramma.txt");
    // graph.ExportGraphToDot("test_example_graph");
    // graph.ExportGraphToConsoleOut("test_example_graph");
    //graph.PrintGraphInBrowser();
    // std::cout <<  "Is digraph? " << std::boolalpha << graph.is_digraph << std::endl;
    GA.DepthFirstSearch(start_vertex);
    
  } catch (const s21::GraphException& e) {
    std::cerr << e.what() << std::endl;
  }

  // std::cout << "All is OK" << std::endl;
  return (0);
}
