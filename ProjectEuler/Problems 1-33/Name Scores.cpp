
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	fstream file;
	string name;
	stringstream stream;
	
	
	
	file.open("names.txt");
	
	//stream << file.rdbuf();
	//string str = stream.str();
	
	vector<string> words;
	string token;
	
	while(getline(file, token, ','))
		words.push_back(token);
	
	sort(words.begin(), words.end());
	
	    int counter = 0;
    unsigned int grand_total = 0;

    //get total of each word and multiply with it's position
    for (std::vector<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        counter++;
        //copy word from token excluding " "
        string word((*it).begin() + 1, (*it).end() - 1);

        int sub_total = 0;
        for (string::iterator it = word.begin(); it != word.end(); it++)
        {
            //ascii value of A is 65
            //A is 1, B is 2, so *it - 64
            sub_total += *it - 64;
        }

        //grand total will be final answer
        grand_total += sub_total*counter; 
    }
	cout <<  grand_total;
	
}

