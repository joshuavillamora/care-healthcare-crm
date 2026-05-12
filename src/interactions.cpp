#include "../include/interactions.h"

#include <iostream>
#include <stdlib.h>

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