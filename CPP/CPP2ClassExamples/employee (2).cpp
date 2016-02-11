#include <string>
#include <cstring>
#include <iostream>

using namespace std;


//BASE CLASS
class Employee
{
    private:
        string name;
        int emp_num;
        char hire_date[11];
    public:
        Employee();
        Employee(string, int, char []);
        bool setName(string);
        bool setEmpNum(int);
        bool setHireDate(char []);
        string getName();
        int getEmpNum();
        char * getHireDate();  
};
//////////////////////////////////////////////////////////////////////
// DERIVED CLASS
class ProductionWorker : public Employee
{
    private:
        int shift;
        double rate;
    public:
        ProductionWorker();
        ProductionWorker(string, int, char [], int, double);
        bool setShift(int);
        bool setRate(double);
        int getShift();
        double getRate();
};
//////////////////////////////////////////////////////////////////
ProductionWorker::ProductionWorker() : Employee()
{
    shift = 0;
    rate = 0.0;
}
ProductionWorker::ProductionWorker(string n, int num, char d[], int s, double r)
                            : Employee(n, num, d)
{
    shift = s; 
    rate = r;
}
bool ProductionWorker::setShift(int s)
{
    shift = s;
    return true;
}
bool ProductionWorker::setRate(double r)
{ 
    rate = r; 
    return true;
}
int ProductionWorker::getShift() { return shift; }
double ProductionWorker::getRate() { return rate; }
//////////////////////////////////////////////////////////////
Employee::Employee()
{
    name = "";
    emp_num = 0;
    hire_date[0] = '\0';
}

Employee::Employee(string n, int num, char d[])
{
    name = n;
    emp_num = num;
    strcpy(hire_date,d);
}

bool Employee::setName(string n)
{
    name = n;
    return true;
}

bool Employee::setEmpNum(int num)
{
    emp_num = num;
    return true;
}

bool Employee::setHireDate(char d[])
{
    strcpy(hire_date, d);
    return true;
}

string Employee::getName() { return name; }

int Employee::getEmpNum() { return emp_num; }

char * Employee::getHireDate() { return hire_date; }

//////////////////////////////////////////////////////////////////
int main()
{
    ProductionWorker none;
    ProductionWorker me("Greg", 123, "4/23/2014", 1, 23.87);
    
    cout << me.getName() << " " << me.getEmpNum() << " " << me.getHireDate()
         << " " << me.getShift() << " " << me.getRate() << endl << endl;
         
    system("pause");
}
