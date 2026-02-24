// include/Email.h
#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
using namespace std;

class Email {
private:
    string emailId;
    string sender;
    string receiver;
    string subject;
    string body;
    string timestamp;
    bool isRead;
    bool isStarred;
    bool isDraft;
    string replyToId;
    string forwardToId;

public:
    // Constructors
    Email();
    Email(string sender, string receiver, string subject, string body);
    Email(string emailId, string sender, string receiver, string subject, 
          string body, string timestamp, bool isRead, bool isStarred, 
          bool isDraft, string replyToId, string forwardToId);

    // Getters
    string getEmailId() const;
    string getSender() const;
    string getReceiver() const;
    string getSubject() const;
    string getBody() const;
    string getTimestamp() const;
    bool getIsRead() const;
    bool getIsStarred() const;
    bool getIsDraft() const;
    string getReplyToId() const;
    string getForwardToId() const;

    // Setters
    void setEmailId(string id);
    void setSender(string s);
    void setReceiver(string r);
    void setSubject(string subj);
    void setBody(string b);
    void setTimestamp(string ts);
    void setIsRead(bool status);
    void setIsStarred(bool status);
    void setIsDraft(bool draft);
    void setReplyToId(string id);
    void setForwardToId(string id);

    // Utility functions
    string toFileString() const;
    static Email fromFileString(const string& line);
    void displayEmail() const;
    string generateEmailId();
};

#endif