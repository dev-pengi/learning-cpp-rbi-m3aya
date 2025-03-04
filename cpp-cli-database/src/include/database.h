#pragma once
#include <string>
#include <vector>

struct Record {
  int id;
  int age;
  std::string name;
};

class Database {

private:
  std::vector<Record> records;

public:
  void insert(Record record);
  void remove(int id);
  void selectAll();
  Database();
  ~Database();
};