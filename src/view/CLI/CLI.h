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

    std::cerr << "Enter starting vertex (BFS): ";
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

  // TODO: нужно дописать
  // ну допустим там вектор вершин
  void GetShortestPathBetweenVertices() {
    std::cout << "\nThere will soon be an implementation of Dijkstra's method\n" << std::endl;
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

    Matrix matrix = alg.GetShortestPathsBetweenAllVertices(graph_);
    std::cout << "\nMatrix of shortest paths between all vertices of the graph:\n" << std::endl;
    PrintMatrix(matrix);
  }

  void SolveTravelingSalesmanProblem() {

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
    { "Print", [this]() { graph_.PrintGraph(); } },
    { "Print in browser", [this]() { graph_.PrintGraphInBrowser(); } },
    { "Breadth First Search", [this]() { BFS(); } },
    { "Deep First Search", [this]() { DFS(); } },
    { "Get shortest paths between all vertices", [this]() {
      GetShortestPathsBetweenAllVertices();
    }},
    { "Ant", [this]() {
      // AntMthod();
    }},
    { "Exit", [this]() { current_state_ = (State::Exit); } }
  };

private:
  CLI() {
    // std::cout << "Console Line Interface created" << std::endl;
    current_state_ = State::EmptyGraph;
  };
  ~CLI() {
    // std::cout << "Console Line Interface destroyed" << std::endl;
    current_state_ = State::EmptyGraph;
  };

  CLI(const CLI&) = delete;
  CLI& operator=(const CLI&) = delete;

  Graph graph_;
  CLI* CLI_instance_;
};

}

#endif // CLI_H
