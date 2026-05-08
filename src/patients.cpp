#include "../include/patients.h"

#include <iostream>
#include <stdlib.h>

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