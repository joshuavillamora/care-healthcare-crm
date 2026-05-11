#include "../include/database.h"

#include <vector>
#include <fstring>
#include <sstring>


template <typename T>
void saveRecords(const std::string& filepath, const std::vector<T>& records, std::function<std::string(const T&)> serializer) {
    std::ofstream file(filepath);
    for (const T& record : records) {
        file << serializer(record) << '\n';
    }
    file.close();
}

template <typename T>
void loadRecords(const std::string& filepath, std::vector<T>& records, std::function<T(const std::string&)> deserializer) {
    std::ifstream file(filepath);
    std::string line;
    while (std::getline(file, line)) {
        records.push_back(deserializer(line));
    }
    file.close();
}
