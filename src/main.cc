#include "cli/s21_cli.h"

int main() {
  s21::Graph CLI;
  s21::CLI& cli = s21::CLI::getInstance();
  cli.start();
}
