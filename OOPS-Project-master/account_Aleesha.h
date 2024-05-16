#ifndef ACCOUNT_ALEESHA_H
#define ACCOUNT_ALEESHA_H

#include <iostream>
#include <string>
#include <unordered_map>

class Account {
private:
    struct UserInfo {
        std::string password;
        std::string email;
    };
    std::unordered_map<std::string, UserInfo> accounts; // stores username and user info
    std::string current_username;

public:
    Account() {
        // Constructor
        // Initialize with one default account
        accounts["user"] = {"password", "user@example.com"};
    }

    void create_new_account() {
        std::string username, password, email;
        std::cout << "Enter new username: ";
        std::getline(std::cin, username);
        if (accounts.find(username) != accounts.end()) {
            std::cout << "Username already exists. Try another one.\n";
            return;
        }
        std::cout << "Enter new password: ";
        std::getline(std::cin, password);
        std::cout << "Enter your email: ";
        std::getline(std::cin, email);
        accounts[username] = {password, email};
        std::cout << "Account created successfully.\n";
    }

    void existing_account() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::getline(std::cin, username);
        std::cout << "Enter password: ";
        std::getline(std::cin, password);
        if (accounts.find(username) != accounts.end() && accounts[username].password == password) {
            std::cout << "Login successful.\n";
            current_username = username;
        } else {
            std::cout << "Invalid username or password.\n";
        }
    }

    void forgetpassword() {
        if (current_username.empty()) {
            std::cout << "No user is currently logged in.\n";
            return;
        }
        std::string new_password;
        std::cout << "Enter new password: ";
        std::getline(std::cin, new_password);
        accounts[current_username].password = new_password;
        std::cout << "Password changed successfully.\n";
    }

    bool verify_email(const std::string& email) {
        if (current_username.empty()) {
            std::cout << "No user is currently logged in.\n";
            return false;
        }
        return accounts[current_username].email == email;
    }
};

#endif // ACCOUNT_ALEESHA_H
