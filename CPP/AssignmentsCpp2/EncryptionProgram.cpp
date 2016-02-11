/*
 Program Name: EncryptionProgram.cpp
 Author: Nathan Caron
 Assignment #5 Bonus
 Date: 3/26/14
 Purpose: Encrypt and decrypt data.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

void encryptFile(fstream &fileE, fstream &fileD);
void decryptFile(fstream &fileE, fstream &fileD);
void displayMenu();

int main()
{
	char choice;
	string fileName;
	
	fstream encrypt;
	fstream decrypt;
	
	do
	{
		displayMenu();
		cin >> choice;
	while (toupper(choice) < 'A' || toupper(choice) > 'C') 
     {
        cout << "Incorrect entry, please make a choice "
             << "in the range of A through C:";
        cin >> choice;
   	 }
   	 
   	 switch(choice)
   	 {
   	 	case 'a':
   	 	case 'A': cout << "\nEnter the name of the file you want to encrypt: ";
   	 			  cin >> fileName;
   	 			  encrypt.open(fileName.c_str(), ios::in);
   	 			  if(encrypt)
   	 			  {
   	 			  	cout << "\nEnter the name of the file for output: "
						 << "\n(must be different than first file for correct results)";
   	 			  	cin >> fileName;
   	 			  	decrypt.open(fileName.c_str(), ios::out);
   	 			  	if(decrypt)
   	 			  	{
   	 			  		encryptFile(encrypt, decrypt);
   	 			  		encrypt.close();
   	 			  		decrypt.close();
   	 			  	}
   	 			  	 else
   	 			  	 {
   	 			  	 	cout << "\nError, file 2 could not be opened! ";
   	 			  	 	encrypt.close();
   	 			  	 }
   	 			  }
   	 			  else
   	 			  cout << "\nError, file could not be opened! ";
   	 			  
   	 	break;
   	 	
   	 	case 'b':
   	 	case 'B': cout << "\nEnter the name of the file you want to decrypt: ";
   	 			  cin >> fileName;
   	 			  decrypt.open(fileName.c_str(), ios::in);
   	 			  if(decrypt)
   	 			  {
   	 			  	cout << "\nEnter the name of file to save the encrypted data: "
   	 			  	     << "\n(must be different than first file for correct results)";
   	 			  	cin >> fileName;
   	 			  	encrypt.open(fileName.c_str(), ios::out);
   	 			  	if(encrypt)
   	 			  	{
   	 			  		decryptFile(encrypt, decrypt);
   	 			  		decrypt.close();
   	 			  		encrypt.close();
   	 			  	}
   	 			  	else
   	 			  	{
   	 			  		cout << "\nError, file 2 could not be opened! ";
   	 			  		decrypt.close();
   	 			  	}
   	 			  }
   	 			  else
   	 			  cout << "\nError, file could not be opened! ";
   	 	
   	 	break;
   	 	
   	 }
   	 
	
	}while(toupper(choice) != 'C');
	
	
	
	return 0;	
}


void encryptFile(fstream &fileE, fstream &fileD)
{
	char ch;
	
	if(fileE)
	{
		fileE.get(ch);
		
		while(fileE)
		{
		
			fileD.put(ch+12);
			
			fileE.get(ch);
		}
	}
	
	cout << "\nEncryption complete! \n";
}

void decryptFile(fstream &fileE, fstream &fileD)
{
	char ch;
	
	if(fileD)
	{
		fileD.get(ch);
		
		while(fileD)
		{
			
			fileE.put(ch-12);
			
			fileD.get(ch);
		}
	}
	
	cout << "\nDecryption complete! \n";
}


void displayMenu()
{
    cout << "\nMenu" << "\n";
    cout << "=====================\n";
    cout << "\t a) Encrypt file\n";
    cout << "\t b) Decrypt file\n";
    cout << "\t c) Exit program\n";
    cout << "Enter your choice: ";
}
