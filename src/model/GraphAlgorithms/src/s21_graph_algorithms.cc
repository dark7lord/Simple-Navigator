#include "../s21_graph_algorithms.h"

namespace s21 {

int sum (int a, int b) {
  return a + b;
}

// void GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex)  {

// }
bool NewElement(std::vector<int> contain, int elem) {
  for (size_t i = 0; i < contain.size(); i++) {
    if (contain[i] == elem) return false;
  }
  return true;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph, int start_vertex)  {
  std::vector<int> way;
  std::vector<int> contain;
  std::queue<int> myQueue;
  contain.push_back(start_vertex);
  myQueue.push(start_vertex);
  while (!myQueue.empty()) {
    for (size_t i = 1; i <= graph.GetSize(); i++){
       size_t edge = graph.GetMatrix()[myQueue.front()-1][i-1];
       if ((edge) && (NewElement(contain, i))) {
         myQueue.push(i);
         contain.push_back(i);
       }
    }
    way.push_back(myQueue.front());
    myQueue.pop();
  }
  return way;
}
}
