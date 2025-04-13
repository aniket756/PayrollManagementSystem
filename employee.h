#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
  int empID;
  string name;
  double basicPay;
  double allowance;
  double deduction;

public:
  Employee(int id, string n, double basic, double allow, double deduct);
  double calculateNetSalary() const;
  void displayPayroll() const;
  int getID() const;
  string getName() const;
  double getBasicPay() const;
  double getAllowance() const;
  double getDeduction() const;
};

#endif // EMPLOYEE_H
