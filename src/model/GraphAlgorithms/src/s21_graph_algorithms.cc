#include "../s21_graph_algorithms.h"

namespace s21 {


bool NewElement(std::vector<size_t> contain, size_t elem) {
  for (size_t i = 0; i < contain.size(); i++) {
    if (contain[i] == elem) return false;
  }
  return true;
}

// std::vector<size_t> GraphAlgorithms::DepthFirstSearch(int start_vertex) {
//   std::vector<size_t> visited; //хранения пути
//   //std::vector<size_t> contain(graph_.GetSize()); // отслеживания посещенных вершин 
//   std::stack<size_t> myStack;
  
//   myStack.push(start_vertex);
//   //visited.push_back(start_vertex);
//   std::cerr << "myStack: " << start_vertex << std::endl;
//   //contain[start_vertex] = start_vertex;

//   while (!myStack.empty()) { // Выполняется, пока стек не будет пустым
//     size_t current = myStack.top(); // Берем верхний элемент
//     myStack.pop(); // удаляем этот элемент
//     visited.push_back(current); //добавляем новый элемент 
//     std::cerr << "visited: " << current << std::endl;

//     for (size_t i = 1; i < graph_.GetSize(); i++) {
//       size_t edge = graph_.GetMatrix()[current][i]; 
//       std::cerr << "myStack: " << i << std::endl;
//       if (edge && NewElement(visited, i)) {
//         myStack.push(i);
//         std::cerr << "myStack: " << i << std::endl;
//         visited[i] = i; 
//       }
//     }
//   }
//   // for (size_t i = 0; i < visited.size(); i++) {
//   //   std::cout << "Посещена вершина: " << visited[i] << std::endl;
//   // }
//   return visited;
// }

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(int start_vertex) {
  std::vector<size_t> visited;  // хранение пути
  std::vector<bool> contain(graph_.GetSize(), false);  // отслеживание посещенных вершин
  std::stack<size_t> myStack; 
  
  myStack.push(start_vertex-1);
  contain[start_vertex-1] = true;

std::cout << "myStack: " << start_vertex << std::endl;

  while (!myStack.empty()) {  // выполняется, пока стек не будет пустым
    size_t current = myStack.top();  // берем верхний элемент
    myStack.pop();  // удаляем этот элемент
    visited.push_back(current);  // добавляем новый элемент 

std::cout << "visited: " << current + 1 << std::endl;

    for (size_t i = 0; i < graph_.GetSize(); ++i) {
      std::cout << "i: " << i << " GetMatrix: " << graph_.GetMatrix()[current][i] << " " << current << " contain: " << contain[i] << std::endl;
      if (graph_.GetMatrix()[current][i] == 1 && contain[i] != 1) { // проверяем смежность и отсутствие посещения
        myStack.push(i);
        std::cout << "myStack: " << i + 1 << std::endl;
        contain[i] = true;
      }
    }
  }

  for (size_t i = 0; i < visited.size(); i++) {
    std::cout << "Посещена вершина: " << visited[i] + 1 << std::endl;
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
