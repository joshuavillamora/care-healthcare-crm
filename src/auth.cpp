#include "../include/auth.h"

#include <iostream>
#include <limits>

void login() {
    system("cls");

    std::cout << "================================================\n";
    std::cout << "        CLINICAL ACTIVITY RECORDS ENGINE\n";
    std::cout << "================================================\n";
    std::cout << "1. Login as Staff\n";
    std::cout << "2. Login as Patient\n";
    std::cout << "3. Exit\n";
    std::cout << ">> ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            std::cout << "Staff Login"; 
            break;
        case 2:
            std::cout << "Patient Login";
            break;
        case 3: 
            return;
        default:
            std::cout << "Invalid input.\n";
            login();
    }
}