#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



int long function(int a)
{   ifstream myfile;
    char z;
    long int number[999];
   char array[999];
	myfile.open("Problem8.txt");
	int i=0;
	 while(myfile.get(z))
	    {//~ {  cout <<z;
			if (z!='\n')
			     {
			       array[i]=z;
			       number[i]=array[i]-'0';// convert char to int
			      }
			 else continue;
		 i++;
	      
	      
	         
	      }
	      
	      return number[a];
	    myfile.close();
 
return 0;
}


int main () 
{
 long long int Res=1;
	for(int i=0; i<=987; i++)
	{   long long int A=1;
		for(int j=i; j<=i+12; j++)
		{A=A*function(j);
	    }
	    //~ cout<<A<<"\n";
	  Res=max(Res,A);
	
    }
			
			
cout<<Res<<"\n";

	
}
