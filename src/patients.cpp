#include "../include/patients.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<Patient> patients;

void printPatientManagementMenu() {
    std::cout << "=================================\n";
    std::cout << "       PATIENT MANAGEMENT\n";
    std::cout << "=================================\n";
    std::cout << "1. Add new patient\n";
    std::cout << "2. View patient list\n";
    std::cout << "3. Update patient information\n";
    std::cout << "4. Delete patient record\n";
    std::cout << "5. Search patient by ID or name\n";
}

void addPatientRecords() {
    Patient p;

    system("cls");

    std::cout << "==================================\n";
    std::cout << "           ADD PATIENT\n";
    std::cout << "==================================\n";

    std::cin.ignore();

    std::cout << "Enter Full Name: ";
    std::getline(std::cin, p.name);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, p.phone);

    std::cout << "Enter Email: ";
    std::getline(std::cin, p.email);

    std::cout << "Enter Age: ";
    std::cin >> p.age;
    std::cin.ignore();

    std::cout << "Address: ";
    std::getline(std::cin, p.address);

    patients.push_back(p);
}

void savePatientRecords() {
    std::ofstream file("data/patients.csv");
    for (Patient& p : patients) {
        file << p.name << ','
             << p.phone << ','
             << p.email << ','
             << p.age << ','
             << p.address << '\n';
    }
    file.close();
}
/*
g++ src/main.cpp src/patients.cpp src/interactions.cpp -Iinclude -o CARE
./CARE
*/