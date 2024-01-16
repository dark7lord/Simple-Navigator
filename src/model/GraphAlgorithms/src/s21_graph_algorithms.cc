#include "../s21_graph_algorithms.h"

namespace s21 {


bool NewElement(const std::vector<size_t>& contain, size_t elem) {
  for (size_t i = 0; i < contain.size(); i++) {
    if (contain[i] == elem) return false;
  }
  return true;
}

std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex)  {
  std::vector<size_t> way;
  std::vector<size_t> contain;
  s21::stack<size_t> myStack;
  contain.push_back(start_vertex);
  myStack.push(start_vertex);
  std::cout << "contain: " << start_vertex +1  << std::endl;
  std::cout << "myStack: " << start_vertex +1  << std::endl;
  while (!myStack.empty()) {
    size_t current = myStack.top();
    myStack.pop();
    way.push_back(current);
    std::cout << "way: " << current +1  << std::endl;
    //std::cout << "for 1: " << graph.GetSize()<< std::endl;
    for (int i = 0; i <  graph.GetSize(); ++i) {
      //std::cout << "for 2: " << std::endl;
      size_t edge = graph.GetMatrix()[current][i];
      if (edge && NewElement(contain, i)) {
        myStack.push(i);
        contain.push_back(i);
        std::cout << "myStack: " << i +1  << std::endl;
        std::cout << "contain: " << i +1  << std::endl;
      }
      
    }
    //std::cout << "for 3: " << graph.GetSize()<< std::endl;
  }

  for (size_t i = 0; i < way.size(); i++) {
     std::cout << "Посещена вершина: " << way[i] +1  << std::endl;
  }

  return way;
}

// std::vector<size_t> GraphAlgorithms::DepthFirstSearch(int start_vertex) {
//   std::vector<size_t> visited;  // хранение пути
//   std::vector<bool> contain(graph_.GetSize(), false);  // отслеживание посещенных вершин
//   std::stack<size_t> myStack; 
  
//   myStack.push(start_vertex);
//   contain[start_vertex] = true;

//   while (!myStack.empty()) {  // выполняется, пока стек не будет пустым
//     size_t current = myStack.top();  // берем верхний элемент
//     myStack.pop();  // удаляем этот элемент
//     visited.push_back(current);  // добавляем новый элемент 

//     for (size_t i = 0; i < graph_.GetSize(); ++i) {
//       if (graph_.GetMatrix()[current][i] && !contain[i]) { // проверяем смежность и отсутствие посещения
//         myStack.push(i);
//         contain[i] = true;
//       }
//     }
//   }

//   for (size_t i = 0; i < visited.size(); i++) {
//     std::cout << "Посещена вершина: " << visited[i] << std::endl;
//   }

//   return visited;
// }

// std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex) {
//   std::vector<size_t> way;
//   std::vector<size_t> contain;
//   std::stack<size_t> myQueue;
//   contain.push_back(start_vertex);
//   myQueue.push(start_vertex);
//   while (!myQueue.empty()) {
//     for (size_t i = 0; i < graph.GetSize(); ++i){
//        size_t edge = graph.GetMatrix()[myQueue.top()][i];
//        if ((edge) && (NewElement(contain, i))) {
//          myQueue.push(i);
//          contain.push_back(i);
//        }
//     }
//     way.push_back(myQueue.top());
//     myQueue.pop();

//   }
// //std::cout << "Посещена вершина: " << way.size() << std::endl;
//   for (size_t i = 0; i < way.size(); i++) {
//      std::cout << "Посещена вершина: " << way[i] + 1 << std::endl;
//   }

//   return way;
// }

std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph &graph, int start_vertex)  {
  std::vector<size_t> way;
  std::vector<size_t> contain;
  s21::queue<size_t> myQueue;
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
