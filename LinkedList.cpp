#include "LinkedList.h"

//#define DEBUG

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

	Node<T>* Pointer = nullptr;

	for(int i = 0; i < Size; i++) {
		
		if(i == 0) {
			this->Head = new Node<T>;
			Pointer = Head;
		}
		else {
			Pointer->Next = new Node<T>;
			Pointer = Pointer->Next;
		}

		if(i == Size - 1) {
			Pointer->Next = nullptr;
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

	std::cout << std::endl;

	while(Pointer != nullptr) {
		std::cout << "Node " << NodeIndex << std::endl;
		std::cout << "   Value: " << Pointer->ReturnValue() << std::endl;
		
		#ifdef DEBUG
			std::cout << "   Address: " << Pointer << std::endl;
			std::cout << "   Next: " << Pointer->Next << std::endl; 
		#endif

		Pointer = Pointer->Next;
		NodeIndex++;
	}

	std::cout << std::endl;

	return;

}

/*
@Brief - This function will reverse the linked list and update the Head member.
If the reversal is not possible an error message will be logged to the console.
*/

template <typename T>
void LinkedList<T>::ReverseList(void) {

	if(Head == nullptr) {
		std::cout << "Error: Unable to reverse empty list." << std::endl;
		return;
	}

	if(Head->Next == nullptr) {
		std::cout << "Error: Unable to reverse list with single node." << std::endl;
		return;
	}

	Node<T>* LeftNode = Head;
	Node<T>* MiddleNode = LeftNode->Next;
	Node<T>* RightNode = MiddleNode->Next;

	while(true) {

		// Reverse linked list.
		MiddleNode->Next = LeftNode;
		
		// Handle last Node reversal.
		if(RightNode == nullptr) {
			Head->Next = nullptr;
			Head = MiddleNode;
			break;
		}
	
		// Shift pointers.
		LeftNode = MiddleNode;
		MiddleNode = RightNode;
		RightNode = RightNode->Next;
	}

	return;
}

/*
@Brief - This function inserts a node at argument Position. If the position is out of range then the 
insertion will not take place. 
*/
template <typename T>
bool LinkedList<T>::InsertNode(int Position) {

	if(Position < 0) {
		std::cout << "Error: Invalid insertion position." << std::endl;
		return false;
	}

	Node<T>* Pointer = nullptr;

	// This will handle an insertion at the begining.
	if(Position == 0) {
		Pointer = new Node<T>;
		Pointer->Next = Head;
		Head = Pointer;
		return true;
	}

	if(Head == nullptr) {
		std::cout << "Error: Invalid insertion position." << std::endl;
		return false;
	}

	// This will handle an insertion in the middle or at the end
	
	Node<T>* PrevNode = nullptr;
	Node<T>* NextNode = Head;
	
	for(int i = 0; i < Position; i++) {

		if((i <= Position - 1) && (NextNode == nullptr)) {
			std::cout << "Error: Invalid insertion position." << std::endl;
			return false;
		}

		PrevNode = NextNode;
		NextNode = NextNode->Next;
	}

	PrevNode->Next = new Node<T>;
	PrevNode = PrevNode->Next;
	PrevNode->Next = NextNode;

	return true;
}

/*
@Brief - This function will delete a given Node at paramater Position. If Position is
out of range then an error message will be logged to the console.
*/
template <typename T>
bool LinkedList<T>::RemoveNode(int Position) {

	if(Position < 0) {
		std::cout << "Error: Invalid removal position" << std::endl;
		return false;
	}
	
	if(Head == nullptr) {
		std::cout << "Error: Unable to remove node from empty list." << std::endl;
		return false;
	}

	// This will handle the removal from the begining.

	if(Position == 0) {
		Node<T>* Pointer = Head;
		Head = Head->Next;
		delete Pointer;
		return true;		
	}

	// This will handle a removal of a node from the end or the middle.
	
	Node<T>* PrevNode = nullptr;
	Node<T>* NextNode = Head;

	for(int i = 0; i < Position; i++) {

		if((i <= Position - 1) && (NextNode->Next == nullptr)) {
			std::cout << "Error: Invalid removal position" << std::endl;
			return false;
		}
		
		PrevNode = NextNode;
		NextNode = NextNode->Next;		
	}

	PrevNode->Next = NextNode->Next;
	delete NextNode;

	return true;
}

/*
@Brief - This function allows the user to set each of the nodes in the linked list via
the console window.
*/
template <typename T>
void LinkedList<T>::SetNodes(void) {

	if(Head == nullptr) {
		std::cout << "Error: Unable to set nodes in empty list." << std::endl;
		return;
	}

	Node<T>* Pointer = Head;
	T TempValue;
	int NodeIndex = 0;

	std::cout << std::endl;
	
	while(Pointer != nullptr) {
		
		std::cout << "Node " << NodeIndex << std::endl;
		std::cout << "Enter a value -->  ";
		std::cin >> TempValue;
		Pointer->SetValue(TempValue);

		Pointer = Pointer->Next;
		NodeIndex++;
	}

	std::cout << std::endl;

	return;
}

/*
@Brief - This function will set an individual nodes value. If the Node is not in range then
the function will not set any value. 
*/
template <typename T>
void LinkedList<T>::SetIndividualNode(int Position, T NodeValue) {
	
	if(Position < 0) {
		std::cout << "Error: Unable to set node due to inavlid position." << std::endl;
		return; 
	}

	if(Head == nullptr) {
		std::cout << "Error: Unable to set node in empty list." << std::endl;
		return;
	}

	Node<T>* Pointer = Head;

	for(int i = 0; i < Position; i++) {
		
		if((i <= Position - 1) && (Pointer->Next == nullptr)) {
			std::cout << "Error: Unable to set out of range node." << std::endl;
			return;
		}
	
		Pointer = Pointer->Next;
	}

	// Insert the value into the Node.

	Pointer->SetValue(NodeValue);
	
	return;
}
