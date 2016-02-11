#include "counter_object.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int main()
{
     char ch;
     counter lil_red;
     double total;
     
     do{
            cout << "\n(p)ennie\n(n)ickle\n(d)ime\n(q)uarter\n(r)eset\n\n"
                 << "(1) to Display  (2) to Quit";
            ch = getch();  
        
            switch(ch)
            {
                case 'p': lil_red.addPenny();
                          break;
                case 'd': lil_red.addDime();
                          break;
                case 'n': lil_red.addNickle();
                          break;
                case 'q': lil_red.addQuarter();
                          break;
                case 'r': lil_red.resetCounter();
                           break;
                case '1': if(lil_red.getTotal(total))
                                cout << "\n\nThe current total is "
                                     << setprecision(2) << fixed
                                     << (total < 10 ? "0" : "")
                                     << total;
                          else
                          {
                                cout << "\n\nThe current total is "
                                     << setprecision(2) << fixed
                                     << (total < 10 ? "0" : "")
                                     << total;
                                cout << "  ERROR";
                          }
                          break;
                case '2': return 0;
            };
    }while(true); 
       
    return 0;
}



















