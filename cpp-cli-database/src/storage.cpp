#include "include/storage.h"
#include "include/database.h"
#include "include/utils.h"
#include <fstream>

void Storage::saveToFile(const std::string &filename,
                         const std::vector<Record> &records) {
  std::ofstream file(filename);

  for (auto it = records.begin(); it != records.end(); ++it) {
    file << it->id << " " << it->name << " " << it->age << std::endl;
  }
}

std::vector<Record> Storage::readFromFile(const std::string &filename) {
  std::vector<Record> records;
  std::ifstream file(filename);

  if (!file.is_open()) {
    return records;
  } else {
    while (!file.eof()) {
      Record record;
      file >> record.id >> record.name >> record.age;
      records.push_back(record);
    }
  }

  return Utils::trimVector(records);
};
