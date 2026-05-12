#include "../include/transactions.h"
#include "../include/database.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

std::vector<Transaction> transactions;

static const std::string TRANSACTIONS_FILE = "transactions.csv";

//Serialization
std::string serializeTransaction(const Transaction& t) {
    return std::to_string(t.id)          + "|" +
           std::to_string(t.patientId)   + "|" +
           t.date                        + "|" +
           std::to_string(t.amount)      + "|" +
           t.serviceType                 + "|" +
           t.description;
}
//Deserialization
Transaction deserializeTransaction(const std::string& line) {
    Transaction t;
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, token, '|'); t.id          = std::stoi(token);
    std::getline(ss, token, '|'); t.patientId   = std::stoi(token);
    std::getline(ss, token, '|'); t.date        = token;
    std::getline(ss, token, '|'); t.amount      = std::stof(token);
    std::getline(ss, token, '|'); t.serviceType = token;
    std::getline(ss, token, '|'); t.description = token;

    return t;
}

//Persitence
void saveTransactionRecords() {
    saveRecords<Transaction>(
        TRANSACTIONS_FILE,
        transactions,
        serializeTransaction
    );
}

void loadTransactionRecords() {
    transactions.clear();
    loadRecords<Transaction>(
        TRANSACTIONS_FILE,
        transactions,
        deserializeTransaction
    );
}

// MENU
void transactionManagement() {
     loadTransactionRecords();

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
        while (std::cin.fail()) {

            std::cout << "Invalid input. Enter a number: ";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cin >> choice;
        }

        switch (choice) {

            case 1:
                addTransaction(transactions);
                saveTransactionRecords();
                break;

            case 2:
                viewTransactions(transactions);
                break;

            case 3:
                editTransaction(transactions);
                saveTransactionRecords();
                break;

            case 4:
                deleteTransaction(transactions);
                saveTransactionRecords();
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
    Transaction t;
    t.id = getNextId (transactions, [](const Transaction& tx) { return tx.id; }); 

    std::cout << "\n=============================\n";
    std::cout << "      ADD TRANSACTION\n";
    std::cout << "=============================\n";
    std::cout << "Transaction ID: " << t.id << "\n";

    std::cout << "Enter Patient ID: ";
    while (!(std::cin >> t.patientId)) {
        std::cout << "Invalid input. Enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Date (MM/DD/YYYY): ";
    std::getline(std::cin, t.date);

    std::cout << "Enter Amount: ";
    while (!(std::cin >> t.amount) || t.amount < 0) {
        std::cout << "Invalid input. Enter a non-negative number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Service Type: ";
    std::getline(std::cin, t.serviceType);

    std::cout << "Enter Description: ";
    std::getline(std::cin, t.description);

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
        std::cout << "Transaction ID : " << t.id          << "\n";
        std::cout << "Patient ID     : " << t.patientId   << "\n";
        std::cout << "Date           : " << t.date        << "\n";
        std::cout << "Amount         : " << std::fixed << std::setprecision(2) << t.amount << "\n";
        std::cout << "Service Type   : " << t.serviceType << "\n";
        std::cout << "Description    : " << t.description << "\n";
        std::cout << "-----------------------------\n";
    }
}

// EDIT TRANSACTION

void editTransaction(std::vector<Transaction>& transactions) {
    if (transactions.empty()) {
        std::cout << "\nNo transactions to edit.\n";
        return;
    }

    std::cout << "\nEnter Transaction ID to edit: ";
    int id;
    while (!(std::cin >> id)) {
        std::cout << "Invalid input. Enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (Transaction& t : transactions) {
        if (t.id != id) continue;

        std::cout << "\n--- Current values ---\n";
        std::cout << "Patient ID   : " << t.patientId   << "\n";
        std::cout << "Date         : " << t.date        << "\n";
        std::cout << "Amount       : " << t.amount      << "\n";
        std::cout << "Service Type : " << t.serviceType << "\n";
        std::cout << "Description  : " << t.description << "\n";
        std::cout << "--- Enter new values (leave blank to keep current) ---\n";


        // Patient ID
        std::cout << "New Patient ID [" << t.patientId << "]: ";
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty()) {
            try { t.patientId = std::stoi(input); }
            catch (...) { std::cout << "Invalid — keeping original.\n"; }
        }

        // Date
        std::cout << "New Date [" << t.date << "]: ";
        std::getline(std::cin, input);
        if (!input.empty()) t.date = input;

        // Amount
        std::cout << "New Amount [" << t.amount << "]: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            try {
                float val = std::stof(input);
                if (val >= 0) t.amount = val;
                else std::cout << "Negative amount — keeping original.\n";
            }
            catch (...) { std::cout << "Invalid — keeping original.\n"; }
        }

        // Service Type
        std::cout << "New Service Type [" << t.serviceType << "]: ";
        std::getline(std::cin, input);
        if (!input.empty()) t.serviceType = input;

        // Description
        std::cout << "New Description [" << t.description << "]: ";
        std::getline(std::cin, input);
        if (!input.empty()) t.description = input;

        std::cout << "\nTransaction updated successfully.\n";
        return;
    }

    std::cout << "\nTransaction ID " << id << " not found.\n";
}

// DELETE TRANSACTION
void deleteTransaction(std::vector<Transaction>& transactions) {
    if (transactions.empty()) {
        std::cout << "\nNo transactions to delete.\n";
        return;
    }

    std::cout << "\nEnter Transaction ID to delete: ";
    int id;
    while (!(std::cin >> id)) {
        std::cout << "Invalid input. Enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto it = std::find_if(
        transactions.begin(), transactions.end(),
        [id](const Transaction& t) { return t.id == id; }
    );

    if (it == transactions.end()) {
        std::cout << "\nTransaction ID " << id << " not found.\n";
        return;
    }

    std::cout << "Delete transaction ID " << id << "? (y/n): ";
    char confirm;
    std::cin >> confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (confirm == 'y' || confirm == 'Y') {
        transactions.erase(it);
        std::cout << "\nTransaction deleted successfully.\n";
    } else {
        std::cout << "\nDeletion cancelled.\n";
    }
}