/*
 Program Name: CourseGrade.cpp
 Author: Nathan Caron
 Assignment #4
 Date: 3/5/14
 Purpose: Take in student names, id numbers, and 3 test scores and send out
 the average test score along with the letter grade equivalent.
*/

#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;

struct student
{
    char name[15];
    int idnum;
    double test[3]; // cap at 3 tests
    double ave;
    char letter_grade;
};

void loadStudent(student *s, int size);
void letterConvert(student *s, int size);
void displayChart(student *s, int size);

int main()
{
    int qty;  // for number of students
    student *ptr;
    
    do{
    cout << "\nHow many students are there? (1-30) ";
    cin >> qty;
    
    }while(qty < 1 || qty > 30);
    
    ptr = new student[qty];
    

    loadStudent(ptr, qty);
    letterConvert(ptr, qty);
    displayChart(ptr, qty);
    
    
    delete[] ptr;
    
    return 0;
}

void loadStudent(student *s, int size)
{
    
    for(int x=0; x< size; x++)
    {
        cin.ignore(1000, '\n');
        do{
            cout << "Enter the name of student # " << x + 1 << " : ";
            cin.getline(s[x].name, 30, '\n');
        }while(s[x].name[0] == '\0');

        do{
            cout << "Enter the ID number of student # " << x+1 << " : ";
            cin >> s[x].idnum;
          
        }while(s[x].idnum < 0 || s[x].idnum == '\n'); // If you just hit enter
                                                      // for some reason it
                                                      // doesn't repeat the 
                                                      // cout but will still
                                                      // correctly read next
                                                      // input.
        
        for(int t=0; t<3; t++)
        {
            do{
                cout << "Enter " << s[x].name << "'s number grade for "
                     << "test # " << t + 1 << " : ";
                cin >> s[x].test[t];
            }while(s[x].test[t] < 0);
        }
    }
    
}

void letterConvert(student *s, int size)
{
    int grade;
    for(int x=0; x < size; x++)
    {
        s[x].ave = s[x].test[0] + s[x].test[1] + s[x].test[2];
        s[x].ave /= 3;
    
        if(s[x].ave > 90){
            s[x].letter_grade = 'A';
        }else if(s[x].ave <= 90 && s[x].ave > 80){
            s[x].letter_grade = 'B';
        }else if(s[x].ave <= 80 && s[x].ave > 70){
            s[x].letter_grade = 'C';
        }else if(s[x].ave <= 70 && s[x].ave > 60){
            s[x].letter_grade = 'D';
        }else if(s[x].ave <= 60){
            s[x].letter_grade = 'F';
        }
    }
}

void displayChart(student *s, int size)
{
    cout << fixed << setprecision(0);
    cout << "\nName \t\tID# \t Average test score \t Letter grade "
         << "\n===========================================================\n";
    for(int x = 0; x < size; x++)
    {
        cout << setw(15) << left << s[x].name << setw(15) << s[x].idnum
             << setw(14) << s[x].ave << "\t\t" << setw(30) << s[x].letter_grade
             << endl;
    }
    
}
