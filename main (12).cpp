#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;

    cout << "\n=== User Registration ===\n";
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, fileUser, filePass;
    cout << "\n=== User Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    bool success = false;

    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            success = true;
            break;
        }
    }
    file.close();

    if (success) {
        cout << "Login successful! Welcome, " << username << "!\n";
        return true;
    } else {
        cout << "Login failed! Invalid username or password.\n";
        return false;
    }
}

int main() {
    int choice;

    cout << "=============================\n";
    cout << "      LOGIN SYSTEM MENU      \n";
    cout << "=============================\n";

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}