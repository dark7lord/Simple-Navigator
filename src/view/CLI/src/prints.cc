#include "../cli.h"

namespace s21 {

void CLI::PrintMatrix(const Matrix& matrix) {
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

static std::string UrlEncode(const std::string &value) {
  std::ostringstream escaped;
  escaped.fill('0');
  escaped << std::hex;

  for (char c : value) {
    if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
      escaped << c;
    } else if (c == ' ') {
      escaped << "%20";
    } else {
      escaped << '%' << std::setw(2)
              << static_cast<int>(static_cast<unsigned char>(c));
    }
  }

  return escaped.str();
}

void CLI::PrintGraphInBrowser(const Graph& graph) {
  std::string cmd = "open ";
  std::string site = "https://dreampuf.github.io/GraphvizOnline/#";
  std::string encoded_graph = UrlEncode(graph.ToString());
  std::string result = cmd + site + encoded_graph;

  std::system(result.c_str());
}

// void CLI::PrintMatrix(const Matrix& matrix) {
//   size_t inf = -1;
//   size_t size = matrix.size();

//   std::cout << " ";
//   for (size_t k = 1; k <= size; ++k) std::cout << "\t" << k;
//   std::cout << std::endl;
//   for (size_t k = 0; k <= size; ++k)
//     std::cout << " "
//               << "\t";
//   std::cout << std::endl;

//   for (size_t i = 0; i < size; ++i) {
//     std::cout << (i + 1) << ")\t";
//     for (size_t j = 0; j < size; ++j) {
//       auto result = matrix[i][j] != inf ? std::to_string(matrix[i][j]) : "∞";
//       std::cout << result << '\t';
//     }
//     std::cout << std::endl;
//   }

//   std::cout << std::endl;
// }

// void Graph::PrintGraph() const { PrintMatrix(matrix_); }

// std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
//   PrintMatrix(matrix);
//   return os;
// }

} // namespace s21
