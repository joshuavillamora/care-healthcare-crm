#ifndef INTERACTIONS_H
#define INTERACTIONS_H

struct Interaction {
    int id;
    int patientId;
    std::string type;
    std::string note;
    std::string date;
    std::string loggedAt;
};

void printInteractionsMenu();

#endif