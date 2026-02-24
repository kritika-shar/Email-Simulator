// include/User.h
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string userId;
    string username;
    string email;
    string password;
    bool isActive;

public:
    User();
    User(string userId, string username, string email, string password);
    
    // Getters
    string getUserId() const;
    string getUsername() const;
    string getEmail() const;
    string getPassword() const;
    bool getIsActive() const;
    
    // Setters
    void setUserId(string id);
    void setUsername(string name);
    void setEmail(string mail);
    void setPassword(string pass);
    void setIsActive(bool status);
    
    // Utility functions
    string toFileString() const;
    static User fromFileString(const string& line);
    void displayUser() const;
};

#endif