#include "../s21_graph.h"

namespace s21 {

static void SkipWhitespace(std::ifstream& file) {
  while (file.peek() == ' ' || file.peek() == '\t' || file.peek() == '\n') {
    file.get();
  }
}

static void ReadMatrixSize(std::ifstream& file, size_t& size_matrix) {
  file >> size_matrix;

  if (file.fail()) {
    file.close();
    throw ParsingErrorException("Failed to read matrix size", 0);
  }
}

static void ReadMatrixElements(std::ifstream& file, Matrix& matrix, size_t& size) {
  SkipWhitespace(file);

  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      file >> matrix[i][j];

      if (file.fail()) {
        file.close();
        throw ParsingErrorException("Failed to read matrix element", i);
      }
    }

    if (file.peek() != '\n') {
      file.close();
      throw MatrixSizeMismatchException(
        "Number of elements in a row does not match the specified matrix size");
    }

    file.get();
    SkipWhitespace(file);
  }
}

void Graph::LoadGraphFromFile(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) throw CantOpenFileException(filename);

  SkipWhitespace(file);

  if (file.eof()) {
    file.close();
    throw EmptyFileException(filename);
  }

  matrix_.clear();
  ReadMatrixSize(file, size_matrix_);

  if (size_matrix_ == 0) {
    file.close();
    throw EmptyFileException(filename);
  }

  matrix_.resize(size_matrix_, std::vector<size_t>(size_matrix_, 0));
  SkipWhitespace(file);
  ReadMatrixElements(file, matrix_, size_matrix_);
  file.close();
}

}  // namespace s21
