#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <cstdlib>

class node {
public:
	// TYPEDEF lol
	typedef double value_type;
	// CONSTRUCTOR
	node(const value_type& init_data = value_type(), node* init_link = NULL)
	{
		data_field = init_data;
		link_field = init_link;
	}

	// Member functions to set the data and link fields:
	void set_data(const value_type& new_data)
	{
		data_field = new_data;
	}
	void set_link(node* new_link)
	{
		link_field = new_link;
	}

	// Constant member function to retrieve current data
	value_type data() const
	{
		return data_field;
	}

private:
	value_type data_field;
	node *link_field;
};
#endif


