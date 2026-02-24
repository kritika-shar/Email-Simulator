# 📧 Email Simulator Project

##  Project Overview

The **Email Simulator** is a console-based application that simulates the core functionalities of an email system such as composing, sending, receiving, and managing emails.  
It is designed to demonstrate the practical use of **Data Structures, Object-Oriented Programming, and File Handling** concepts.

This project does **not send real emails** but mimics the **working flow of an email client** like Gmail or Outlook.

---

##  Objectives

- Simulate real-world email operations  
- Understand client-side email workflow  
- Apply Data Structures in real applications  
- Practice modular and object-oriented design  

---

##  Features

1. User Registration & Login  
2. Compose Email  
3. Send & Receive Emails  
4. Inbox Management  
5. Sent Mailbox  
6. Trash / Delete Emails  
7. Persistent Storage using Files  
8. Multiple User Support  

---

##  Technologies Used

| Technology | Purpose |
|----------|---------|
|  C++ | Core programming |
|  File Handling | Persistent storage |
|  OOP Concepts | Modular design |
|  Data Structures | Efficient email management |

---

##  Data Structures Used

| Feature | Data Structure | Reason |
|-------|---------------|--------|
|  Inbox | Queue | FIFO email delivery |
|  Sent Mail | Linked List | Dynamic storage |
|  Trash | Stack | Undo delete option |
|  Users | File / Map | Fast lookup |

---

##  System Architecture

```text
User Interface
      ↓
Authentication Module
      ↓
Email Processing Module
      ↓
Mailbox Manager
      ↓
File Storage System
