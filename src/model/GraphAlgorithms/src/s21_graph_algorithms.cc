#include "../s21_graph_algorithms.h"

namespace s21 {

int sum (int a, int b) {
  return a + b;
}


bool NewElement(std::vector<size_t> contain, size_t elem) {
  for (size_t i = 0; i < contain.size(); i++) {
    if (contain[i] == elem) return false;
  }
  return true;
}

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex) {
  std::vector<size_t> visited; //хранения пути 
  std::vector<size_t> contain; //отслеживания посещенных вершин 
  std::stack<size_t> myStack; 

  myStack.push(start_vertex);
  contain[start_vertex] = true;

  while (!myStack.empty()) { // Выполняется, пока стек не будет пустым
        int current = myStack.top(); // Берем верхний элемент
        myStack.pop(); // удаляем этот элемент
        visited.push_back(current); //добавляем новый элемент 

        for (size_t i = 0; i < graph.GetSize(); i++) {
          size_t edge = graph.GetMatrix()[myStack.top()][i];
            if ((edge) && (NewElement(contain, i))) {
                myStack.push(i);
                contain.push_back(i);
            }
        }
    }

  return visited;

}

// std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph &graph, int start_vertex)  {
//   std::vector<size_t> way;
//   std::vector<size_t> contain;
//   std::queue<size_t> myQueue;
//   contain.push_back(start_vertex);
//   myQueue.push(start_vertex);
//   while (!myQueue.empty()) {
//     for (size_t i = 0; i < graph.GetSize(); ++i){
//        size_t edge = graph.GetMatrix()[myQueue.front()][i];
//        if ((edge) && (NewElement(contain, i))) {
//          myQueue.push(i);
//          contain.push_back(i);
//        }
//     }
//     way.push_back(myQueue.front());
//     myQueue.pop();

//   }
//   return way;
// }

 
}
