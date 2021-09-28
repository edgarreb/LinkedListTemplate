#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>

template <typename T>
struct Node {

	private:
	T Value;

	public:
	Node* Next;
	void SetValue(T InputValue);
	T ReturnValue(void);
};

template <typename T>
class LinkedList {
	
	public:
	
	LinkedList(void);
	
	Node<T>* Head;	
	Node<T>* ReturnHead(void);	

	void CreateList(int Size);
	void PrintList(void);
	void ReverseList(void);

	bool InsertNode(int Position);
	bool RemoveNode(int Position);
	
	void SetNodes(void);
	void SetIndividualNode(int Position, T NodeValue);
};

#endif
