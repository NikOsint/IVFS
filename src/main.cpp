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
  char buff[100];
  do {
    std::cin >> command;
    if (command == "open") {
      std::cin >> filename;
      if (ivfs.Open(filename.c_str())) {
        std::cout << "File " << filename << " is successfully opened for reading.\n";
      } else {
        std::cout << "Error while opening " << filename << " for reading.\nIt does not exist OR is opened in writeonly mode.\n";
      }
    } else if (command == "create") {
      std::cin >> filename;
      if (ivfs.Create(filename.c_str())) {
        std::cout << "File " << filename << " is successfully opened for writing.\n";
      } else {
        std::cout << "Error while opening " << filename << " for writing.\nIt is opened in readonly mode.\n";
      }
    } else if (command == "read") {
      std::cin >> filename;
      TestTask::File *readFile = ivfs.OpenedReadonly(filename.c_str());
      if (!readFile) {
        std::cout << "Error: " << filename << " is not opened for reading.\n";
      } else {
        size_t read_bytes = ivfs.Read(readFile, buff);
        if (read_bytes) {
          std::cout << "Successfully read " << read_bytes << " from " << filename << "\n";
        } else {
          std::cout << "Error while reading from " << filename << ".\n";
        }
      }
    } else if (command == "write") {
      std::cin >> filename;
      TestTask::File *writeFile = ivfs.OpenedWriteonly(filename.c_str());
      if (!writeFile) {
        std::cout << "Error: " << filename << " is not opened for writing.\n";
      } else {
        size_t write_bytes = ivfs.Write(writeFile, buff);
        if (write_bytes) {
          std::cout << "Successfully wrote " << write_bytes << " to " << filename << "\n";
        } else {
          std::cout << "Error while writing to " << filename << ".\n";
        }
      }
    } else if (command == "close") {
      std::cin >> filename;
      TestTask::File *readFile = ivfs.OpenedReadonly(filename.c_str());
      TestTask::File *writeFile = ivfs.OpenedWriteonly(filename.c_str());
      if (readFile) {
        ivfs.Close(readFile);
        std::cout << filename << " successfully closed.\n";
      } else if (writeFile) {
        ivfs.Close(writeFile);
        std::cout << filename << " successfully closed.\n";
      } else {
        std::cout << filename << " is not opened.\n";
      }
    } // else ignore command and wait for another
  } while (command != "q");
  return 0;
}
