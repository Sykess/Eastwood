#include <string>
#include <iostream>
using namespace std;

class employee
{
    private:
        string name;
        int idNum;
        string dept;
        string pos;
    public:
        //constructors
        employee();
        employee(string,int);
        employee(string,int,string,string);
        //mutators
        bool setName(string);
        bool setIdNum(int);
        bool setDept(string);
        bool setPos(string);
        //accessors
        string getName();
        int getIdNum();
        string getDept();
        string getPos();
        //destructor
        ~employee();    
};
//////////////////////////////////////////////////////////////////////
///////////        MEMBER FUNCTION DEFINITIONS       /////////////////
//////////////////////////////////////////////////////////////////////
employee::employee()
{
    name = "";
    idNum = 0;
    dept = "";
    pos = "";
}
/////////////////////////////////////////////////////////////////////
employee::employee(string n, int id)
{
    name = n;
    idNum = id;
    dept = "";
    pos = "";
}
/////////////////////////////////////////////////////////////////////
employee::employee(string n, int id, string d, string p)
{
    name = n;
    idNum = id;
    dept = d;
    pos = p;
}
/////////////////////////////////////////////////////////////////////
bool employee::setName(string n)
{
    name = n;
}
//////////////////////////////////////////////////////////////////////
bool employee::setIdNum(int id)
{
    idNum = id;
}
/////////////////////////////////////////////////////////////////////        
bool employee::setDept(string d)
{
    dept = d;
}
/////////////////////////////////////////////////////////////////////
bool employee::setPos(string p)
{ 
    pos = p; 
}
//////////////////////////////////////////////////////////////////////
string employee::getName(){ return name; }
//////////////////////////////////////////////////////////////////////
int employee::getIdNum(){ return idNum; }
//////////////////////////////////////////////////////////////////////
string employee::getDept(){ return dept; }
//////////////////////////////////////////////////////////////////////
string employee::getPos() { return pos; }
//////////////////////////////////////////////////////////////////////
employee::~employee()
{
    cout << "Good-Bye " << name;
    system("pause");
}
////////// THANKS ALL FOLKS ////////////////

