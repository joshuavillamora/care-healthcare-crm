#ifndef DATABASE_H
#define DATABASE_H

void saveRecords(const std::string& filepath, const std::vector<T>& records, std::function<std::string(const T&)> serializer);
void loadRecords(const std::string& filepath, std::vector<T>& records, std::function<T(const std::string&)> deserializer);

#endif