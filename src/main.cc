#include "model/Graph/s21_graph.h"
#include  "model/GraphAlgorithms/s21_graph_algorithms.h"

int main() {
  // s21::Graph graph{};
  // //Graph &graph
  // // int start_vertex = 0;

  

  // try {
  //   // graph.LoadGraphFromFile("files/depth_first_search.txt");
  //   graph.LoadGraphFromFile("/Users/madamkyl/A2_SimpleNavigator_v1.0-1/src/files/matrix_5x5.txt");
  //   s21::GraphAlgorithms GA(graph);
  //   // graph.LoadGraphFromFile("files/graph_2x2.txt");
  //   // graph.LoadGraphFromFile("files/pentagramma.txt");
  //   // graph.ExportGraphToDot("test_example_graph");
  //   // graph.ExportGraphToConsoleOut("test_example_graph");
  //   //graph.PrintGraphInBrowser();
  //   // std::cout <<  "Is digraph? " << std::boolalpha << graph.is_digraph << std::endl;
  //   // GA.DepthFirstSearch(graph, start_vertex);
  //   GA.GetLeastSpanningTree(graph);

    
  // } catch (const s21::GraphException& e) {
  //   std::cerr << e.what() << std::endl;
  // }

  // // std::cout << "All is OK" << std::endl;
  // return (0);


  // CHATGPT VERSION TEST
  // ===========================================================
  // Example graph represented as an adjacency matrix
    s21::Graph graph;
    // graph.LoadGraphFromFile("/Users/madamkyl/A2_SimpleNavigator_v1.0-1/src/files/chatgpt_matrix.txt");
    graph.LoadGraphFromFile("/Users/madamkyl/A2_SimpleNavigator_v1.0-1/src/files/matrix_5x5.txt");

    s21::GraphAlgorithms GA(graph);

    // Run Prim's algorithm and get the minimum spanning tree
    s21::Matrix matrix = graph.GetMatrix();
    std::vector<s21::Edge> minimumSpanningTree = GA.GetLeastSpanningTree(matrix);

    // Display the minimum spanning tree
    std::cout << "Minimum Spanning Tree Edges:" << std::endl;
    for (const s21::Edge& edge : minimumSpanningTree) {
        std::cout << "Edge: " << edge.from << " - " << edge.to << "   Weight: " << edge.weight << std::endl;
    }
}
