#include "../cli.h"

namespace s21 {

void CLI::UploadGraph() {
  try {
    std::string file_name = inputFileName();
    graph_.LoadGraphFromFile(file_name);
    this->current_state_ = State::LoadedGraph;
    std::cout << "Graph " << file_name << " is loaded!" << std::endl;
  } catch (const s21::GraphException& e) {
    std::cout << e.what() << std::endl;
  } catch (char const* e) {
    std::cerr << e << std::endl;
  }
}

void CLI::Export() {
  try {
    std::string file_name = inputFileName();
    graph_.ExportGraphToDot(file_name);
    std::cout << "Graph " << file_name << " is exported!" << std::endl;
  } catch (const s21::GraphException& e) {
    std::cerr << e.what() << std::endl;
  } catch (char const* e) {
    std::cerr << e << std::endl;
  }
};

}  // namespace s21
