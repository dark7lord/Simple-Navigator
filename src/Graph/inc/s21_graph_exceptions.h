#ifndef S21_GRAPH_EXCEPTIONS_H
#define S21_GRAPH_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace s21 {

class GraphException : public std::runtime_error {
 public:
  explicit GraphException(const std::string& message)
      : std::runtime_error(message) {}
};

class CantOpenFileException : public GraphException {
 public:
  explicit CantOpenFileException(const std::string& filename)
      : GraphException("Cannot open file: " + filename) {}
};

class CantCreateFileException : public GraphException {
 public:
  explicit CantCreateFileException(const std::string& filename)
      : GraphException("Cannot create file: " + filename) {}
};

class ParsingErrorException : public GraphException {
 public:
  explicit ParsingErrorException(const std::string& message, int number_line)
      : GraphException("Parsing error at line " + std::to_string(number_line) +
                       ": " + message) {}
};

class MatrixSizeMismatchException : public GraphException {
 public:
  explicit MatrixSizeMismatchException(const std::string& message)
      : GraphException("Matrix size mismatch: " + message) {}
};

class EmptyFileException : public GraphException {
 public:
  explicit EmptyFileException(const std::string& filename)
      : GraphException("File is empty: " + filename) {}
};

class EmptyGraphException : public GraphException {
 public:
  explicit EmptyGraphException() : GraphException("Graph is empty") {}
};

}  // namespace s21

#endif  // S21_GRAPH_EXCEPTIONS_H
