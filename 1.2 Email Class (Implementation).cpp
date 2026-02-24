// src/Email.cpp
#include "../include/Email.h"

// Static counter for generating unique IDs
static int emailCounter = 1000;

Email::Email() : isRead(false), isStarred(false), isDraft(false) {
    emailId = generateEmailId();
    timestamp = getCurrentTimestamp();
}

Email::Email(string s, string r, string subj, string b) 
    : sender(s), receiver(r), subject(subj), body(b), 
      isRead(false), isStarred(false), isDraft(false) {
    emailId = generateEmailId();
    timestamp = getCurrentTimestamp();
}

string Email::generateEmailId() {
    return "EML" + to_string(++emailCounter);
}

string Email::getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    auto time = chrono::system_clock::to_time_t(now);
    auto ms = chrono::duration_cast<chrono::milliseconds>(
        now.time_since_epoch()) % 1000;
    
    stringstream ss;
    ss << put_time(localtime(&time), "%Y-%m-%d %H:%M:%S");
    ss << "." << setfill('0') << setw(3) << ms.count();
    return ss.str();
}

// Getters
string Email::getEmailId() const { return emailId; }
string Email::getSender() const { return sender; }
string Email::getReceiver() const { return receiver; }
string Email::getSubject() const { return subject; }
string Email::getBody() const { return body; }
string Email::getTimestamp() const { return timestamp; }
bool Email::getIsRead() const { return isRead; }
bool Email::getIsStarred() const { return isStarred; }
bool Email::getIsDraft() const { return isDraft; }
string Email::getReplyToId() const { return replyToId; }
string Email::getForwardToId() const { return forwardToId; }

// Setters
void Email::setEmailId(string id) { emailId = id; }
void Email::setSender(string s) { sender = s; }
void Email::setReceiver(string r) { receiver = r; }
void Email::setSubject(string subj) { subject = subj; }
void Email::setBody(string b) { body = b; }
void Email::setTimestamp(string ts) { timestamp = ts; }
void Email::setIsRead(bool status) { isRead = status; }
void Email::setIsStarred(bool status) { isStarred = status; }
void Email::setIsDraft(bool draft) { isDraft = draft; }
void Email::setReplyToId(string id) { replyToId = id; }
void Email::setForwardToId(string id) { forwardToId = id; }

// File operations
string Email::toFileString() const {
    return emailId + "|" + sender + "|" + receiver + "|" + 
           subject + "|" + body + "|" + timestamp + "|" +
           to_string(isRead) + "|" + to_string(isStarred) + "|" +
           to_string(isDraft) + "|" + replyToId + "|" + forwardToId;
}

Email Email::fromFileString(const string& line) {
    stringstream ss(line);
    string emailId, sender, receiver, subject, body, timestamp;
    string isReadStr, isStarredStr, isDraftStr, replyToId, forwardToId;
    
    getline(ss, emailId, '|');
    getline(ss, sender, '|');
    getline(ss, receiver, '|');
    getline(ss, subject, '|');
    getline(ss, body, '|');
    getline(ss, timestamp, '|');
    getline(ss, isReadStr, '|');
    getline(ss, isStarredStr, '|');
    getline(ss, isDraftStr, '|');
    getline(ss, replyToId, '|');
    getline(ss, forwardToId);
    
    Email email(emailId, sender, receiver, subject, body, timestamp,
                stoi(isReadStr), stoi(isStarredStr), stoi(isDraftStr),
                replyToId, forwardToId);
    return email;
}

void Email::displayEmail() const {
    cout << "\n========================================" << endl;
    cout << "Email ID: " << emailId << endl;
    cout << "From: " << sender << endl;
    cout << "To: " << receiver << endl;
    cout << "Subject: " << subject << endl;
    cout << "Time: " << timestamp << endl;
    cout << "Status: " << (isRead ? "Read" : "Unread") 
         << " | " << (isStarred ? "Starred" : "Not Starred") << endl;
    cout << "----------------------------------------" << endl;
    cout << body << endl;
    cout << "========================================" << endl;
}
