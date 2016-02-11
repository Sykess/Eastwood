/*
 Program Name: Pascal.cpp
 Author: Nathan Caron
 Assignment #1
 Date: 1/30/15
 Purpose: Use pascal class to display pascal's triangle.
*/

#include "Pascal.h"

const int SIZE = 153;

int main()
{

	pascal n(SIZE);
	n.propagate();
	n.displayInverted();
	
	return 0;
}
	
