#ifndef PATIENTS_H
#define PATIENTS_H

#include <string>

struct Patient {
   int id;
   std::string name;
   std::string phone;
   std::string email;
   int age;
   std::string address;
};

void printPatientManagementMenu();
void addPatientRecords();

#endif