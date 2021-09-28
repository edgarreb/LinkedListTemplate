#include "LinkedList.h"

// --- struct Node --- //

/*
@Brief - This function will set the Value variable within the Node struct.
*/
template <typename T>
void Node<T>::SetValue(T InputValue) {
	this->Value = InputValue;
	return;
}

/*
@Brief - This function will return the Value variable within the Node struct.
*/
template <typename T>
T Node<T>::ReturnValue(void) {
	return this->Value;
}

// --- class LinkedList --- //

/*
@Brief - This function is used to retrieve the Head of the linked list.
*/
template <typename T>
Node<T>* LinkedList<T>::ReturnHead(void) {
	return this->Head;
} 

/*
@Brief - This constructor initializes the Head of the linked list to NULL.
*/
template <typename T>
LinkedList<T>::LinkedList() {
	this->Head = nullptr;
	return;
}

/*
@Brief - This function creates a linked list of paramater Size and sets the Head to the first
Node in the linked list. If the user enters an invalid size then the Head is set to null.
*/
template <typename T>
void LinkedList<T>::CreateList(int Size) {

	if(Size <= 0) {
		Head = nullptr;
		return;
	}

	Node<T>* Pointer2 = nullptr;

	for(int i = 0; i < Size; i++) {
		
		if(i == 0) {
			this->Head = new Node<T>;
			Pointer2 = Head;
		}
		else {
			Pointer2->Next = new Node<T>;
			Pointer2 = Pointer2->Next;
		}

		if(i == Size - 1) {
			Pointer2->Next = nullptr;
		}

	}

	return;
}

/*
@Brief - This function prints out all of the values for each node in the linked list. If the 
linked list is empty then an error message is logged to the console.
*/
template <typename T>
void LinkedList<T>::PrintList(void) {

	if(this->Head == nullptr) {
		std::cout << "Error: List is empty." << std::endl;
		return;
	}

	Node<T>* Pointer = Head;
	
	int NodeIndex = 0;

	while(Pointer != nullptr) {
		std::cout << "Node " << NodeIndex << std::endl;
		std::cout << "   Value: " << Pointer->ReturnValue() << std::endl;
		std::cout << std::endl;

		Pointer = Pointer->Next;
		NodeIndex++;
	}

	return;

}
