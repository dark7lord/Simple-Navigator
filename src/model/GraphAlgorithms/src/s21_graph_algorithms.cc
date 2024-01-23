#include "../s21_graph_algorithms.h"
#include <iostream>

namespace s21 {

void GraphAlgorithms::Print(std::set<unsigned> &set) {
  for(auto it = set.begin(); it != set.end(); it++) {
    std::cout << *it << std::endl;
  }
}


// TEST CHATGPT
// =================================================================================================
std::vector<Edge> GraphAlgorithms::GetLeastSpanningTree(const Matrix& graph) {
  size_t numVertices = graph.size();
  size_t cheapestEdgeSize = numVertices - 1;  // Corrected size
  // Initialize data structures
  std::vector<size_t> cheapestCost(numVertices, std::numeric_limits<size_t>::max());
  std::vector<Edge> cheapestEdge(numVertices, Edge(-1, -1, std::numeric_limits<int>::max()));
  std::vector<bool> inTree(numVertices, false);
  // Initialize the starting vertex
  size_t startVertex = 0;  // You can choose any starting vertex arbitrarily
  cheapestCost[startVertex] = 0;
  // Main loop of Prim's algorithm
  for (size_t i = 0; i < numVertices; ++i) {
    // Find the vertex with the minimum cost that is not yet in the tree
    size_t currentVertex = numVertices;  // Initialize to an invalid value
    for (size_t v = 0; v < numVertices; ++v) {
      if (!inTree[v] && (currentVertex == numVertices || cheapestCost[v] < cheapestCost[currentVertex])) {
        currentVertex = v;
      }
    }
    // Add the current vertex to the tree
    inTree[currentVertex] = true;
    // Update cost and edge information for adjacent vertices
    for (size_t neighbor = 0; neighbor < numVertices; ++neighbor) {
      if (graph[currentVertex][neighbor] > 0 
          && !inTree[neighbor] 
          && graph[currentVertex][neighbor] < cheapestCost[neighbor]
      ) {
        cheapestCost[neighbor] = graph[currentVertex][neighbor];
        cheapestEdge.at(neighbor) = Edge(currentVertex, neighbor, graph[currentVertex][neighbor]);  // Corrected index
      }
    }
  }
  std::vector<Edge> spanning_tree(cheapestEdgeSize, Edge(-1, -1, std::numeric_limits<int>::max()));
  
  // КОСТЫЛЬ: удаление лишнего элемента в начале вектора
  int key = 0;
  for (const s21::Edge& edge : cheapestEdge) {
    if(edge.from == -1) {
      continue;
    }
    spanning_tree.at(key) = edge;
    key++;
  }

  // Return the resulting minimum spanning tree
  return spanning_tree;
}


// CURRENT VERSION
// =================================================================================================
// void GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {
//     // Создаем два множества, для посещенных и не посещенных вершин 
//     // (пометим, соответственно, как visited и unvisited)
//     std::set<unsigned> visited;
//     std::set<unsigned> unvisited;

//     // Создаем исходную матрицу, которая будет представлять собой остовное дерево 
//     // (пометим как spanning_tree)
//     Matrix spanning_tree(std::vector<int> number_of_vertices, std::vector<int> number_of_vertic);

//     // Создаем массив ребер (пометим как tree_edges), 
//     // ребро в данном случае это структура, 
//     // которая хранит две вершины и вес самого ребра.
//     std::vector<Edge> tree_edges;

//     // Инициализируем множество непосещенных вершин всеми, существующими в графе вершинами
//     for (size_t i = 0; i < graph.GetMatrix().size(); i++) {
//         unvisited.insert(i);
//     }

//     // Print(unvisited);
    
//     // Выбираем, случайным образом
//     unsigned vertex = 0;

//     // Помечаем эту вершину как посещенной
//     visited.insert(vertex);
//     // убираем ее из множества непосещенных 
//     unvisited.erase(vertex);
    
//     // std::cout << "visited: " << std::endl;
//     // Print(visited);
//     // std::cout << "unvisited: " << std::endl;
//     // Print(unvisited);
    
//     while (!unvisited.empty()) {

//     }
    

