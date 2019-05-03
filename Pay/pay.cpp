#include <iostream>
#include <string>
using namespace std;

class Payslip {
    private:
      string name;
      string paygrade;
      float basicsalary;
      int overtimehours;
      float overtimepay;
      float grosspay;
      float netpay;
      float withholdingtax;
      float taxrate;

      float sss = 500;
      float pagibig = 200;
      float philhealth = 100;
      
       
    public:
       // mutators
       void setName(string value) {
          name = value;
       }
       void setPayGrade(string value) {
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
       void setTaxRate(float value) {
          taxrate = value;
       }
       void setWithholdingTax(float value) {
          withholdingtax = value;
       }

       // accessors
       string getName() {
          return name;
       }
       string getPayGrade() {
          return paygrade;
       }
       float getBasicSalary() {
          return basicsalary;
       }
       int getOvertimeHours() {
          return overtimehours;
       }
       float getOvertimePay() {
          overtimepay = getOvertimeHours() * (getBasicSalary()*0.01);
          return overtimepay;
       }
       float getGrossPay() {
          grosspay = getBasicSalary() + getOvertimePay();
          return grosspay;
       }
       float getNetPay() {
          netpay = getGrossPay() - getWithholdingTax() - (sss+pagibig+philhealth);
          return netpay;
       }
       float getTaxRate() {
          return taxrate;
       }
       float getWithholdingTax() {
          withholdingtax = getGrossPay() * (getTaxRate()*0.100*0.100);
          return withholdingtax;
       }

       // custom methods
       void determinePayGradeAndTaxRate() {
          if(getBasicSalary() >= 10000 && getBasicSalary() < 15000) {
             setPayGrade("A");
             setTaxRate(10);
          } else if(getBasicSalary() >= 15000 && getBasicSalary() < 20000) {
             setPayGrade("B");
             setTaxRate(10);
          } else if(getBasicSalary() >= 20000 && getBasicSalary() < 25000) {
             setPayGrade("A");
             setTaxRate(15);
          } else if(getBasicSalary() >= 25000 && getBasicSalary() < 30000) {
             setPayGrade("B");
             setTaxRate(15);
          } else if(getBasicSalary() >= 30000 && getBasicSalary() < 35000) {
             setPayGrade("A");
             setTaxRate(20);
          } else if(getBasicSalary() >= 35000 && getBasicSalary() < 40000) {
             setPayGrade("B");
             setTaxRate(20);
          } else if(getBasicSalary() >= 40000 && getBasicSalary() < 45000) {
             setPayGrade("A");
             setTaxRate(25);
          } else if(getBasicSalary() >= 45000 && getBasicSalary() < 50000) {
             setPayGrade("B");
             setTaxRate(25);
          } else if(getBasicSalary() >= 50000 && getBasicSalary() < 55000) {
             setPayGrade("A");
             setTaxRate(30);
          } else if(getBasicSalary() >= 55000 && getBasicSalary() < 60000) {
             setPayGrade("B");
             setTaxRate(30);
          }
       }
       void computePay() {
          determinePayGradeAndTaxRate();
          cout << "\n\nEmployee Name: " << getName() << endl;
          cout << "Basic Salary: " << getBasicSalary() << endl;
          cout << "Pay Grade: " << getPayGrade() << endl;
          cout << "No. of OT Hours: " << getOvertimeHours() << endl;
          cout << "OT Pay: " << getOvertimePay() << endl;
          cout << "Gross Pay: " << getGrossPay() << endl;
          cout << "Withholding Tax: " << getWithholdingTax() << endl;
          cout << "Net Pay: " << getNetPay() << endl;
       }
       
};

 int main() {
      Payslip payslip;
      string name;
      float paygrade;
      float basicsalary;
      int overtimehours;
      float overtimepay;
      float grosspay;
      float netpay;
      float withholdingtax;
      bool inputisright = false;

      while(!inputisright) {

            cout << "Your Name: ";
            getline(cin, name);

            payslip.setName(name);

            cout << "Basic Salary: ";
            cin >> basicsalary;

            payslip.setBasicSalary(basicsalary);

            cout << "Number of Overtime: ";
            cin >> overtimehours;

            payslip.setOvertimeHours(overtimehours);

            if(basicsalary > 10000 && overtimehours > 0 && !name.empty()) {
               inputisright = true;
               payslip.computePay();
            } else {
               if(name.empty()) {
                  cout << "Name cannot be empty\n";
               }

               if(basicsalary < 10000) {
                  cout << "Basic salary must be higher than 10,000\n";
               }

               if(overtimehours == 0) {
                  cout << "Overtime hours must be greater than 0\n";
               }
            }

            cin.ignore();

         }

      return 0;
 }