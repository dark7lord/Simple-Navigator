#include "../cli.h"

namespace s21 {

CLI& CLI::getInstance() {
  static CLI instance;
  return instance;
}

Graph& CLI::getGraph() { return graph_; }

void CLI::start() {
  while (current_state_ != State::Exit) {
    displayMenu();
    processInput();
  }
}

void CLI::displayMenu() {
  // int i = 0;
  std::cout << std::endl;
  std::cout << "Select a command to execute: " << std::endl;
  switch (current_state_) {
    case State::EmptyGraph:
      displayOptions(emptyGraphOptions_);
      break;
    case State::LoadedGraph:
      displayOptions(loadedGraphOptions_);
      break;
    default:
      break;
  }

  std::cout << std::endl << "Enter your choice: ";
}

void CLI::processInput() {
  int choice;
  if (!(std::cin >> choice)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.eof()) {
      current_state_ = State::Exit;
      std::cerr << "Ctrl+D (Exit)" << std::endl;
      return;
    }
    std::cerr << "Invalid input. Please enter a number." << std::endl;
    return;
  }

  std::vector<std::pair<std::string, std::function<void()>>> options;
  switch (current_state_) {
    case State::EmptyGraph:
      options = emptyGraphOptions_;
      break;
    case State::LoadedGraph:
      options = loadedGraphOptions_;
      break;
    default:
      break;
  }

  if (choice >= 1 && static_cast<size_t>(choice) <= options.size()) {
    options[choice - 1].second();
  } else {
    std::cout << "Invalid choice. Please try again.\n";
  }
}

void CLI::ProcessEmptyGraphState(int choice) {
  switch (choice) {
    case 1:
      std::cout << "Graph loaded!\n";
      current_state_ = State::LoadedGraph;
      break;
    case 2:
      std::cout << "Exiting...\n";
      current_state_ = State::Exit;
      break;
    default:
      std::cout << "Invalid choice. Try again.\n";
      break;
  }
}

void CLI::processLoadedGraphState(int choice) {
  switch (choice) {
    case 1:
      std::cout << "Graph unloaded.\n";
      current_state_ = State::EmptyGraph;
      break;
    case 2:
      std::cout << "Exiting...\n";
      current_state_ = State::Exit;
      break;
    default:
      std::cout << "Invalid choice. Try again.\n";
      break;
  }
}

void CLI::displayOptions(
    const std::vector<std::pair<std::string, std::function<void()>>>& options) {
  int i = 0;
  for (const auto& option : options) {
    std::cout << ++i << ". " << option.first << std::endl;
  }
}

}  // namespace s21
