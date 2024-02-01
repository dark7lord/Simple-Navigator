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
  ASSERT_THROW(
    graph.LoadGraphFromFile(invalidFileName),
    s21::CantOpenFileException
  );
}

TEST_F(GraphFixture, ParsingErrorTest) {
  ASSERT_THROW(
    graph.LoadGraphFromFile("tests/files/parsing_error_file.txt"),
    s21::ParsingErrorException
  );
}

TEST_F(GraphFixture, EmptyFileTest) {
  ASSERT_THROW(
    graph.LoadGraphFromFile("tests/files/empty_file.txt"),
    s21::EmptyFileException
  );
}

TEST_F(GraphFixture, MatrixSizeMismatchTest) {
  ASSERT_THROW(graph.LoadGraphFromFile(
    "tests/files/wrong_matrix.txt"),
    s21::MatrixSizeMismatchException
  );
}

TEST_F(GraphFixture, NegativeNumbersTest) {
  ASSERT_THROW(
    graph.LoadGraphFromFile("tests/files/negative_numbers.txt"),
    s21::ParsingErrorException
  );
}
