#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Esraa Mabrouk
typedef struct {
    char username[20];
    char password[20];
    bool active;  // New flag to indicate if the user is active
} User;

User users[100];
int totalUsers = 0;

void registerUser() {
    if (totalUsers >= 100) {
        printf("Maximum user limit reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[totalUsers].username);

    printf("Enter password: ");
    scanf("%s", users[totalUsers].password);

    printf("Set user as active (true/1 or false/0): ");
    scanf("%d", &users[totalUsers].active);

    totalUsers++;
    printf("User registered successfully!\n");
}

bool loginUser() {
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            users[i].active) {  // Check if the user is active
            printf("Login successful! Welcome, %s.\n", username);
            return true;
        }
    }

    printf("Login failed.\n");
    return false;
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
