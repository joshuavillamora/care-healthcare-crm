#include "../include/patients.h"
#include "../include/database.h"

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

std::string serializePatientRecord(const Patient& p) {
    return p.name + "|" + p.phone + "|" + p.email + "|" + std::to_string(p.age) + "|" + p.address;
}

Patient deserializePatientRecord(const std::string& line) {
    Patient p;
    std::string age;

    std::stringstream ss(line);

    std::getline(ss, p.name, ',');
    std::getline(ss, p.phone, ',');
    std::getline(ss, p.email, ',');
    std::getline(ss, age, ',');
    std::getline(ss, p.address, '\n');

    p.age = std::stoi(age);

    return p;
}

void savePatientRecords() {
    saveRecords<Patient>("data/patients.csv", patients, serializePatientRecord);
}

void loadPatientRecords() {
    loadRecords<Patient>("data/patients.csv", patients, deserializePatientRecord);
}

/*
g++ src/main.cpp src/patients.cpp src/interactions.cpp src/database.cpp -Iinclude -o CARE
./CARE
*/