#include <stdio.h>
#include <string.h>

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    float balance;
};

// Function to transfer money between two accounts
void transferMoney(struct BankAccount* sender, struct BankAccount* receiver, float amount) {
    if (sender->balance >= amount) {
        sender->balance -= amount;
        receiver->balance += amount;
        printf("Amount transferred successfully!\n");
    } else {
        printf("Insufficient balance in the sender's account!\n");
    }
}

// Function to create a new account
void createAccount(struct BankAccount* account) {
    printf("Enter account number: ");
    scanf("%d", &(account->accountNumber));
    printf("Enter account holder name: ");
    scanf("%s", account->accountHolder);
    printf("Enter initial balance: ");
    scanf("%f", &(account->balance));
    printf("Account created successfully!\n");
}

// Function to check the balance of an account
void checkBalance(struct BankAccount* account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Balance: %.2f\n", account->balance);
}

// Function to handle login functionality
int login() {
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Add your login logic here
    // For simplicity, let's assume the login is successful if the username and password are not empty
    if (strlen(username) > 0 && strlen(password) > 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}

int main() {
    struct BankAccount account1, account2;
    int loggedIn = login();

    if (loggedIn) {
        printf("Login successful!\n");

        // Example usage of the functions
        createAccount(&account1);
        createAccount(&account2);

        transferMoney(&account1, &account2, 100.0);

        checkBalance(&account1);
        checkBalance(&account2);
    } else {
        printf("Login failed!\n");
    }

    return 0;
}