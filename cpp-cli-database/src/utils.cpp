#include "include/utils.h"
#include <vector>

std::vector<Record> Utils::trimVector(std::vector<Record> records) {
  for (auto it = records.begin(); it != records.end(); ++it) {
    if (it->name.back() == '\n') {
      it->name.pop_back();
    }
  }

  return records;
}