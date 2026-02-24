// src/Authentication.cpp
#include "../include/Authentication.h"
#include <algorithm>
#include <cctype>

Authentication::Authentication() : currentUser(nullptr) {
    loadUsersFromStorage();
}

void Authentication::loadUsersFromStorage() {
    vector<string> lines = storage.readAllLines("data/users.txt");
    for (const string& line : lines) {
        if (!line.empty()) {
            User user = User::fromFileString(line);
            userDatabase[user.getEmail()] = user;
        }
    }
}

string Authentication::hashPassword(const string& password) {
    // Simple hash function for demonstration
    // In real applications, use bcrypt or similar
    int hash = 0;
    for (char c : password) {
        hash = (hash * 31 + c) % 100000;
    }
    return to_string(hash);
}

string Authentication::generateUserId() {
    static int counter = 1000;
    return "USR" + to_string(++counter);
}

bool Authentication::registerUser(string username, string email, string password) {
    // Convert email to lowercase for case-insensitive lookup
    transform(email.begin(), email.end(), email.begin(), ::tolower);
    
    // Check if user already exists
    if (userDatabase.find(email) != userDatabase.end()) {
        cout << "Error: Email already registered!" << endl;
        return false;
    }
    
    // Validate email format (basic validation)
    if (email.find('@') == string::npos || email.find('.') == string::npos) {
        cout << "Error: Invalid email format!" << endl;
        return false;
    }
    
    // Validate password strength
    if (password.length() < 6) {
        cout << "Error: Password must be at least 6 characters!" << endl;
        return false;
    }
    
    // Create new user
    string userId = generateUserId();
    string hashedPassword = hashPassword(password);
    
    User newUser(userId, username, email, hashedPassword);
    userDatabase[email] = newUser;
    
    // Save to storage
    storage.appendLine("data/users.txt", newUser.toFileString());
    
    cout << "Registration successful! User ID: " << userId << endl;
    return true;
}

bool Authentication::login(string email, string password) {
    transform(email.begin(), email.end(), email.begin(), ::tolower);
    
    auto it = userDatabase.find(email);
    if (it == userDatabase.end()) {
        cout << "Error: User not found!" << endl;
        return false;
    }
    
    User& user = it->second;
    string hashedPassword = hashPassword(password);
    
    if (user.getPassword() != hashedPassword) {
        cout << "Error: Incorrect password!" << endl;
        return false;
    }
    
    if (!user.getIsActive()) {
        cout << "Error: Account is deactivated!" << endl;
        return false;
    }
    
    currentUser = &user;
    cout << "Login successful! Welcome, " << user.getUsername() << "!" << endl;
    return true;
}

bool Authentication::logout() {
    if (currentUser) {
        cout << "Goodbye, " << currentUser->getUsername() << "!" << endl;
        currentUser = nullptr;
        return true;
    }
    return false;
}

User* Authentication::getCurrentUser() {
    return currentUser;
}

bool Authentication::isLoggedIn() {
    return currentUser != nullptr;
}

vector<User> Authentication::getAllUsers() {
    vector<User> users;
    for (const auto& pair : userDatabase) {
        users.push_back(pair.second);
    }
    return users;
}

bool Authentication::userExists(string email) {
    transform(email.begin(), email.end(), email.begin(), ::tolower);
    return userDatabase.find(email) != userDatabase.end();
}

void Authentication::displayAllUsers() {
    cout << "\n=== Registered Users ===" << endl;
    for (const auto& pair : userDatabase) {
        cout << "Email: " << pair.second.getEmail() 
             << " | Name: " << pair.second.getUsername()
             << " | Status: " << (pair.second.getIsActive() ? "Active" : "Inactive") << endl;
    }
    cout << "========================" << endl;
}
