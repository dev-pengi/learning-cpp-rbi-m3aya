#include "include/database.h"
#include "include/storage.h"
#include <iostream>

Storage stoage;

Database::Database() { records = stoage.readFromFile("db.txt"); }

Database::~Database() { stoage.saveToFile("db.txt", records); }

void Database::insert(Record record) {
  records.push_back(record);
  stoage.saveToFile("db.txt", records);
}

void Database::remove(int id) {
  for (auto it = records.begin(); it != records.end(); ++it) {
    if (it->id == id) {
      records.erase(it);
      break;
    }
  }
  stoage.saveToFile("db.txt", records);
}

void Database::selectAll() {
  for (auto i = records.begin(); i != records.end(); ++i) {
    std::cout << "ID: " << i->id << " Name: " << i->name << " Age: " << i->age
              << std::endl;
  }
}
