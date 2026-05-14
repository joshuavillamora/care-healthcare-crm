#include "../include/interactions.h"
#include "../include/patients.h"
#include "../include/database.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <limits>

std::vector<Interaction> interactions;

void printInteractionsMenu() {
    std::cout << "============================\n";
    std::cout << "      INTERACTION LOGS\n";
    std::cout << "============================\n";
    std::cout << "1. Add Interaction Log\n";
    std::cout << "2. View All Logs\n";
    std::cout << "3. View Logs per Patient\n";
    std::cout << "4. Delete Log\n";\
    std::cout << "5. Back to Main Menu\n";
}

void addInteractionRecord() {
    Interaction i;

    system("cls");

    std::cout << "==================================\n";
    std::cout << "         LOG INTERACTION\n";
    std::cout << "==================================\n";

    std::cout << "Enter Patient ID: ";
    std::cin >> i.patientId;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();


    bool found = false;

    for (Patient& p : patients) {
        if (p.id == i.patientId) { 
            found = true; 
            break; 
        }
    }

    if (!found) {
        std::cout << "Patient ID not found.\n";
        std::cout << "Press enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Select Interaction Type:\n";
    std::cout << "1. Clinic Visit\n"
              << "2. Appointment Reminder\n"
              << "3. Follow-up Call\n"
              << "4. Lab Results Notification\n"
              << "5. Appointment Rescheduled\n"
              << "6. Patient Inquiry\n"
              << "7. Payment Reminder\n"
              << "8. Other\n"
              << "9. Cancel\n";
    std::cout << ">> ";

    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    switch (choice) {
        case 1: i.type = "Clinic Visit"; break;
        case 2: i.type = "Appointment Reminder"; break;
        case 3: i.type = "Follow-up Call"; break;
        case 4: i.type = "Lab Results Notification"; break;
        case 5: i.type = "Appointment Rescheduled"; break;
        case 6: i.type = "Patient Inquiry"; break;
        case 7: i.type = "Payment Reminder"; break;
        case 8: i.type = "Other"; break;
        case 9: 
            std::cout << "Cancel logging...\n"; 
            return;
        default:
            std::cout << "Invalid choice.\n";
            return;
    }

    std::cout << "Enter Note: ";
    std::getline(std::cin, i.note);

    std::cout << "Enter Interaction Date (YYYY-MM-DD): ";
    std::getline(std::cin, i.date);

    i.loggedAt = "Timestamp Placeholder";
    i.id = getNextId(interactions, [](const Interaction& x) { return x.id; });

    interactions.push_back(i);

    std::cout << "Interaction logged successfully!\n";
    std::cout << "Press enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (const Interaction& interaction : interactions) {
        std::cout << interaction.id << " | "
                  << interaction.patientId << " | "
                  << interaction.type << " | "
                  << interaction.note << " | "
                  << interaction.date << " | "
                  << interaction.loggedAt << "\n";
    }
}
