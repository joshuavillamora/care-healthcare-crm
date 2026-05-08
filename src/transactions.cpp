#include "../include/transactions.h"

#include <iostream>
#include <iomanip>
#include <limits>

void transactionManagement() {

    int choice;

    do {
        std::cout << "=============================\n";
        std::cout << "    TRANSACTION MANAGEMENT\n";
        std::cout << "=============================\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View Transactions\n";
        std::cout << "3. Edit Transaction\n";
        std::cout << "4. Delete Transaction\n";
        std::cout << "5. Back\n";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                std::cout << "Add Transaction selected.\n";
                break;
            case 2:
                std::cout << "View Transactions selected.\n";
                break;
            case 3:
                std::cout << "Edit Transaction selected.\n";
                break;
            case 4:
                std::cout << "Delete Transaction selected.\n";
                break;
            case 5:
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid option! Try again. (1-5)\n";
                break;
        }

    } while (choice != 5);
}