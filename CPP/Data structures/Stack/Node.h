
#ifndef NODE_H
#define NODE_H

typedef struct data
{
	int id;
	char name;
}data;

struct node
{
	int key;
	data d;
	node * next;
};
#endif
