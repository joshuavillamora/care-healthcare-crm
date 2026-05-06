#include "../include/interactions.h"

#include <iostream>
#include <limits>

void printHomePage();
void interactionsModule();

int main() {
    int choice;
    
    do {
        printHomePage();

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                std::cout << "This is the Patient Management Module.\n";
                break;
            case 2:
                std::cout << "This is the Transaction Management Module.\n";
                break;
            case 3:
                interactionsModule();
                break;
            case 4:
                std::cout << "This is the Reporting Module.\n";
                break;
            case 5:
                std::cout << "Thank you for using Clinical Activity and Records Engine!\n";
                break;
            default:
                std::cout << "Invalid option! Try again. (1-5)\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

void printHomePage() {
    std::cout << "=============================\n";
    std::cout << "    HEALTHCARE CRM SYSTEM\n";
    std::cout << "=============================\n";
    std::cout << "1. Patient Management\n";
    std::cout << "2. Transaction Management\n";
    std::cout << "3. Interaction Logs\n";
    std::cout << "4. Reports\n";\
    std::cout << "5. Exit\n";
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
                std::cout << "This is add interaction log.\n";
                break;
            case 2:
                std::cout << "This is view all logs.\n";
                break;
            case 3:
                std::cout << "This is view logs per patient.\n";
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