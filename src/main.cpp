#include "../include/patients.h"
#include "../include/interactions.h"
#include "../include/transactions.h"
#include "../include/auth.h"
#include "../include/usermanagement.h"

#include <iostream>
#include <limits>

void printStaffMenu();
void printAdminMenu();
void patientManagementModule();
void interactionsModule();
void reportsModule();
void staffMenu();
void adminMenu();

int main() {
    loadUsers();
    loadPatientRecords();
    loadInteractionLogs();

    if (users.empty()) {
        seedAdminAccount();
        seedStaffAccount();
        seedPatientAccount();
    }

    while (true) {
        while (!isLoggedIn && !exitRequested) {
            login();
        }

        if (!isLoggedIn) {
            std::cout << "Thank you for using Clinical Activity and Records Engine!\n";
            return 0;
        }

        if (currentUser.role == "admin") {
            adminMenu();
        }

        if (currentUser.role == "staff") {
            staffMenu();
        }
    }

    return 0;
}

void adminMenu() {
    int choice;
    do {
        system("cls");
        printAdminMenu();

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                patientManagementModule();
                break;
            case 2:                
                transactionManagement();
                break;
            case 3:
                interactionsModule();
                break;
            case 4:
                reportsModule();
                break;
            case 5:
                userManagementModule();
                break;
            case 6:
                return;
                break;
            default:
                std::cout << "Invalid option! Try again. (1-5)\n";
                break;
        }
    } while (choice != 6);
}


void staffMenu() {
    int choice;
    do {
        system("cls");
        printStaffMenu();

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                patientManagementModule();
                break;
            case 2:                
                transactionManagement();
                break;
            case 3:
                interactionsModule();
                break;
            case 4:
                reportsModule();
                break;
            case 5:
                return;
                break;
            default:
                std::cout << "Invalid option! Try again. (1-5)\n";
                break;
        }
    } while (choice != 5);
}

void printStaffMenu() {
    std::cout << "=============================\n";
    std::cout << "    HEALTHCARE CRM SYSTEM\n";
    std::cout << "=============================\n";
    std::cout << "1. Patient Management\n";
    std::cout << "2. Transaction Management\n";
    std::cout << "3. Interaction Logs\n";
    std::cout << "4. Reports\n";
    std::cout << "5. Exit\n";
}

void printAdminMenu() {
    std::cout << "=============================\n";
    std::cout << "    HEALTHCARE CRM SYSTEM\n";
    std::cout << "=============================\n";
    std::cout << "1. Patient Management\n";
    std::cout << "2. Transaction Management\n";
    std::cout << "3. Interaction Logs\n";
    std::cout << "4. Reports\n";
    std::cout << "5. User Management\n";
    std::cout << "6. Exit\n";
}

void patientManagementModule() {
    int choice;

    do {
        printPatientManagementMenu();

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addPatientRecords();
                savePatientRecords();
                break;
            case 2:
                viewPatientRecords();
                break;
            case 3:
                updatePatientRecord();
                break;
            case 4:
                deletePatientRecord();
                break;
            case 5:
                searchPatientRecord();
                break;
            case 6:
                std::cout << "Going back to main menu...\n";
                break;
            default:
                std::cout << "Invalid option! Try again. (1-6)\n";
                break;
        }
    } while (choice != 6);
}

void interactionsModule() {
    int choice;

    do {
        printInteractionsMenu();

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addInteractionRecord();
                break;
            case 2:
                viewInteractionLogs();
                break;
            case 3:
                viewLogsByPatient();
                break;
            case 4:
                std::cout << "This is delete logs.\n";
                break;
            case 5:
                std::cout << "Going back to main menu...\n";
                break;
            default:
                std::cout << "Invalid option! Try again. (1-5)\n";
                break;
        }
    } while (choice != 5);
}