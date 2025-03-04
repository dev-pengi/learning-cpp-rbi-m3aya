#pragma once

#include "database.h"
#include <string>

class Storage {
public:
  void saveToFile(const std::string &filename,
                  const std::vector<Record> &records);
  std::vector<Record> readFromFile(const std::string &filename);
};
