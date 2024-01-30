#include "../cli.h"

namespace s21 {

std::string CLI::inputFileName() {
  std::string file_name;
  while (true) {
    std::cout << "Enter file name: ";
    if (!(std::cin >> file_name)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << "Ctrl+D (Exit)" << std::endl;
        // break;
        throw "Exit. Bye!";
        // throw std::runtime_error("Ctrl+D (Exit)");
      }
      std::cerr << "Invalid input. Please enter a valid file name."
                << std::endl;
    } else if (file_name.empty()) {
      std::cerr << "Error: empty string entered" << std::endl;
    } else {
      break;
    }
  }
  return file_name;
}

int CLI::InputValue(const std::string& prompt, const std::string& errorMessage,
                    const int& minValue, const int& maxValue) {
  int value;
  while (true) {
    std::cout << prompt;
    if (!(std::cin >> value)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.eof()) {
        current_state_ = State::Exit;
        std::cerr << std::endl << "Ctrl+D (Exit)" << std::endl;
        throw "Exit. Bye!";
      }
      std::cerr << "Invalid input. Please enter a valid value." << std::endl;
    } else if (value < minValue || value > maxValue) {
      std::cerr << errorMessage << std::endl;
    } else {
      break;
    }
  }
  return value;
}

}  // namespace s21
