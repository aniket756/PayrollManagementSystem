#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include "Employee.h"
#include <string>
#include <vector>


class PayrollSystem {
private:
  std::vector<Employee> employees;
  const std::string filename = "employees.txt";

  void saveToFile() const;
  void loadFromFile();

public:
  PayrollSystem();
  void addEmployee();
  void displayPayroll() const;
  void searchEmployeeByID() const;
  void deleteEmployeeByID();
  void modifyEmployeeByID();
};

#endif // PAYROLLSYSTEM_H
