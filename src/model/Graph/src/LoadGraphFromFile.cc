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

static void ReadMatrixElements(std::ifstream& file, Matrix& matrix,
                               size_t& size) {
  SkipWhitespace(file);

  for (size_t i = 0; i < size; ++i) {
    std::string line;
    std::getline(file, line);

    std::istringstream iss(line);
    std::vector<size_t> row;

    size_t element;
    while (iss >> element) {
      if ((int)element < 0) {
        file.close();
        throw ParsingErrorException("Negative numbers are not allowed", i);
      }
      row.push_back(element);
    }

    if (row.size() != size) {
      file.close();
      throw MatrixSizeMismatchException(
          "Number of elements in a row does not match the specified matrix "
          "size");
    }

    matrix[i] = row;
  }

  if (file.fail()) {
    file.close();
    throw MatrixSizeMismatchException(
        "Number of elements in a row does not match the specified matrix size");
  }
}

static bool findoutDigraph(Matrix matrix, size_t size) {
  for (size_t i = 0; i != size; i++) {
    for (size_t j = 0; j != size; j++) {
      if (matrix[j][i] != matrix[i][j]) {
        return true;
      }
    }
  }
  return false;
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
  is_digraph = findoutDigraph(matrix_, size_matrix_);
}

}  // namespace s21
