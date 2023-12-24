#include "../s21_graph.h"

namespace s21 {

void Graph::ExportGraphToDot(const std::string& ) {
  // тут нужно записывать файлы в формате .dot
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
