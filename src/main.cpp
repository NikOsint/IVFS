#include <iostream>

#include "ivfs.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Incorrect usage.\nPlease, type: [path to binary] [archive name]\n";
    return 1;
  }
  TestTask::IVFS ivfs(argv[1]);
  if (!ivfs.Valid()) {
    std::cout << "Incorrect archive name. It should have .zip extension.\n";
    return 1;
  }
  std::string command, filename, data;
  do {
    std::cin >> command;
    if (command == "open") {

    } else if (command == "create") {

    } else if (command == "read") {

    } else if (command == "write") {

    } else if (command == "close") {

    } // else ignore
  } while (command != "q");
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
