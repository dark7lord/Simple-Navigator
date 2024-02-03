#include "../s21_graph.h"
#include "gtest/gtest.h"

// Функция для тестирования экспорта графа
void TestExportGraphToDot(const std::string& input_file,
                          const std::string& expected_output_file,
                          const std::string& exported_output_file) {
  s21::Graph graph;

  ASSERT_NO_THROW(graph.LoadGraphFromFile(input_file));
  ASSERT_NO_THROW(graph.ExportGraphToDot(exported_output_file));

  std::ifstream exported_output_stream(exported_output_file + ".dot");
  std::ifstream expected_output_stream(expected_output_file);

  EXPECT_TRUE(exported_output_stream.is_open());
  EXPECT_TRUE(expected_output_stream.is_open());

  std::stringstream expected_content;
  std::stringstream exported_content;

  expected_content << expected_output_stream.rdbuf();
  exported_content << exported_output_stream.rdbuf();

  EXPECT_EQ(exported_content.str(), expected_content.str());
}

TEST(GraphTest, ExportDigraphToDot) {
  TestExportGraphToDot("tests/files/digraph_5x5.txt",
                       "tests/files/digraph_5x5_expected.dot",
                       // tmp for easy deleting in Makefile
                       "tests/files/digraph_5x5_exported.tmp");
}

TEST(GraphTest, ExportGraphToDot) {
  TestExportGraphToDot("tests/files/graph_2x2.txt",
                       "tests/files/graph_2x2_expected.dot",
                       "tests/files/graph_2x2_exported.tmp");
}

TEST(GraphTest, ExportGraphToDotCantCreateFileException) {
  s21::Graph graph;
  ASSERT_NO_THROW(graph.LoadGraphFromFile("tests/files/graph_2x2.txt"));
  EXPECT_THROW(graph.ExportGraphToDot("/invalid/path/graph.dot"),
               s21::CantCreateFileException);
}
