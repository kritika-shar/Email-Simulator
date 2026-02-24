// src/ComposeEmail.cpp
#include "../include/ComposeEmail.h"
#include <limits>

ComposeEmail::ComposeEmail(Authentication& authRef) : auth(authRef) {}

Email* ComposeEmail::composeNewEmail() {
    Email* email = new Email();
    
    cout << "\n=== Compose New Email ===" << endl;
    
    // Sender is automatically set to current user
    if (auth.isLoggedIn()) {
        email->setSender(auth.getCurrentUser()->getEmail());
    } else {
        cout << "Error: You must be logged in to compose emails!" << endl;
        delete email;
        return nullptr;
    }
    
    // Get receiver email
    cout << "To: ";
    getline(cin, email->setReceiver(email->getReceiver()));
    string receiver;
    getline(cin, receiver);
    email->setReceiver(receiver);
    
    // Validate receiver
    if (!auth.userExists(receiver)) {
        cout << "Warning: Recipient email is not registered in the system." << endl;
        cout << "Do you want to send anyway? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice != 'y' && choice != 'Y') {
            delete email;
            return nullptr;
        }
    }
    
    // Get subject
    cout << "Subject: ";
    getline(cin, email->setSubject(email->getSubject()));
    string subject;
    getline(cin, subject);
    email->setSubject