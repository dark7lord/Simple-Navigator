#ifndef CLI_H
#define CLI_H

#include "map"

#include "../../model/Graph/s21_graph.h"
#include "../../model/GraphAlgorithms/s21_graph_algorithms.h"

namespace s21 {

class CLI {

public:
  static CLI& getInstance() {
    static CLI instance;
    return instance;
  }

  Graph& getGraph() { return graph_; }

  void start() {
    while (current_state_ != State::Exit) {
      displayMenu();
      processInput();
    }
  }

private:
  enum class State {
    EmptyGraph,
    LoadedGraph,
    Exit
  };

  void UploadGraph() {
    std::cout << "Enter file name: ";
    std::string file_name;

    if (!(std::cin >> file_name)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        return;
      }
      if (file_name.empty()) {
        std::cerr << "Error: empty string entered" << std::endl;
      }
    }

    try {
      graph_.LoadGraphFromFile(file_name);
      this->current_state_ = State::LoadedGraph;
      std::cout << "Graph " << file_name <<  " is loaded!" << std::endl;
    } catch (const s21::GraphException& e) {
      std::cout << e.what() << std::endl;
    }
  }

  void Export() {
    std::cout << "Enter file name: " ;
    std::string file_name;

    if (!(std::cin >> file_name)) {
      std::cin.clear();  // Очистить флаг ошибки
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очистить буфер
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        return;
      }
      if (file_name.empty()) {
        std::cerr << "Error: empty string entered" << std::endl;
      }
    }

    try {
      graph_.ExportGraphToDot(file_name);
      std::cout << "Graph " << file_name <<  " is exported!" << std::endl;
    } catch (const s21::GraphException& e) {
      std::cout << e.what() << std::endl;
    }
  };

  void BFS() {
    GraphAlgorithms alg;

    std::cout << "Enter starting vertex (BFS): ";
    int start_vertex;
    if (!(std::cin >> start_vertex)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        return;
      }
      std::cerr << "Invalid input. Please enter a number." << std::endl;
      return;
    }

    if (start_vertex <= 0 || start_vertex > (int) graph_.GetSize()) {
      std::cerr << "Vertex selection error." << std::endl;
      return;
    }

    auto path = alg.BreadthFirstSearch(graph_, start_vertex);

    std::cout << "Path: ";
    for (auto& elem : path) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }

  void DFS() {
    GraphAlgorithms alg;

    std::cerr << "Enter starting vertex (DFS): ";
    int start_vertex;
    if (!(std::cin >> start_vertex)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        return;
      }
      std::cerr << "Invalid input. Please enter a number." << std::endl;
      return;
    }

    if (start_vertex <= 0 || start_vertex > (int) graph_.GetSize()) {
      std::cerr << "Vertex selection error." << std::endl;
      return;
    }

    auto path = alg.DepthFirstSearch(graph_, start_vertex);

    std::cout << "Path: ";
    for (auto& elem : path) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }

  void GetShortestPathBetweenVertices() {
    GraphAlgorithms alg;

    std::cout << "Enter start and finish vertices (Dijkstra): ";
    int start_vertex;
    int finish_vertex;
    // TODO: работает не так, как нужно если ввести типа "1 3 4" и 4 уходит в горизонт другой логики
    if (!(std::cin >> start_vertex >> finish_vertex)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        return;
      }
      std::cerr << "Invalid input. Please enter a number." << std::endl;
      return;
    }

    if (start_vertex <= 0 || finish_vertex <= 0 ||
      start_vertex > (int) graph_.GetSize() ||
      finish_vertex > (int) graph_.GetSize()) {
      std::cerr << "Vertex selection error." << std::endl;
      return;
    }

    auto result = alg.GetShortestPathBetweenVertices(graph_, start_vertex, finish_vertex);
    std::cout << "The shortest path between point "
      << start_vertex << " and "<< finish_vertex<< " is "
      << result << std::endl;
  }

  void GetShortestPathsBetweenAllVertices() {
    GraphAlgorithms alg;

    Matrix matrix = alg.GetShortestPathsBetweenAllVertices(graph_);
    std::cout << "\nMatrix of shortest paths between all vertices of the graph:\n" << std::endl;
    PrintMatrix(matrix);
  }

  // TODO: нужно дописать
  // нужно возвращать матрицу
  void GetLeastSpanningTree() {
    GraphAlgorithms alg;
    std::cout << ">_<"<< std::endl;

    Matrix matrix = alg.GetLeastSpanningTree(graph_);
    std::cout << "\nMatrix of least spanning tree of the graph:\n" << std::endl;
    PrintMatrix(matrix);
  }

  // TODO: Нужно убрать отладочную консольную печать
  void SolveTravelingSalesmanProblem() {
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

  void displayMenu() {
    // int i = 0;
    std::cout << std::endl;
    std::cout << "Select a command to execute: " << std::endl;
    switch (current_state_) {
      case State::EmptyGraph:
        displayOptions(emptyGraphOptions_);
        break;
      case State::LoadedGraph:
        displayOptions(loadedGraphOptions_);
        break;
      default:
        break;
    }

    std::cout << std::endl << "Enter your choice: ";
  }

  void processInput() {
    int choice;
    if (!(std::cin >> choice)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        return;
      }
      std::cerr << "Invalid input. Please enter a number." << std::endl;
      return;
    }

    std::vector<std::pair<std::string, std::function<void()>>> options;
    switch (current_state_) {
      case State::EmptyGraph:
        options = emptyGraphOptions_;
        break;
      case State::LoadedGraph:
        options = loadedGraphOptions_;
        break;
      default:
        break;
    }

    if (choice >= 1 && static_cast<size_t>(choice) <= options.size()) {
      options[choice - 1].second();
    } else {
      std::cout << "Invalid choice. Please try again.\n";
    }
  }

  void ProcessEmptyGraphState(int choice) {
    switch (choice) {
      case 1:
        std::cout << "Graph loaded!\n";
        current_state_ = State::LoadedGraph;
        break;
      case 2:
        std::cout << "Exiting...\n";
        current_state_ = State::Exit;
        break;
      default:
        std::cout << "Invalid choice. Try again.\n";
        break;
    }
  }

  void processLoadedGraphState(int choice) {
    switch (choice) {
      case 1:
        std::cout << "Graph unloaded.\n";
        current_state_ = State::EmptyGraph;
        break;
      case 2:
        std::cout << "Exiting...\n";
        current_state_ = State::Exit;
        break;
      default:
        std::cout << "Invalid choice. Try again.\n";
        break;
    }
  }

