#include <iostream>
using namespace std;

const int SIZE = 17; // number of rows

int main()
{

  for (int x = 0; x < SIZE; x++)
  {
    int c = 1;
    cout.width(SIZE - x );
    for (int y = 0; y <= x; y++)
    {
      cout << c << " ";
      c = c * (x - y) / (y + 1);
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
