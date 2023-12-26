#include "../s21_graph_algorithms.h"

namespace s21 {

int sum (int a, int b) {
  return a + b;
}

// void GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex)  {

// }
bool NewElement(std::vector<size_t> contain, size_t elem) {
  for (size_t i = 0; i < contain.size(); i++) {
    if (contain[i] == elem) return false;
  }
  return true;
}

std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph &graph, int start_vertex)  {
  std::vector<size_t> way;
  std::vector<size_t> contain;
  std::queue<size_t> myQueue;
  contain.push_back(start_vertex);
  myQueue.push(start_vertex);
  while (!myQueue.empty()) {
    for (size_t i = 0; i < graph.GetSize(); ++i){
       size_t edge = graph.GetMatrix()[myQueue.front()][i];
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
