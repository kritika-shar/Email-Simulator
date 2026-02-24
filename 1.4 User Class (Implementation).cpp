// src/User.cpp
#include "../include/User.h"
#include <sstream>

User::User() : isActive(true) {}

User::User(string id, string name, string mail, string pass) 
    : userId(id), username(name), email(mail), password(pass), isActive(true) {}

// Getters
string User::getUserId() const { return userId; }
string User::getUsername() const { return username; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
bool User::getIsActive() const { return isActive; }

// Setters
void User::setUserId(string id) { userId = id; }
void User::setUsername(string name) { username = name; }
void User::setEmail(string mail) { email = mail; }
void User::setPassword(string pass) { password = pass; }
void User::setIsActive(bool status) { isActive = status; }

// File operations
string User::toFileString() const {
    return userId + "|" + username + "|" + email + "|" + 
           password + "|" + to_string(isActive);
}

User User::fromFileString(const string& line) {
    stringstream ss(line);
    string userId, username, email, password, isActiveStr;
    
    getline(ss, userId, '|');
    getline(ss, username, '|');
    getline(ss, email, '|');
    getline(ss, password, '|');
    getline(ss, isActiveStr);
    
    User user(userId, username, email, password);
    user.setIsActive(isActiveStr == "1");
    return user;
}

void User::displayUser() const {
    cout << "User ID: " << userId << endl;
    cout << "Username: " << username << endl;
    cout << "Email: " << email << endl;
    cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
}
