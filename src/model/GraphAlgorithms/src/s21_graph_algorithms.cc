#include "../s21_graph_algorithms.h"

namespace s21 {

void GraphAlgorithms::DepthFirstSearch(Graph& , int) {

}

bool hasElement(std::vector<size_t> visited, size_t elem) {
  for (size_t i = 0; i < visited.size(); i++) {
    if (visited[i] == elem) return true;
  }
  return false;
}

std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph &graph, size_t start_vertex)  {
  std::vector<size_t> way;
  std::vector<size_t> visited;
  s21::queue<size_t> myQueue;
  visited.push_back(start_vertex);
  myQueue.push(start_vertex);
  while (!myQueue.empty()) {
    for (size_t i = 1; i <= graph.GetSize(); i++){
      size_t edge = graph.GetMatrix()[myQueue.front() - 1][i - 1];
      if ((edge) && (!hasElement(visited, i))) {
        myQueue.push(i);
        visited.push_back(i);
      }
    }
    way.push_back(myQueue.front());
    myQueue.pop();
  }
  return way;
}




} // namespace s21
