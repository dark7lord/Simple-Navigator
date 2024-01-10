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
  
//   std::vector<size_t> contain{graph_.GetSize()}; //отслеживания посещенных вершин 
//   std::stack<size_t> myStack; 
//   std::cout << contain.size() << std::endl;
//   myStack.push(start_vertex);
//   contain[start_vertex] = start_vertex;

//   //std::cerr << "-------" << visited[1] << std::endl;

//   while (!myStack.empty()) { // Выполняется, пока стек не будет пустым
//         int current = myStack.top(); // Берем верхний элемент
//         myStack.pop(); // удаляем этот элемент
//         visited.push_back(current); //добавляем новый элемент 

//         for (size_t i = 0; i < graph_.GetSize(); i++) {
//           size_t edge = graph_.GetMatrix()[myStack.top()][i];
//             if ((edge) && (NewElement(contain, i))) {
//                 myStack.push(i);
//                 contain.push_back(i);
//             }
//         }
//     }

//   for (int i = 0; i < 5;i++) {
//     std::cerr << "-------" << visited[i] << std::endl;
//   }

//   return visited;

// }

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(int start_vertex) {
  std::vector<size_t> visited; // хранение пути
  std::vector<size_t> contain{graph_.GetSize()};// отслеживание посещенных вершин
  std::stack<size_t> myStack; 
//false - 0
  //true - 1
  myStack.push(start_vertex);
  contain[start_vertex] = start_vertex;

  while (!myStack.empty()) { // выполняется, пока стек не будет пустым
        size_t current = myStack.top(); // берем верхний элемент
        myStack.pop(); // удаляем этот элемент
        visited.push_back(current); // добавляем новый элемент 

//std::cout << "GetMatrix: " << graph_.GetSize() << std::endl;

        for (size_t i = 0; i < graph_.GetSize(); ++i) {
          size_t edge = graph_.GetMatrix()[current][i];
          std::cout << "GetMatrix: " << graph_.GetMatrix()[current][i] << std::endl;
          if (edge && contain[i] != current) { // проверяем смежность и отсутствие посещения
            myStack.push(i);
            contain[i] = start_vertex;
          }
        }
    }

  for (int i = 0; i < 5;i++) {
    std::cout << "Посещена вершина: " << visited[i] << std::endl;
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
