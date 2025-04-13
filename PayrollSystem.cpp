#include "PayrollSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <exception>
#include<iomanip>

using namespace std;

void PayrollSystem::saveToFile() const {
    ofstream outFile(filename);
    for (const auto& emp : employees) {
        outFile << emp.getID() << ','
                << emp.getName() << ','
                << emp.getBasicPay() << ','
                << emp.getAllowance() << ','
                << emp.getDeduction() << '\n';
    }
}

void PayrollSystem::loadFromFile() {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Warning: Could not open " << filename << ". Starting with empty records.\n";
        return;
    }

    employees.clear();
    int id;
    string name;
    double basic, allow, deduct;
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string field;
        try {
            getline(ss, field, ','); id = stoi(field);
            getline(ss, field, ','); name = field;
            getline(ss, field, ','); basic = stod(field);
            getline(ss, field, ','); allow = stod(field);
            getline(ss, field, ','); deduct = stod(field);
            employees.emplace_back(id, name, basic, allow, deduct);
        } catch (exception& e) {
            cerr << "Error parsing line: " << line << ". Skipping.\n";
        }
    }
}

PayrollSystem::PayrollSystem() {
    loadFromFile();
}

void PayrollSystem::addEmployee() {
    int id;
    string name;
    double basic, allow, deduct;

    cout << "Enter Employee ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid Employee ID: ";
    }

    // Check if employee ID already exists
    auto exists = find_if(employees.begin(), employees.end(),
                          [id](const Employee& e) { return e.getID() == id; });

    if (exists != employees.end()) {
        cout << "Employee with ID " << id << " already exists. Cannot add duplicate.\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Basic Pay: ";
    while (!(cin >> basic)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid Basic Pay: ";
    }
    cout << "Enter Allowance: ";
    while (!(cin >> allow)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid Allowance: ";
    }
    cout << "Enter Deduction: ";
    while (!(cin >> deduct)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid Deduction: ";
    }

    employees.emplace_back(id, name, basic, allow, deduct);
    saveToFile();
    cout << "Employee added successfully.\n";
}

void PayrollSystem::displayPayroll() const {
    if (employees.empty()) {
        cout << "No employees found.\n";
        return;
    }

    cout << left << setw(10) << "EmpID"
         << setw(20) << "Name"
         << setw(12) << "Basic Pay"
         << setw(12) << "Allowance"
         << setw(12) << "Deduction"
         << setw(12) << "Net Salary" << endl;
    cout << string(78, '-') << endl;

    // Sort employees by ID (or name if you prefer)
    vector<Employee> sortedEmployees = employees;
    sort(sortedEmployees.begin(), sortedEmployees.end(),
         [](const Employee& a, const Employee& b) { return a.getID() < b.getID(); });

    for (const auto& emp : sortedEmployees) {
        emp.displayPayroll();
    }
}

void PayrollSystem::searchEmployeeByID() const {
    if (employees.empty()) {
        cout << "No employees found.\n";
        return;
    }

    int searchID;
    cout << "Enter Employee ID to search: ";
    cin >> searchID;

    for (const auto& emp : employees) {
        if (emp.getID() == searchID) {
            cout << "\nEmployee Found:\n";
            cout << left << setw(10) << "EmpID"
                 << setw(20) << "Name"
                 << setw(12) << "Basic Pay"
                 << setw(12) << "Allowance"
                 << setw(12) << "Deduction"
                 << setw(12) << "Net Salary" << endl;
            cout << string(78, '-') << endl;
            emp.displayPayroll();
            return;
        }
    }

    cout << "Employee with ID " << searchID << " not found.\n";
}

void PayrollSystem::deleteEmployeeByID() {
    if (employees.empty()) {
        cout << "No employees to delete.\n";
        return;
    }

    int deleteID;
    cout << "Enter Employee ID to delete: ";
    cin >> deleteID;

    auto it = remove_if(employees.begin(), employees.end(),
                        [deleteID](const Employee& emp) {
                            return emp.getID() == deleteID;
                        });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        saveToFile();
        cout << "Employee with ID " << deleteID << " deleted successfully.\n";
    } else {
        cout << "Employee with ID " << deleteID << " not found.\n";
    }
}

void PayrollSystem::modifyEmployeeByID() {
    if (employees.empty()) {
        cout << "No employees to modify.\n";
        return;
    }

    int modifyID;
    cout << "Enter Employee ID to modify: ";
    cin >> modifyID;

    for (auto& emp : employees) {
        if (emp.getID() == modifyID) {
            string newName;
            double newBasic, newAllow, newDeduct;

            cin.ignore();

            cout << "Enter new name [" << emp.getName() << "]: ";
            getline(cin, newName);
            if (newName.empty()) newName = emp.getName();

            cout << "Enter new basic pay [" << emp.getBasicPay() << "]: ";
            string input;
            getline(cin, input);
            newBasic = input.empty() ? emp.getBasicPay() : stod(input);

            cout << "Enter new allowance [" << emp.getAllowance() << "]: ";
            getline(cin, input);
            newAllow = input.empty() ? emp.getAllowance() : stod(input);

            cout << "Enter new deduction [" << emp.getDeduction() << "]: ";
            getline(cin, input);
            newDeduct = input.empty() ? emp.getDeduction() : stod(input);

            emp = Employee(modifyID, newName, newBasic, newAllow, newDeduct);
            saveToFile();
            cout << "Employee updated successfully.\n";
            return;
        }
    }

    cout << "Employee with ID " << modifyID << " not found.\n";
}
