#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

const int total = 100;
int roll_no[total];
string name[total];
string Class[total];
string course[total];
long long mobile_no[total];
int admission_year[total];
int size = 0;

void enter() {
    if (size < total) {
        cout << "Enter roll number: ";
        cin >> roll_no[size];
        cin.ignore(); // Ignore newline character in the input buffer
        cout << "Enter name: ";
        getline(cin, name[size]);
        cout << "Enter class: ";
        getline(cin, Class[size]);
        cout << "Enter course: ";
        getline(cin, course[size]);
        cout << "Enter mobile number: ";
        cin >> mobile_no[size];
        cout << "Enter admission year: ";
        cin >> admission_year[size];
        size++;
    } else {
        cout << "Array is full. Cannot enter more data." << endl;
    }
}

void show() {
    if (size == 0) {
        cout << "No data to show." << endl;
    } else {
        for (int i = 0; i < size; i++) {
            cout << "Roll number: " << roll_no[i] << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Class: " << Class[i] << endl;
            cout << "Course: " << course[i] << endl;
            cout << "Mobile number: " << mobile_no[i] << endl;
            cout << "Admission year: " << admission_year[i] << endl;
            cout << "-------------------------" << endl;
        }
    }
}

void search() {
    if (size == 0) {
        cout << "No data to search." << endl;
    } else {
        int target;
        cout << "Enter roll number to search: ";
        cin >> target;
        for (int i = 0; i < size; i++) {
            if (roll_no[i] == target) {
                cout << "Record found:" << endl;
                cout << "Roll number: " << roll_no[i] << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Class: " << Class[i] << endl;
                cout << "Course: " << course[i] << endl;
                cout << "Mobile number: " << mobile_no[i] << endl;
                cout << "Admission year: " << admission_year[i] << endl;
                return;
            }
        }
        cout << "Record not found." << endl;
    }
}

void update() {
    if (size == 0) {
        cout << "No data to update." << endl;
    } else {
        int target;
        cout << "Enter roll number to update: ";
        cin >> target;
        for (int i = 0; i < size; i++) {
            if (roll_no[i] == target) {
                cout << "Enter new name: ";
                cin.ignore(); // Ignore newline character in the input buffer
                getline(cin, name[i]);
                cout << "Enter new class: ";
                getline(cin, Class[i]);
                cout << "Enter new course: ";
                getline(cin, course[i]);
                cout << "Enter new mobile number: ";
                cin >> mobile_no[i];
                cout << "Record updated successfully." << endl;
                return;
            }
        }
        cout << "Record not found." << endl;
    }
}

void Delete() {
    if (size == 0) {
        cout << "No data to delete." << endl;
    } else {
        int target;
        cout << "Enter roll number to delete: ";
        cin >> target;
        for (int i = 0; i < size; i++) {
            if (roll_no[i] == target) {
                for (int j = i; j < size - 1; j++) {
                    roll_no[j] = roll_no[j + 1];
                    name[j] = name[j + 1];
                    Class[j] = Class[j + 1];
                    course[j] = course[j + 1];
                    mobile_no[j] = mobile_no[j + 1];
                    admission_year[j] = admission_year[j + 1];
                }
                size--;
                cout << "Record deleted successfully." << endl;
                return;
            }
        }
        cout << "Record not found." << endl;
    }
}

void writeToFile() {
    ofstream outputFile;
    outputFile.open("students.txt");

    if (outputFile.is_open()) {
        for (int i = 0; i < size; i++) {
            outputFile << roll_no[i] << "\n";
            outputFile << name[i] << "\n";
            outputFile << Class[i] << "\n";
            outputFile << course[i] << "\n";
            outputFile << mobile_no[i] << "\n";
            outputFile << admission_year[i] << "\n";
        }
        outputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void readFromFile() {
    ifstream inputFile;
    inputFile.open("students.txt");

    if (inputFile.is_open()) {
        while (inputFile >> roll_no[size]) {
            getline(inputFile >> ws, name[size]);
            getline(inputFile >> ws, Class[size]);
            getline(inputFile >> ws, course[size]);
            inputFile >> mobile_no[size];
            inputFile >> admission_year[size];
            size++;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
int main() {
    int choice;
    readFromFile();
    while (true) {
        cout << "1. Add student data" << endl;
        cout << "2. Show student data" << endl;
        cout << "3. Search student data" << endl;
        cout << "4. Update student data" << endl;
        cout << "5. Delete student data" << endl;
        cout << "6. Save student data to file" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        
        // Check if the input is valid
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        switch (choice) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                Delete();
                break;
            case 6:
                writeToFile();
                cout << "Data saved to file." << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
