





class Queue
{
	private:
		int max;
		int qty;
		node * in, * out;
	public:
		Queue(int);
		Queue();
		bool Queue(data &);
		bool deQueue(data &);
		bool makeEmpty();
		bool isEmpty();
		bool isFull();
		~Queue(); 
};
