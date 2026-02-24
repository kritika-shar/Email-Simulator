// include/ComposeEmail.h
#ifndef COMPOSE_EMAIL_H
#define COMPOSE_EMAIL_H

#include <iostream>
#include <string>
#include "../include/Email.h"
#include "../include/Authentication.h"
using namespace std;

class ComposeEmail {
private:
    Authentication& auth;
    
public:
    ComposeEmail(Authentication& authRef);
    
    Email* composeNewEmail();
    Email* composeReplyEmail(Email* originalEmail);
    Email* composeForwardEmail(Email* originalEmail);
    Email* saveAsDraft(Email* email);
    void displayEmailEditor(Email* email);
};

#endif
