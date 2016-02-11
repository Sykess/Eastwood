/******************************************************************************
program:	BinaryTree.h
author:		A.Hayden
date:		4/28/15
assignment:	...
purpose:	binary tree header file
******************************************************************************/

typedef struct data
{
	int num;
}data;

struct node
{
	node *left;
	int k;
	data d;
	node *right;
};

class BT
{
	private:
		node *tt;
		int qty;
		int max;
	private:
		bool p_add(node *curr, int &k, data &d);
		node * p_find(node *curr, int k, data &d);
		node *p_find2(int k, data d);
		void p_print(ostream &out, node *curr);
		void p_empty(node *curr);
	public:
		BT();
		BT(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		int getLength();
		bool putItem(int k, data d);
		bool deleteItem(int k, data &d);
		void print(ostream & out);
		bool find(int k, data &d);
		~BT();
};
///////////////////////////////////////////////////////////////////////////////
BT::BT()
{
	qty = 0;
	tt = NULL;
	max = INT_MAX;
}
///////////////////////////////////////////////////////////////////////////////
BT::BT(int m)
{
	if(m > 0)
		max = m;
	else
		max = INT_MAX;
	
	tt = NULL;
	qty = 0;
}
///////////////////////////////////////////////////////////////////////////////
bool BT::isEmpty()
{
	if(qty == 0)
		return true;
	return false;
}
///////////////////////////////////////////////////////////////////////////////
bool BT::isFull()
{
	if(qty == max)
		return true;
	return false;
}
///////////////////////////////////////////////////////////////////////////////
bool BT::putItem(int k, data d)
{
	node *temp;
	if(isFull())
		return false;
	if(isEmpty())
	{
		tt = new node;
		tt -> left = tt -> right = NULL;
		tt -> k = k;
		tt -> d = d;
		qty = 1;
		return true;
	}
	return p_add(tt, k, d);
}
///////////////////////////////////////////////////////////////////////////////
bool BT::p_add(node *curr, int &k, data &d)
{
	if(curr -> k == k)	//duplicate
		return false;
	if(curr -> k > k)	//walk left
	{
		if(curr -> left == NULL)
		{
			curr -> left = new node;
			curr -> left -> left = curr -> left -> right = NULL;
			curr -> left -> k = k;
			curr -> left -> d = d;
			qty ++;
			return true;
		}
		return p_add(curr -> left, k, d);
	}
	else
	{
		if(curr -> right == NULL)
		{
			curr -> right = new node;
			curr -> right -> left = curr -> right -> right = NULL;
			curr -> right -> k = k;
			curr -> right -> d = d;
			qty ++;
			return true;
		}
		return p_add(curr -> right, k, d);
	}
}
///////////////////////////////////////////////////////////////////////////////
bool BT::find(int k, data &d)
{
	if(p_find2(k,d) == NULL)
		return false;
	return true;
}
///////////////////////////////////////////////////////////////////////////////
node * BT::p_find2(int k, data d)
{
	if(tt -> k == k)
	{
		d = tt -> d;
		return tt;
	}
	return p_find(tt, k, d);
}
///////////////////////////////////////////////////////////////////////////////
node * BT::p_find(node *curr, int k, data &d)
{
	if(curr == NULL)
		return curr;
	if(curr -> k > k)		//check left
	{
		if((curr -> left != NULL) && (curr -> left -> k == k))
		{
			d = curr -> left -> d;
			return curr;
		}
		return p_find(curr -> left, k, d);
	}
	if(curr -> k < k)		//check right
	{
		if((curr -> right != NULL) && (curr -> right -> k == k))
		{
			d = curr -> right -> d;
			return curr;
		}
		return p_find(curr -> right, k, d);
	}
}
///////////////////////////////////////////////////////////////////////////////
bool BT::deleteItem(int k, data &d)
{
	node *lost, *temp, *scan;
	if(tt == NULL)
		return false;
	if(tt -> k == k)		// new tt
	{
		temp = tt;
		d = temp -> d;
		tt = temp -> left;
		lost = temp -> right;
		if(tt == NULL)
			tt = lost;
		else
		{
			for(scan = tt; scan -> right != NULL; scan = scan -> right);
			scan -> right = lost;
		}
		delete temp;
		qty --;
		return true;
	}
	scan = p_find(tt, k, d);
	if(scan == NULL)		//not found
		return false;
	if(scan -> k < k)
	{
		temp = scan -> right;
		scan -> right = temp -> left;
		for(;scan -> right != NULL; scan = scan -> right);
		scan -> right = temp -> right;
		delete temp;
		qty--;
		return true;
	}
	temp = scan -> left;
	scan -> left = temp -> left;
	for(; scan -> right != NULL; scan = scan -> right);
	scan -> right = temp -> right;
	delete temp;
	qty--;
	return true;
}
///////////////////////////////////////////////////////////////////////////////
void BT::print(ostream &out)
{
	p_print(out, tt);
}
///////////////////////////////////////////////////////////////////////////////
void BT::p_print(ostream &out, node *curr)
{
	if(curr == NULL)
		return;
	p_print(out, curr -> left);
	out << curr -> k << endl;
	p_print(out, curr -> right);
}
///////////////////////////////////////////////////////////////////////////////
bool BT::makeEmpty()
{
	p_empty(tt);
	return true;
}
///////////////////////////////////////////////////////////////////////////////
void BT::p_empty(node *curr)
{
	if(curr == NULL)
		return;
	p_empty(curr -> left);
	p_empty(curr -> right);
	delete curr;
}
///////////////////////////////////////////////////////////////////////////////
BT::~BT()
{
	makeEmpty();
}
