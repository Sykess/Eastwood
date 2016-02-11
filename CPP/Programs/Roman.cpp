#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;


int main()
{
	fstream file("p089_roman.txt", ios::in);
	string str = "", temp = "";
	string pattern = "DCCCC|LXXXX|VIIII|CCCC|XXXX|IIII";
	string replace = "kk";
	int total = 0;
	string orig = "", dup = "";
	
	regex r("DCCCC|LXXXX|VIIII|CCCC|XXXX|IIII");
	//temp += str;
	while(file.good())
	{
		getline(file, temp);
		//str+= temp;
		str = regex_replace(temp, r, replace);
		if(str.size() != temp.size())
			total += temp.size() - str.size();
		orig += temp;
		dup += str;
	}
	file.close();
	cout << total;
	cout << endl << orig.size() - dup.size();
	//string str2 = regex_replace(str, r, replace);
	
	//cout << str.size() - str2.size();
	//cout << endl << str2 << "**";
	
}
