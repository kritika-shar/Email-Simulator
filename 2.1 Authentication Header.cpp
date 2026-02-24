// include/Authentication.h
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../include/User.h"
#include "../include/StorageManager.h"
using namespace std;

class Authentication {
private:
    map<string, User> userDatabase;  // Hash Map for O(1) lookup
    User* currentUser;
    StorageManager storage;
    
    string hashPassword(const string& password);
    string generateUserId();

public:
    Authentication();
    
    bool registerUser(string username, string email, string password);
    bool login(string email, string password);
    bool logout();
    User* getCurrentUser();
    bool isLoggedIn();
    vector<User> getAllUsers();
    bool userExists(string email);
    void displayAllUsers();
};

#endif
