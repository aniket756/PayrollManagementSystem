#include "PayrollSystem.h"
#include <iostream>

int main() {
  PayrollSystem payroll;
  int choice;

  do {
    cout << "\n--- Payroll Management System ---\n";
    cout << "1. Add Employee\n";
    cout << "2. Display Payroll\n";
    cout << "3. Search Employee by ID\n";
    cout << "4. Delete Employee by ID\n";
    cout << "5. Modify Employee by ID\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      payroll.addEmployee();
      break;
    case 2:
      payroll.displayPayroll();
      break;
    case 3:
      payroll.searchEmployeeByID();
      break;
    case 4:
      payroll.deleteEmployeeByID();
      break;
    case 5:
      payroll.modifyEmployeeByID();
      break;
    case 6:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice!\n";
    }
  } while (choice != 6);

  return 0;
}
