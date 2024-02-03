#include "s21_graph.h"

namespace s21 {

const std::string Graph::ToString() const {
  if (size_matrix_ == 0) throw EmptyGraphException();

  std::ostringstream result;
  std::string padding = "  ";

  result << (is_digraph ? "digraph" : "graph") << " {" << std::endl;

  for (size_t i = 0; i != size_matrix_; i++)
    result << padding << (i + 1) << ";" << std::endl;

  result << std::endl;
  std::string sep = is_digraph ? "->" : "--";

  for (size_t i = 0; i != size_matrix_; i++) {
    for (size_t j = 0; j != size_matrix_; j++) {
      if (matrix_[i][j] != 0) {
        if (!is_digraph && i > j) continue;  // HasAlreadyAddedUndirectedEdge

        std::string length =
            " [label=\"" + std::to_string(matrix_[i][j]) + "\"]";
        result << padding << (i + 1) << sep << (j + 1) << length << ";"
               << std::endl;
      }
    }
  }

  result << "}" << std::endl;

  return result.str();
}

void Graph::ExportGraphToDot(const std::string &filename) {
  std::ofstream output_file(filename + ".dot", std::ios::trunc);

  if (!output_file.is_open()) {
    throw CantCreateFileException(filename);
  }

  output_file << this->ToString();
  output_file.close();
}

}  // namespace s21