    // // Пока множество непосещенных вершин не пусто:
    // while unvisited is not empty:
    //     // Создаем ребро инициализируя его поля бесконечностями
    //     min_edge = {from: None, to: None, weight: infinity}

    //     // Перебираем все посещенные вершины (пометим как from):
    //     for from_vertex in visited:
    //         // Перебираем все вершины графа (пометим как to):
    //         for to_vertex in all_vertices:
    //             // Если to является непосещенной вершиной и ребро между вершинами {from, to} существует и вес ребра (созданного в пункте 5.1) больше чем вес ребра между вершинами {from, to}, то:
    //             if to_vertex in unvisited and graph_has_edge(from_vertex, to_vertex):
    //                 edge_weight = get_edge_weight(from_vertex, to_vertex)
    //                 if edge_weight < min_edge.weight:
    //                     // Обновляем ребро (5.1) вершинами from и to и весом между этими вершинами
    //                     min_edge.from = from_vertex
    //                     min_edge.to = to_vertex
    //                     min_edge.weight = edge_weight

    //     // Если вес ребра не равен бесконечности:
    //     if min_edge.weight < infinity:
    //         // Добавляем в массив tree_edges новое ребро
    //         tree_edges.append(min_edge)
    //         // Удаляем из множества непосещенных вершин вершину to
    //         unvisited.remove(min_edge.to)
    //         // Добавляем в множество посещенных вершин вершину to
    //         visited.add(min_edge.to)
    //     else:
    //         // Иначе прекращаем цикл
    //         break

    // // Пробегаясь по всем ребрам массива tree_edges:
    // for edge in tree_edges:
    //     // Инициализируем spanning_tree, добавляя в нее ребра (добавлять нужно в обе стороны, чтобы граф получился неориентированным)
    //     spanning_tree.append(edge)
// }



// bool NewElement(const std::vector<size_t>& contain, size_t elem) {
//   for (size_t i = 0; i < contain.size(); i++) {
//     if (contain[i] == elem) return false;
//   }
//   return true;
// }


// std::vector<size_t> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex)  {
//   std::vector<size_t> way;
//   std::vector<size_t> contain;
//   s21::stack<size_t> myStack;
//   contain.push_back(start_vertex);
//   myStack.push(start_vertex);
//   std::cout << "contain: " << start_vertex +1  << std::endl;
//   std::cout << "myStack: " << start_vertex +1  << std::endl;
//   while (!myStack.empty()) {
//     size_t current = myStack.top();
//     myStack.pop();
//     way.push_back(current);
//     std::cout << "way: " << current +1  << std::endl;
//     //std::cout << "for 1: " << graph.GetSize()<< std::endl;
//     for (int i = 0; i <  graph.GetSize(); ++i) {
//       //std::cout << "for 2: " << std::endl;
//       size_t edge = graph.GetMatrix()[current][i];
//       if (edge && NewElement(contain, i)) {
//         myStack.push(i);
//         contain.push_back(i);
//         std::cout << "myStack: " << i +1  << std::endl;
//         std::cout << "contain: " << i +1  << std::endl;
//       }
      
//     }
//     //std::cout << "for 3: " << graph.GetSize()<< std::endl;
//   }

//   for (size_t i = 0; i < way.size(); i++) {
//      std::cout << "Посещена вершина: " << way[i] +1  << std::endl;
//   }

//   return way;
// }

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

// std::vector<size_t> GraphAlgorithms::BreadthFirstSearch(Graph &graph, int start_vertex)  {
//   std::vector<size_t> way;
//   std::vector<size_t> contain;
//   s21::queue<size_t> myQueue;
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