private:
  State current_state_;

  void displayOptions(const std::vector<std::pair<std::string, std::function<void()>>>& options) {
    int i = 0;
    for (const auto& option : options) {
      std::cout << ++i << ". " << option.first << std::endl;
    }
  }

  std::vector<std::pair<std::string, std::function<void()>>> emptyGraphOptions_{
    { "Load Graph", [this]() { UploadGraph(); } },
    { "Exit", [this]() { current_state_ = (State::Exit); } }
  };

  std::vector<std::pair<std::string, std::function<void()>>> loadedGraphOptions_{
    { "Load Graph", [this]() { UploadGraph(); } },
    { "Export", [this]() { Export(); } },
    { "Breadth First Search", [this]() { BFS(); } },
    { "Deep First Search", [this]() { DFS(); } },
    { "Get shortest path between vertices", [this]() {
      GetShortestPathBetweenVertices();
    }},
    { "Get shortest paths between all vertices", [this]() {
      GetShortestPathsBetweenAllVertices();
    }},
    { "Get least spanning tree", [this]() {
      GetLeastSpanningTree();
    }},
    { "Solve traveling salesman problem", [this]() {
      SolveTravelingSalesmanProblem();
    }},
    { "Print (adjacency matrix)", [this]() { graph_.PrintGraph(); } },
    { "Print in browser (graph)", [this]() {
      graph_.PrintGraphInBrowser();
    }},
    { "Exit", [this]() { current_state_ = (State::Exit); } }
  };

private:
  CLI() {
    current_state_ = State::EmptyGraph;
  };
  ~CLI() {
    current_state_ = State::EmptyGraph;
  };

  CLI(const CLI&) = delete;
  CLI& operator=(const CLI&) = delete;

  Graph graph_;
  CLI* CLI_instance_;
};

}

#endif // CLI_H
