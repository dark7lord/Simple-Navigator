#include "../s21_graph.h"

namespace s21 {

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

const std::string Graph::ToString_() const {
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

  output_file << this->ToString_();
  output_file.close();
}

// TODO: нужно вынести эту штуку в console line interface (CLI)
void Graph::PrintGraphInBrowser() {
  std::string cmd = "open ";
  std::string site = "https://dreampuf.github.io/GraphvizOnline/#";
  std::string encoded_graph = UrlEncode(this->ToString_());
  std::string result = cmd + site + encoded_graph;

  std::system(result.c_str());
}

}  // namespace s21
