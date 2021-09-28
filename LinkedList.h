#pragma once
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
	Node<T>* Head;	
	Node<T>* ReturnHead(void);	

	LinkedList(void);

	void CreateList(int Size);
	void PrintList(void);
};
