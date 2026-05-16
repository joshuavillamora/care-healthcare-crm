#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <vector>

struct User {
    int id;
    std::string username;
    std::string passwordHash;
    std::string role;        // "admin", "staff", "patient"
    int linkedPatientId;     // -1 if not a patient
};

extern User currentUser;
extern bool isLoggedIn;
extern std::vector<User> users;

std::string hashPassword(const std::string& password);
void login();
void staffLogin();
void patientLogin();
void seedAdminAccount();

#endif