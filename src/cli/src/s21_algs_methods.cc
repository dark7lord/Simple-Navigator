#include "../s21_cli.h"

namespace s21 {

void CLI::BFS() {
  GraphAlgorithms alg;
  std::string prompt = "Enter starting vertex (BFS): ";
  std::string error_message = "Vertex selection error.";
  int min_value = 1;
  int max_value = graph_.GetSize();
  int start_vertex;

  try {
    start_vertex = InputValue(prompt, error_message, min_value, max_value);
  } catch (char const* e) {
    std::cerr << e << std::endl;
    return;
  }

  auto path = alg.BreadthFirstSearch(graph_, start_vertex);

  std::cout << "Path: ";
  for (const auto& elem : path) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void CLI::DFS() {
  GraphAlgorithms alg;
  std::string prompt = "Enter starting vertex (DFS): ";
  std::string error_message = "Vertex selection error.";
  int min_value = 1;
  int max_value = graph_.GetSize();
  int start_vertex;

  try {
    start_vertex = InputValue(prompt, error_message, min_value, max_value);
  } catch (char const* e) {
    std::cerr << e << std::endl;
    return;
  }

  auto path = alg.DepthFirstSearch(graph_, start_vertex);

  std::cout << "Path: ";
  for (auto& elem : path) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

void CLI::GetShortestPathBetweenVertices() {
  GraphAlgorithms alg;
  std::string prompt_start = "Enter starting vertex: ";
  std::string prompt_finish = "Enter finish vertex: ";
  std::string error_message = "Vertex selection error.";
  int min_value = 1;
  int max_value = graph_.GetSize();

  std::cout << "Enter start and finish vertices (Dijkstra)" << std::endl;

  int start_vertex;
  int finish_vertex;

  try {
    start_vertex =
        InputValue(prompt_start, error_message, min_value, max_value);
    finish_vertex =
        InputValue(prompt_finish, error_message, min_value, max_value);
  } catch (char const* e) {
    std::cerr << e << std::endl;
    return;
  }

  auto result =
      alg.GetShortestPathBetweenVertices(graph_, start_vertex, finish_vertex);

  std::cout << "The shortest path between point " << start_vertex << " and "
            << finish_vertex << " is " << result << std::endl;
}

void CLI::GetShortestPathsBetweenAllVertices() {
  GraphAlgorithms alg;

  Matrix matrix = alg.GetShortestPathsBetweenAllVertices(graph_);
  std::cout << "\nMatrix of shortest paths between all vertices of the graph:\n"
            << std::endl;
  PrintMatrix(matrix);
  // std::cout << matrix;
}

void CLI::GetLeastSpanningTree() {
  GraphAlgorithms alg;
  std::cout << ">_<" << std::endl;

  Matrix matrix = alg.GetLeastSpanningTree(graph_);
  std::cout << "\nMatrix of least spanning tree of the graph:\n" << std::endl;
  PrintMatrix(matrix);
}

void CLI::SolveTravelingSalesmanProblem() {
  GraphAlgorithms alg;

  // try {
  AntWay ant_way = alg.SolveTravelingSalesmanProblem(graph_);
  std::vector<size_t> vertices = ant_way.vertices;
  double distance = ant_way.distance;

  // TODO: Is it OK?
  if (vertices.size() == 0) {
    std::cerr << "There is no way" << std::endl;
    return;
  }

  std::cout << "Path: ";
  for (auto& vertex : vertices) {
    std::cout << vertex << " ";
  }
  std::cout << std::endl;
  std::cout << "Distance: " << distance << std::endl;

  // } catch (const s21::GraphException& e) {
  //   std::cout << e.what() << std::endl;
  // }
}

}  // namespace s21
