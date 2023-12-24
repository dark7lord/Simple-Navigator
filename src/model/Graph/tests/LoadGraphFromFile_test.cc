#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "../s21_graph.h"

class GraphFixture : public testing::Test {
protected:
  s21::Graph graph;
};

// Helpers
void CreateTempFile(const std::string& filename, const std::string& content) {
  std::ofstream file(filename);
  file << content;
  file.close();
}

void RemoveFile(const std::string& filename) {
  if (std::filesystem::exists(filename)) {
    std::filesystem::remove(filename);
  }
}

// Tests
TEST_F(GraphFixture, InvalidFileTest) {
  std::string invalidFileName = "tests/files/invalid_file.txt";
  ASSERT_THROW(graph.LoadGraphFromFile(invalidFileName), s21::CantOpenFileException);
}

TEST_F(GraphFixture, ParsingErrorTest) {
  std::string invalidContent = "invalid_content";
  CreateTempFile("tests/files/parsing_error_file.txt", invalidContent);
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/parsing_error_file.txt"), s21::ParsingErrorException);
  RemoveFile("tests/files/parsing_error_file.txt");
}

TEST_F(GraphFixture, EmptyFileTest) {
  CreateTempFile("tests/files/empty_file.txt", "");
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/empty_file.txt"), s21::EmptyFileException);
  RemoveFile("tests/files/empty_file.txt");
}

TEST_F(GraphFixture, MatrixSizeMismatchTest) {
  std::string mismatchContent = "2\n1 2\n3 4 5";
  CreateTempFile("tests/files/matrix_size_mismatch_file.txt", mismatchContent);
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/matrix_size_mismatch_file.txt"), s21::MatrixSizeMismatchException);
  RemoveFile("tests/files/matrix_size_mismatch_file.txt");
}
