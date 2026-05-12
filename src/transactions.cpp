#include "../include/transactions.h"

#include <iostream>
#include <iomanip>
#include <limits>

std::vector<Transaction> transactions;

// MENU
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
        std::cout << "Enter choice: ";

        std::cin >> choice;

        // INPUT VALIDATION
        while (std::cin.fail()) {

            std::cout << "Invalid input. Enter a number: ";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cin >> choice;
        }

        switch (choice) {

            case 1:
                addTransaction(transactions);
                break;

            case 2:
                viewTransactions(transactions);
                break;

            case 3:
                editTransaction(transactions);
                break;

            case 4:
                deleteTransaction(transactions);
                break;

            case 5:
                std::cout << "Returning to main menu...\n";
                break;

            default:
                std::cout << "Invalid option! Try again.\n";
                break;
        }

    } while (choice != 5);
}


// ADD TRANSACTION
void addTransaction(std::vector<Transaction>& transactions) {

    // PERSISTS BETWEEN FUNCTION CALLS
    static int nextId = 1;

    Transaction t;

    // AUTO-GENERATED ID
    t.id = nextId;

    // PREPARE NEXT AVAILABLE ID
    nextId++;

    std::cout << "\n=============================\n";
    std::cout << "      ADD TRANSACTION\n";
    std::cout << "=============================\n";

    std::cout << "Transaction ID () " << t.id << "\n";
    // PATIENT ID
    std::cout << "Enter Patient ID: ";

    while (!(std::cin >> t.patientId)) {

        std::cout << "Invalid input. Enter a number: ";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // CLEAR BUFFER BEFORE GETLINE
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // DATE
    std::cout << "Enter Date (MM/DD/YYYY): ";
    std::getline(std::cin, t.date);

    // AMOUNT
    std::cout << "Enter Amount: ";

    while (!(std::cin >> t.amount)) {

        std::cout << "Invalid input. Enter a number: ";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // CLEAR BUFFER
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // SERVICE TYPE
    std::cout << "Enter Service Type: ";
    std::getline(std::cin, t.serviceType);

    // DESCRIPTION
    std::cout << "Enter Description: ";
    std::getline(std::cin, t.description);

    // STORE
    transactions.push_back(t);

    std::cout << "\nTransaction added successfully.\n";
}


// VIEW TRANSACTIONS
void viewTransactions(const std::vector<Transaction>& transactions) {

    if (transactions.empty()) {

        std::cout << "\nNo transactions found.\n";
        return;
    }

    std::cout << "\n=============================\n";
    std::cout << "       TRANSACTION LIST\n";
    std::cout << "=============================\n";

    for (const Transaction& t : transactions) {

        std::cout << "Transaction ID : " << t.id << "\n";
        std::cout << "Patient ID     : " << t.patientId << "\n";
        std::cout << "Date           : " << t.date << "\n";
        std::cout << "Amount         : " << t.amount << "\n";
        std::cout << "Service Type   : " << t.serviceType << "\n";
        std::cout << "Description    : " << t.description << "\n";

        std::cout << "-----------------------------\n";
    }
}


// EDIT TRANSACTION
void editTransaction(std::vector<Transaction>& transactions) {

    std::cout << "\nEdit Transaction not implemented yet.\n";
}


// DELETE TRANSACTION
void deleteTransaction(std::vector<Transaction>& transactions) {

    std::cout << "\nDelete Transaction not implemented yet.\n";
}