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

  std::string inputFileName() {
    std::string file_name;
    while (true) {
      std::cout << "Enter file name: ";
      if (!(std::cin >> file_name)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.eof()) {
          current_state_ = State::Exit;
          std::cerr << "Ctrl+D (Exit)" << std::endl;
          // break;
          throw "Exit. Bye!";
          // throw std::runtime_error("Ctrl+D (Exit)");
        }
        std::cerr << "Invalid input. Please enter a valid file name." << std::endl;
      } else if (file_name.empty()) {
        std::cerr << "Error: empty string entered" << std::endl;
      } else {
        break;
      }
    }
    return file_name;
  }

  int InputValue(const std::string& prompt, const std::string& errorMessage, const int& minValue, const int& maxValue) {
    int value;
    while (true) {
      std::cout << prompt;
      if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.eof()) {
          current_state_ = State::Exit;
          std::cerr << std::endl << "Ctrl+D (Exit)" << std::endl;
          throw "Exit. Bye!";
        }
        std::cerr << "Invalid input. Please enter a valid value." << std::endl;
      } else if (value < minValue || value > maxValue) {
        std::cerr << errorMessage << std::endl;
      } else {
        break;
      }
    }
    return value;
  }

  void UploadGraph() {
    try {
      std::string file_name = inputFileName();
      graph_.LoadGraphFromFile(file_name);
      this->current_state_ = State::LoadedGraph;
      std::cout << "Graph " << file_name <<  " is loaded!" << std::endl;
    } catch (const s21::GraphException& e) {
      std::cout << e.what() << std::endl;
    } catch (char const* e) {
      std::cerr << e << std::endl;
    }
  }

  void Export() {
    try {
      std::string file_name = inputFileName();
      graph_.ExportGraphToDot(file_name);
      std::cout << "Graph " << file_name <<  " is exported!" << std::endl;
    } catch (const s21::GraphException& e) {
      std::cerr << e.what() << std::endl;
    } catch (char const* e) {
      std::cerr << e << std::endl;
    }
  };

  void BFS() {
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

  void DFS() {
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

  void GetShortestPathBetweenVertices() {
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
      start_vertex = InputValue(prompt_start, error_message, min_value, max_value);
      finish_vertex = InputValue(prompt_finish, error_message, min_value, max_value);
    } catch (char const* e) {
      std::cerr << e << std::endl;
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
    // PrintMatrix(matrix);
    std::cout << matrix;
  }

  void GetLeastSpanningTree() {
    GraphAlgorithms alg;
    std::cout << ">_<"<< std::endl;

    Matrix matrix = alg.GetLeastSpanningTree(graph_);
    std::cout << "\nMatrix of least spanning tree of the graph:\n" << std::endl;
    PrintMatrix(matrix);
  }

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
