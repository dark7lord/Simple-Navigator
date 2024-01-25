#include "../s21_graph_algorithms.h"
#include <iostream>

namespace s21 {

void GraphAlgorithms::Print(std::set<unsigned> &set) {
  for(auto it = set.begin(); it != set.end(); it++) {
    std::cout << *it << std::endl;
  }
}

std::vector<Edge> GraphAlgorithms::GetLeastSpanningTree(const Matrix& graph) {
  size_t numVertices = graph.size();
  size_t cheapestEdgeSize = numVertices - 1; 

  std::vector<size_t> cheapestCost(numVertices, std::numeric_limits<size_t>::max());
  std::vector<Edge> cheapestEdge(numVertices, Edge(-1, -1, std::numeric_limits<int>::max()));
  std::vector<bool> inTree(numVertices, false);

  size_t startVertex = 0;
  cheapestCost[startVertex] = 0;
  for (size_t i = 0; i < numVertices; ++i) {
    size_t currentVertex = numVertices;
    for (size_t v = 0; v < numVertices; ++v) {
      if (!inTree[v] && (currentVertex == numVertices || cheapestCost[v] < cheapestCost[currentVertex])) {
        currentVertex = v;
      }
    }
    inTree[currentVertex] = true;
    for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
      if (graph[currentVertex][neighbor] > 0 
          && !inTree[neighbor] 
          && graph[currentVertex][neighbor] < cheapestCost[neighbor]
      ) {
        cheapestCost[neighbor] = graph[currentVertex][neighbor];
        cheapestEdge.at(neighbor) = Edge(currentVertex, neighbor, graph[currentVertex][neighbor]);
      }
    }
  }
  std::vector<Edge> spanning_tree(cheapestEdgeSize, Edge(-1, -1, std::numeric_limits<int>::max()));
  
  int key = 0;
  for (const s21::Edge& edge : cheapestEdge) {
    if(edge.from == -1) {
      continue;
    }
    spanning_tree.at(key) = edge;
    key++;
  }

  return spanning_tree;
}

 
}
