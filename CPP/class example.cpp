#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;

struct parts
{
    char desc[10];
    int qty;
};

void initBins(parts *b, int size);
void displayBins(const parts *b, int size);

int main()
{
    int q;
    parts *bin; // pointer to struct
    
    do{
        cout << "\nHow many bins do you need (2-10): ";
        cin >> q;
    }while((q<2 || q>10));
    
    bin = new parts[q];
    initBins(bin, q);
    displayBins(bin, q);
    
    
    
    delete []bin;
    system("pause");  
    return 0;
}

////////////////////////////////////////////////////////////////////////

void initBins(parts *b, int size)
{
    for(int x=0; x < size; x++)
    {
        cin.ignore(1000, '\n');
        cout << "\nEnter the description of item " << x + 1 << ": ";
        cin.getline(b[x].desc, 30, '\n'); //read cstring
        cout << "\nHow many " << b[x].desc << "do you have?";
        cin >> b[x].qty;
    }
}

/////////////////////////////////////////////////////////////////////////

void displayBins(const parts *b, int size)
{
    cout << "\nDescription                    Qty"
         << "\n==================================";
    for(int x=0; x < size; x++)
    {
        cout << endl << setw(30) << left << b[x].desc << setw(3)
             << right << b[x].qty;
    }
}

