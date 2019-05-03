#include <iostream>
using namespace std;

class Payslip {
    private:
       string name;
       float paygrade;
       float basicsalary;
       int overtimehours;
       float overtimepay;
       float grosspay;
       float netpay;
       float withholdingtax;
       
    public:
       // mutators
       void setName(string value) {
          name = value;
       }
       void setPayGrade(float value) {
          paygrade = value;
       }
       void setBasicSalary(float value) {
          basicsalary = value;
       }
       void setOvertimeHours(int value) {
          overtimehours = value;
       }
       void setOvertimePay(float value) {
          overtimepay = value;
       }
       void setGrossPay(float value) {
          grosspay = value;
       }
       void setNetPay(float value) {
          netpay = value;
       }
       void setWithholdingTax(float value) {
          withholdingtax = value;
       }

       // accessors
       string getName() {
          return name;
       }
       float getPayGrade() {
          return paygrade;
       }
       float getBasicSalary() {
          return basicsalary;
       }
       int getOvertimeHours() {
          return overtimehours;
       }
       float getOvertimePay() {
          return overtimepay;
       }
       float getGrossPay() {
          return grosspay;
       }
       float getNetPay() {
          return netpay;
       }
       float getWithholdingTax() {
          return withholdingtax;
       }

       // custom methods
       string determinePayGradeAndTaxRate() {
          return name;
       }
       float computePay() {
          return withholdingtax;
       }
       
};

class Employee {
   private:
       Payslip payslip;
       string name;
       float paygrade;
       float basicsalary;
       int overtimehours;
       float overtimepay;
       float grosspay;
       float netpay;
       float withholdingtax;

   public:
      Employee() {
         cout << "You entered " << endl;
         cin >> name;

         payslip.setName(name);
      }
};

 int main() {
      Employee employee;
      Payslip payslip;
      
      cout << payslip.getName << endl;

      return 0;
 }