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


