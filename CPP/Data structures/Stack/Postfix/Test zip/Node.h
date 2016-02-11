/*
 Program Name: Node.h
 Author: Nathan Caron
 Assignment #3
 Date: 2/25/2015
 Purpose: Create node and typedef.
*/

#ifndef NODE_H
#define NODE_H

typedef struct data
{
	int num;
	char ch;
	double real;
}data;

struct node
{
	int key;
	data d;
	node * next;
};
#endif
