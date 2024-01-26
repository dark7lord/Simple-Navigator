#include "model/Graph/s21_graph.h"
#include "model/GraphAlgorithms/s21_graph_algorithms.h"
#include "view/CLI/CLI.h"



int main() {
   s21::Graph CLI;
   s21::CLI& cli = s21::CLI::getInstance();
   cli.start();

   // Example graph represented as an adjacency matrix
   //  s21::Graph graph;
    // graph.LoadGraphFromFile("/Users/madamkyl/A2_SimpleNavigator_v1.0-1/src/files/chatgpt_matrix.txt");
   //  graph.LoadGraphFromFile("/Users/madamkyl/A2_SimpleNavigator_v1.0-1/src/files/matrix_5x5.txt");

    //s21::GraphAlgorithms GA(graph);
   //  s21::GraphAlgorithms GA;

    // Run Prim's algorithm and get the minimum spanning tree
   //  s21::Matrix matrix = graph.GetMatrix();

     // Run Prim's algorithm and get the minimum spanning tree
   //  s21::Matrix minimumSpanningTree = GA.GetLeastSpanningTree(graph);

    // Display the minimum spanning tree
   //  std::cout << "Minimum Spanning Tree Edges:" << std::endl;
   //  for (const s21::Edge& edge : minimumSpanningTree) {
   //      std::cout << "Edge: " << edge.from << " - " << edge.to << "   Weight: " << edge.weight << std::endl;
   //  }
    //PrintMatrix(minimumSpanningTree);
   //  std::cout << "Minimum Spanning Tree Edges:" << std::endl;
   //  for (const s21::Edge& edge : minimumSpanningTree) {
   //      std::cout << "Edge: " << edge.from << " - " << edge.to << "   Weight: " << edge.weight << std::endl;
   //  }


}
