#include "../s21_graph_algorithms.h"

#include <iostream>

namespace s21 {

bool HasElement(std::vector<size_t> visited, size_t elem) {
  for (size_t i = 0; i < visited.size(); i++) {
    if (visited[i] == elem) return true;
  }
  return false;
}

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph& graph,
                                                      int start_vertex) {
  std::vector<size_t> visited;
  s21::stack<size_t> myStack;
  Matrix matrix = graph.GetMatrix();
  size_t size_graph = graph.GetSize();
  myStack.push(start_vertex);

  while (!myStack.empty()) {
    size_t current = myStack.top();
    myStack.pop();

    if (!HasElement(visited, current)) {
      visited.push_back(current);

      for (size_t i = size_graph; i > 0; --i) {
        bool hasPath = matrix[current - 1][i - 1] != 0;

        if (hasPath && !HasElement(visited, i)) {
          myStack.push(i);
        }
      }
    }
  }

  return visited;
}

std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph& graph,
                                                        size_t start_vertex) {
  std::vector<size_t> way;
  std::vector<size_t> visited;
  s21::queue<size_t> myQueue;
  visited.push_back(start_vertex);
  myQueue.push(start_vertex);
  while (!myQueue.empty()) {
    for (size_t i = 1; i <= graph.GetSize(); i++) {
      size_t edge = graph.GetMatrix()[myQueue.front() - 1][i - 1];
      if ((edge) && (!HasElement(visited, i))) {
        myQueue.push(i);
        visited.push_back(i);
      }
    }
    way.push_back(myQueue.front());
    myQueue.pop();
  }

  return visited;
}

}  // namespace s21
