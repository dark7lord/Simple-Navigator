#ifndef CLI_H
#define CLI_H

#include <map>

#include "../../model/Graph/s21_graph.h"
#include "../../model/GraphAlgorithms/s21_graph_algorithms.h"

namespace s21 {

class CLI {
 public:
  static CLI& getInstance();
  void start();

 private:
  enum class State { EmptyGraph, LoadedGraph, Exit };

  // Helpers
  Graph& getGraph();
  std::string inputFileName();
  int InputValue(const std::string&, const std::string&, const int&,
                 const int&);

  // Files
  void UploadGraph();
  void Export();

  // Methods
  void BFS();
  void DFS();
  void GetShortestPathBetweenVertices();
  void GetShortestPathsBetweenAllVertices();
  void GetLeastSpanningTree();
  void SolveTravelingSalesmanProblem();

  // Menu
  void displayMenu();
  void processInput();
  void ProcessEmptyGraphState(int choice);
  void processLoadedGraphState(int choice);

 private:
  State current_state_;

  void displayOptions(
      const std::vector<std::pair<std::string, std::function<void()>>>&
          options);

  std::vector<std::pair<std::string, std::function<void()>>> emptyGraphOptions_{
      {"Load Graph", [this]() { UploadGraph(); }},
      {"Exit", [this]() { current_state_ = (State::Exit); }}};

  std::vector<std::pair<std::string, std::function<void()>>>
      loadedGraphOptions_{
          {"Load Graph", [this]() { UploadGraph(); }},
          {"Export", [this]() { Export(); }},
          {"Breadth First Search", [this]() { BFS(); }},
          {"Deep First Search", [this]() { DFS(); }},
          {"Get shortest path between vertices",
           [this]() { GetShortestPathBetweenVertices(); }},
          {"Get shortest paths between all vertices",
           [this]() { GetShortestPathsBetweenAllVertices(); }},
          {"Get least spanning tree", [this]() { GetLeastSpanningTree(); }},
          {"Solve traveling salesman problem",
           [this]() { SolveTravelingSalesmanProblem(); }},
          {"Print (adjacency matrix)", [this]() { graph_.PrintGraph(); }},
          {"Print in browser (graph)",
           [this]() { graph_.PrintGraphInBrowser(); }},
          {"Exit", [this]() { current_state_ = (State::Exit); }}};

 private:
  CLI() { current_state_ = State::EmptyGraph; };
  ~CLI() { current_state_ = State::EmptyGraph; };

  CLI(const CLI&) = delete;
  CLI& operator=(const CLI&) = delete;

  Graph graph_;
  CLI* CLI_instance_;
};

}  // namespace s21

#endif  // CLI_H
