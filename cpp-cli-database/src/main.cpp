#include "include/database.h"
#include <iostream>

void Exit(bool &isRunning, std::string code) {
  std::cout << "database is closing with code: " << code << std::endl;
  isRunning = false;
}

int main() {
  Database db;
  std::string command;

  bool isRunning = true;

  while (isRunning) {
    std::cout << "db> ";
    std::cin >> command;

    if (command == "EXIT")
      Exit(isRunning, "0");
    else if (command == "INSERT") {
      int id, age;
      std::string name;
      std::cout << "Enter ID Name Age: ";
      std::cin >> id >> name >> age;
      db.insert(Record{id, age, name});
    } else if (command == "SELECT") {
      db.selectAll();
    } else if (command == "DELETE") {
      int id;
      std::cout << "Enter ID to delete: ";
      std::cin >> id;
      db.remove(id);
    } else {
      std::cout << "Unknown command!\n";
    }
  }

  isRunning = false;

  return 0;
}
