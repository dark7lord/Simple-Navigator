#include "../s21_graph.h"

namespace s21 {

using size_t = std::size_t;

void Graph::LoadGraphFromFile(const std::string& filename) {
  std::ifstream file(filename);

  // if (!input_file.is_open()) {
  //   throw IKeyValueStorage::CantOpenFile(filename);
  // }

  matrix_.clear();
  file >> size_matrix_;
  matrix_.resize(size_matrix_, std::vector<size_t>(size_matrix_, 0));


  for (size_t i = 0; i < size_matrix_; ++i) {
    for (size_t j = 0; j < size_matrix_; ++j) {
      file >> matrix_[i][j];
    }
  }

  file.close();
}

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
