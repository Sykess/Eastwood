
#ifndef NODE_H
#define NODE_H

typedef struct data
{
	char toolName[35];
	int quantity;
	double cost;
}data;

struct node
{
	node * prev;
	node * next;
	int key;
	data d;
};

#endif
