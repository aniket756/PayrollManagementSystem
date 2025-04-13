# Console-Based Payroll Management System

This is a **console-based payroll management system** built in C++ that allows the addition, modification, deletion, and display of employee payroll information. The system supports:

- Employee ID, name, basic pay, allowances, and deductions.
- Payroll report generation with calculations for net salary.
- File storage (employee details are saved in a text file).
- Robust handling of edge cases like missing/corrupted files, invalid input, and duplicate IDs.
- Sorting employee records by ID or name.
- Export of payroll reports to CSV format.

## Features

- **Add Employee**: Add a new employee by entering their ID, name, basic pay, allowances, and deductions.
- **Display Payroll**: View the payroll details of all employees in a sorted format (by ID or name).
- **Search Employee by ID**: Search for an employee's details using their ID.
- **Delete Employee by ID**: Remove an employee from the system using their ID.
- **Modify Employee by ID**: Update employee details like name, pay, allowances, and deductions.
- **Export to CSV**: Generate and export payroll reports in CSV format, including totals and summaries.
- **Error Handling**: The program includes error handling for common edge cases like missing/corrupted files, invalid input types, and duplicate employee IDs.

## How to Compile and Run

To compile and run the program, you can use the following commands:

```bash
g++ -o payroll main.cpp Employee.cpp PayrollSystem.cpp
./payroll
