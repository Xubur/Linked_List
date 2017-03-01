// FILE: node.h
// PROVIDES: A class for a node in a linked list and a collection of functions for
// manipulating linked lists
//
// TYPEDEF for the node class:
//	Each node of the list contains some kind of data as well as a pointer to the next node
//	The type of data is defined as node::value_type in a typedef statement.
//	The value_type may be any of the C++ built-in types (int, char, etc) or a class with a
//	default constructor (!!!), copy constructor, an assignment operator, and a test for equality.
//
// CONSTRUCTOR for the node class:
//	node(const value_type& init_data, node* init_link)
//		Postcondition: The node contains the specified data and link.
//		NOTE: The init_data parameter has a default value that is obtained from the default constructor
//		of the value_type. In the ANSI/ISO Standard, this notation is also allowed for the built-in types,
//		providing a default value of zero. The init_link has a default value of NULL.
//
// NOTE:
//	Some functions have a return value that is a pointer to a node. 
//	Each of these functions comes in two versions: 
//		A non-const version (returns node*)
//		A const version (returns constant node*)
// EXAMPLES:
//	const node *c;
//	c->link() activates the const version of link
//	list_search(c, ... calls the const version of list_search
//	node *p;
//	p->link() activates the non-const version of link
//	list_search(p, ... calls the non-const version of list_search
//
// MEMBER FUNCTIONS
//	void set_data(const value_type& new_data)
//		Postcondition: The node now contains the specified new data.
//
//	void set_link(node* new_link)
//		Postcondition: The node now contains the specified new link.
//
//	value_type data() const
//		Postcondition: The return value is the data from this node.
//
//	const node* link() const			<--Const Version 
//	and
//	node* link()						<--Non-const Version
//	See the previous note about the const version and non-const versions.
//		Postcondition: The return value is the link from this node.
//
// FUNCTIONS in the linked list toolset:
//	size_t list_length(const node* head_ptr);
//		Precondition: head_ptr is the head pointer of a linked list.
//		Postcondition: The value returned is the nummber of nodes in the linked list
//
//	void list_head_insert(node*& head_ptr, const node::value_type& entry);
//		Precondition: head_ptr is the head pointer of a linked list.
//		Postcondition: A new node containing the given entry has been added at the head 
//		of the linked list; head_ptr now points to the head of the new, longer linked list.
//
//	void list_insert(node* prev_ptr, const node::value_type& entry);
//		Precondition: prev_ptr points to a node in a linked list.
//		Postcondition: A new node containing the given entry has been added after the node
//		that prev_ptr points to.
//
//	const node* list_search(const node* head_ptr, const node::value_type& target);
//	and
//	node* list_search(node* head_ptr, const node::value_type& target);
//	See the previous note about the const version and non-const versions.
//		Precondition: head_ptr is the head pointer of a linked list.
//		Postcondition: The pointer returned points to the firstnode containing the specified
//		target in its data field. If there is no such node, the null pointer is returned.
//
//	const node* list_locate(const node* head_ptr, const std::size_t position);
//	and
//	node* list_locate(node* head_ptr, const std::size_t position);
//	See the previous note about the const version and non-const versions.
//		Precondition: head_ptr is the head pointer of a linked list, and position > 0.
//		Postcondition: The pointer returned points to the node at the specified position in the list.
//		(The head node is position 1, the next node is in position 2, etc) If there is no such position,
//		then the null pointer of the new, shorter linked list.
//
//	void list_head_remove(node*& head_ptr);
//		Precondition: head_ptr is the head pointer of a linked list, with at leas one node.
//		Postcondition: The head node has been removed and returned to the heap;
//		head_ptr is now the head pointer of the new, shorter linked list.
//
//	void list_remove(node* prev_ptr);
//		Precondition: prev_ptr points to a node in a linked list, and this is not the tail node of 
//		the list.
//		Postcondition: The node after prev_ptr has been removed from the linked list.
//
//	void list_clear(node*& head_ptr);
//		Precondition: head_ptr is the head pointer of a linked list.
//		Postcondition: All nodes of the list have been retured to the heap, and the head_ptr is
//		now NULL.
//
//	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
//		Precondition: source_ptr is the head pointer of a linked list.
//		Postcondition: head_ptr and tail_ptr are the head and tail pointers for a new list that
//		contains the same items as the list pointed to by the source_ptr
//
// DYNAMIC MEMORY usage by the functions:
//	If there is insufficient dynamic memory, then the following functions throw bas_alloc:
//	the node constructor, list_head_insert, list_insert, list_copy.

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <cstdlib>

class node {
public:
	// TYPEDEF Will replace with templates soon enough. Just you wait.
	typedef double value_type;
	// CONSTRUCTOR
	node(const value_type& init_data = value_type(), node* init_link = NULL)
	{
		data_field = init_data;
		link_field = init_link;
	}
	// Member functions to set data and links:
	node* link()
	{
		return link_field;
	}
	void set_data(const value_type& new_data)
	{
		data_field = new_data;
	}
	void set_link(node* new_link)
	{
		link_field = new_link;
	}

	// Const member functions to get data
	value_type data() const
	{
		return data_field;
	}
	const node* link() const
	{
		return link_field;
	}

private:
	value_type data_field;
	node *link_field;
};

// Toolkit Functions
std::size_t list_length(const node* head_ptr);
void list_head_insert(node*& head_ptr, const node::value_type& entry);
void list_insert(node* prev_ptr, const node::value_type& entry);
node* list_search(node* head_ptr, const node::value_type& target); //Data manipulation
const node* list_search(const node* head_ptr, const node::value_type& target); //Const, no manipulation
node* list_locate(node* head_ptr, const std::size_t position); //Data manipulation
const node* list_locate(const node* head_ptr, const std::size_t position); //Const, no manipulation
void list_head_remove(node*& head_ptr);
void list_remove(node* prev_ptr);
void list_clear(node*& head_ptr);
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
#endif


