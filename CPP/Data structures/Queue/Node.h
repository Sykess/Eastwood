
#ifndef NODE_H
#define NODE_H

typedef struct data
{
	int custNum;
	int time;
}data;

struct node
{
	int key;
	data d;
	node * next;
};
#endif
