#include "../s21_graph.h"

namespace s21 {

void Graph::ExportGraphToDot(const std::string& filename) {
  if (size_matrix_ == 0) throw EmptyGraphException();

  std::ofstream output_file(filename + ".dot", std::ios::trunc);

  if (!output_file.is_open()) {
    throw CantCreateFileException(filename);
  }

  std::string padding = "  ";

  output_file << (is_digraph ? "digraph " : "graph ") << filename;


  output_file << " {" << std::endl;

  for (size_t i = 0; i != size_matrix_; i++) {
    output_file << padding << i + 1 << ";" << std::endl;
  }

  output_file << std::endl;

  std::string sep = is_digraph ? "->" : "--";

  for (size_t i = 0; i != size_matrix_; i++) {
    for (size_t j = 0; j != size_matrix_; j++) {

      if (matrix_[i][j] != 0) {
        if (!is_digraph && i > j) continue;
        std::string length = " [label=\"" + std::to_string(matrix_[i][j]) + "\"]";
        output_file << padding << i + 1 << sep << j + 1 << length << ";" << std::endl;
      }
    }
  }

  output_file << "}";
  output_file.close();
}

void Graph::PrintGraph() {
  for (size_t i = 0; i < size_matrix_; ++i) {
    for (size_t j = 0; j < size_matrix_; ++j) {
      std::cout << matrix_[i][j] << '\t';
    }
    std::cout << std::endl;
  }
}

}
