#ifndef SUPMANE_H
#define SUPMANE_H

class DankList {
	struct  Node {
		int data;
		Node* next;
	};
	
	public:
		DankList();
		void add(int n);
		void print();
        void testList();


	private:
		int size;
		Node* head;
		Node* tail;
};

#endif 
