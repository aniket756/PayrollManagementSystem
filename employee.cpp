#include "Employee.h"
#include <iomanip>
#include <iostream>


Employee::Employee(int id, string n, double basic, double allow, double deduct)
    : empID(id), name(n), basicPay(basic), allowance(allow), deduction(deduct) {
}

double Employee::calculateNetSalary() const {
  return basicPay + allowance - deduction;
}

void Employee::displayPayroll() const {
  cout << left << setw(10) << empID << setw(20) << name << setw(12) << basicPay
       << setw(12) << allowance << setw(12) << deduction << setw(12)
       << calculateNetSalary() << endl;
}

int Employee::getID() const { return empID; }
string Employee::getName() const { return name; }
double Employee::getBasicPay() const { return basicPay; }
double Employee::getAllowance() const { return allowance; }
double Employee::getDeduction() const { return deduction; }
