/******************************************************************************
program:	Node.h
author:		A.Hayden
date:		4/8/15
assignment:	#5
purpose:	node structure header file
******************************************************************************/

typedef struct data
{
	char toolname[35];
	int quantity;
	double cost;
}data;

struct node
{
	node *prev;
	int key;
	data d;
	node *next;
};
