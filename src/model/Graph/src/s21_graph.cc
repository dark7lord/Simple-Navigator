#include "../s21_graph.h"

namespace s21 {

void PrintMatrix(const Matrix& matrix) {
  size_t inf = -1;
  size_t size = matrix.size();

  std::cout << " ";
  for (size_t k = 1; k <= size; ++k) std::cout << "\t" << k;
  std::cout << std::endl;
  for (size_t k = 0; k <= size; ++k)
    std::cout << " "
              << "\t";
  std::cout << std::endl;

  for (size_t i = 0; i < size; ++i) {
    std::cout << (i + 1) << ")\t";
    for (size_t j = 0; j < size; ++j) {
      auto result = matrix[i][j] != inf ? std::to_string(matrix[i][j]) : "∞";
      std::cout << result << '\t';
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Graph::PrintGraph() const { PrintMatrix(matrix_); }

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
  PrintMatrix(matrix);
  return os;
}

}  // namespace s21
