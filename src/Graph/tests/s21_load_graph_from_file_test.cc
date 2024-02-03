#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <iostream>

#include "s21_graph.h"

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
  ASSERT_THROW(graph.LoadGraphFromFile(invalidFileName),
               s21::CantOpenFileException);
}

TEST_F(GraphFixture, ParsingErrorTest) {
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/parsing_error_file.txt"),
               s21::ParsingErrorException);
}

TEST_F(GraphFixture, EmptyFileTest) {
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/empty_file.txt"),  // ?
               s21::EmptyFileException);
}

TEST_F(GraphFixture, AlmostEmptyFileTest) {
  ASSERT_THROW(
      graph.LoadGraphFromFile("tests/files/almost_empty_file.txt"),  // ?
      s21::EmptyFileException);
}

TEST_F(GraphFixture, MatrixSizeMismatchTest1) {
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/wrong_matrix.txt"),
               s21::MatrixSizeMismatchException);
}

TEST_F(GraphFixture, MatrixSizeMismatchTest2) {
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/mismatch_matrix.txt"),
               s21::MatrixSizeMismatchException);
}

TEST_F(GraphFixture, NegativeNumbersTest) {
  ASSERT_THROW(graph.LoadGraphFromFile("tests/files/negative_numbers.txt"),
               s21::ParsingErrorException);
}

TEST_F(GraphFixture, ExtraLineAfterMatrixTest) {
  std::string filename = "tests/files/extra_line_after_matrix.txt";
  ASSERT_THROW(graph.LoadGraphFromFile(filename),
               s21::MatrixSizeMismatchException);
}

TEST_F(GraphFixture, EmptyFileTest2) {
  std::string filename = "tests/files/empty_matrix.txt";
  // graph.LoadGraphFromFile(filename);
  ASSERT_THROW(graph.ToString(), s21::EmptyGraphException);
}
