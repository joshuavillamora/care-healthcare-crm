#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <string>

struct Interaction {
    int id;
    int patientId;
    std::string type;
    std::string note;
    std::string date;
    std::string loggedAt;
};

void printInteractionsMenu();
void addInteractionRecord();
std::string getCurrentTimestamp();
std::string serializeInteractionRecord(const Interaction& i);
Interaction deserializeInteractionRecord(const std::string& line);
void saveInteractionLogs();
void loadInteractionLogs();
void viewInteractionLogs();
void viewLogsByPatient();
void deleteInteractionLog();

#endif