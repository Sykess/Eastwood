/*
 Program Name: BT.h
 Author: Nathan Caron
 Assignment #7
 Date: 4/28/14
 Purpose: The data, node, and BT class file.  It contains the functions
 		  we created in class, as well as the ones I made for an additional
 		  display in tree form, the ones to balance the tree, and the functions
 		  to get the depth.
*/


typedef struct data
{
	int num;
}data;
/////////////////////////////////////////////////////////////////////////////
struct node
{
	node * left;
	node * right;
	int k;
	data d;
};
/////////////////////////////////////////////////////////////////////////////
class BT
{
	private:
		node * tt;
		// had to add index to hold all nodes in an array, and since it fills
		// recursively, the only way I could get it to function properly was
		// with a class member variable.
		int index;
		int qty;
		int max;
		int p_getDepth(node * curr);
		bool p_add(node *, int &, data &);
		void p_makeEmpty(node * curr);
		void printLevels(node * root, int depth);
		void private_print(ostream &, node *);
		void p_sort(node * sort[], node * curr);
		node * p_find(int, data &, node *);
		node * p_balance(node * sorted[], int  start, int end);
		string getLevel(node *root, int level, string gap);
	public:
		BT();
		BT(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		bool putItem(int, data);
		bool deleteItem(int, data&);
		bool find(int, data&);
		void print(ostream & out);
		void displayTree();
		void balance();
		int getLength();
		int getDepth();
		~BT();
};
/////////////////////////////////////////////////////////////////////////////
BT::BT()
{
	qty = 0;
	tt = NULL;
	max = INT_MAX;
	index = 0;
}
/////////////////////////////////////////////////////////////////////////////
BT::BT(int num)
{
	if(num > 0)
		max = num;
	else
		max = INT_MAX;
	qty = 0;
	tt = NULL;
	index = 0;
}
/////////////////////////////////////////////////////////////////////////////
int BT::getDepth()
{
	return p_getDepth(tt);
}
/////////////////////////////////////////////////////////////////////////////
void BT::balance()
{
	node * sorted[qty];
	index = 0;

	// loads array with ordered nodes
	p_sort(sorted, tt);
	
	tt = p_balance(sorted, 0, qty - 1);
}
/////////////////////////////////////////////////////////////////////////////
node * BT::p_balance(node * sorted[], int  start, int end)
{
	if(start > end)
		return NULL;
	int mid = start + (end - start) / 2;

	node * curr = sorted[mid];
	curr -> left = p_balance(sorted, start, mid - 1);
	curr -> right = p_balance(sorted, mid + 1, end);
	return curr;
}
/////////////////////////////////////////////////////////////////////////////
void BT::p_sort(node * sort[], node * curr)
{
	if(curr == NULL)
		return;
		
	p_sort(sort, curr -> left); //walk left
	
	sort[index++] = curr;
	
	p_sort(sort, curr -> right); // walk right
}
/////////////////////////////////////////////////////////////////////////////
int BT::p_getDepth(node * curr)
{
	if(curr == NULL)
		return 0;
	int depthLeft = p_getDepth(curr -> left);
	int depthRight = p_getDepth(curr -> right);
	return depthLeft > depthRight? depthLeft + 1 : depthRight + 1;
}
/////////////////////////////////////////////////////////////////////////////
bool BT::putItem(int k, data d)
{
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
/////////////////////////////////////////////////////////////////////////////
bool BT::p_add(node * curr, int &k, data &d)
{
	if(curr -> k == k) //duplicate
		return false;
	if(curr -> k > k) //walk left
	{
		if(curr -> left == NULL)
		{
			curr -> left = new node;
			curr -> left -> left = curr -> left -> right = NULL;
			curr -> left -> k = k;
			curr -> left -> d = d;
			qty++;
			return true;
		}
		return p_add(curr -> left, k, d);
	}
	else // walk right
	{
		if(curr -> right == NULL)
		{
			curr -> right = new node;
			curr -> right -> left = curr -> right -> right = NULL;
			curr -> right -> k = k;
			curr -> right -> d = d;
			qty++;
			return true;
		}
		return p_add(curr -> right, k, d);
	}
}
/////////////////////////////////////////////////////////////////////////////
bool BT::find(int k, data &d)
{
	if(p_find(k, d, tt) == NULL)
		return false;
	return true;
}
/////////////////////////////////////////////////////////////////////////////
node * BT::p_find(int k, data &d, node * curr)
{
	if(curr == NULL)
		return curr;
		
	if(curr -> k > k) // check left
	{
		if((curr -> left != NULL) && (curr -> left -> k == k))
		{
			d = curr -> left -> d;
			return curr;
		}
		return p_find(k, d, curr -> left); // walk left
	}
	
	if(curr -> k < k) // check right
	{
		if(curr -> right != NULL && curr -> right -> k == k)
		{
			d = curr -> right -> d;
			return curr;
		}
		return p_find(k, d, curr -> right);
	}
	
	if(tt -> k == k)
	{
		d = tt -> d;
		return tt;
	}
}
/////////////////////////////////////////////////////////////////////////////
bool BT::deleteItem(int k, data &d)
{
	node * lost, * temp, *scan;
	
	if(tt == NULL)
		return false;
		
	if(tt -> k == k) //new tt
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
		qty--;
		return true;
	}
	
	scan = p_find(k, d, tt);
	
	if(scan == NULL) //not found
		return false;

	if(scan -> k < k) //right node is delete node
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
	
	//before if the node to delete's left child was NULL program would crash
	if(scan -> left == NULL)
		scan -> left = temp -> right;
	else
	{
		for(scan = scan -> left; scan -> right != NULL; scan = scan -> right);
		scan -> right = temp -> right;
	}

	delete temp;
	qty--;
	return true;
}
/////////////////////////////////////////////////////////////////////////////
bool BT::isFull()
{
	return qty >= max;
}
/////////////////////////////////////////////////////////////////////////////
bool BT::isEmpty()
{
	return qty == 0;
}
/////////////////////////////////////////////////////////////////////////////
int BT::getLength()
{
	return qty;
}
/////////////////////////////////////////////////////////////////////////////
bool BT::makeEmpty()
{
	p_makeEmpty(tt);
	return true;
}
/////////////////////////////////////////////////////////////////////////////
void BT::p_makeEmpty(node * curr)
{
	if(curr == NULL)
		return;
	p_makeEmpty(curr -> left);
	p_makeEmpty(curr -> right);
	delete curr;
}
/////////////////////////////////////////////////////////////////////////////
void BT::print(ostream & out)
{
	private_print(out, tt);
}
/////////////////////////////////////////////////////////////////////////////
void BT::private_print(ostream & out, node * curr)
{
	if(curr == NULL)
		return;
	private_print(out, curr -> left); //walk left
	out << curr -> k << " ";
	private_print(out, curr -> right); // walk right
}
/////////////////////////////////////////////////////////////////////////////
void BT::displayTree()
{
	printLevels(tt, getDepth());
}
/////////////////////////////////////////////////////////////////////////////
void BT::printLevels(node * curr, int depth) 
{
	for (int i = 1; i <= depth; i++) 
	{
		string gap="";
		for (int j = 0; j < pow(2, depth-i) - 1; j++) 
      		gap+=" ";

    	string levelNodes = getLevel(curr, i, gap);
    	cout << levelNodes << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////
string BT::getLevel(node * curr, int level, string gap) 
{
    if (level==1) 
    {
    	if (curr == 0) 
    		return gap + "-" + gap;
		stringstream out;
    	out << curr -> k;
    	return gap + out.str() + gap;
  	} 
  	else if (level > 1) 
  	{
		string leftStr = getLevel(curr ? curr -> left : 0, level-1, gap);
		string rightStr = getLevel(curr ? curr -> right : 0, level-1, gap);
		return leftStr + " " + rightStr;
 	} 
  	else 
  		return "";
}
/////////////////////////////////////////////////////////////////////////////
BT::~BT()
{
	makeEmpty();
}
/////////////////////////////////////////////////////////////////////////////
