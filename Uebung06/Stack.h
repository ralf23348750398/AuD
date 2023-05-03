#pragma once

template<class item_type>
class Stack {
	struct node {
		item_type item;
		node* next;
	};
	
private:
	node* tail;
	int anz_items;
public:
	Stack(){
		tail = nullptr;
		anz_items = 0;
	}
	~Stack() {
		while (!empty()) {
			pop();
		}
	}
	void push(item_type& r) {
		node* new_node = new node;
		new_node->item = r;
		new_node->next = tail;
		anz_items++;
		tail = new_node;
	}
	item_type pop() {
		if (empty()) {
			throw std::out_of_range("empty stack");
		}
		node* temp = tail;
		item_type item = temp->item;
		tail = temp->next;
		delete temp;
		anz_items--;
		return item;
	}
	item_type top() {
		if (empty()) {
			throw std::out_of_range("Stack is empty");
		}
		return tail->item;
	}
	int length() {
		return anz_items;
	}
	bool empty() {
		return tail == nullptr;
	}
};



/*
First, let's start with the node struct:

c++

struct node {
	item_type item;  // The item stored in this node
	node* next;      // A pointer to the next node in the stack
};

This struct defines the individual nodes that make up the stack. Each node contains an item of the item_type class, which is the type of objects that will be stored in the stack. The next pointer is used to link this node to the next node in the stack.

Next, let's look at the private members of the Stack class:

c++

node* tail;     // A pointer to the top (i.e., the most recently added) node in the stack
int anz_items;  // The number of items in the stack

The tail pointer points to the top node in the stack. Initially, it is set to nullptr to indicate that the stack is empty. The anz_items variable keeps track of the number of items in the stack.

The public interface of the Stack class includes the following methods:

c++

Stack();            // The constructor initializes an empty stack
~Stack();           // The destructor deletes all nodes in the stack
void push(item_type& r);  // Adds a new item to the top of the stack
item_type pop();    // Removes and returns the top item from the stack
item_type top();    // Returns the top item without removing it from the stack
int length();       // Returns the number of items in the stack
bool empty();       // Returns true if the stack is empty, false otherwise

The constructor and destructor are pretty straightforward. The constructor initializes an empty stack by setting tail to nullptr and anz_items to 0. The destructor removes all nodes in the stack by repeatedly calling pop() until the stack is empty.

The push() method adds a new item to the top of the stack. It creates a new node object and initializes its item member with the given item. Then it sets the next pointer of the new node to point to the current top node (i.e., tail). Finally, it updates the tail pointer to point to the new node and increments the anz_items counter.

The pop() method removes and returns the top item from the stack. It first checks if the stack is empty (i.e., tail is nullptr), and throws an exception if it is. Otherwise, it creates a temporary pointer temp to point to the current top node. It retrieves the item from temp, updates the tail pointer to point to the next node in the stack, deletes temp, decrements anz_items, and returns the retrieved item.

The top() method returns the top item from the stack without removing it. It checks if the stack is empty and throws an exception if it is. Otherwise, it simply returns the item member of the tail node.

The length() method returns the number of items in the stack, which is stored in the anz_items member.

The empty() method returns true if the stack is empty (i.e., tail is nullptr), and false otherwise.
*/