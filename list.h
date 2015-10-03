/* 
 * File:   list.h
 * Author: Edward
 *
 * Created on November 1, 2014, 10:58 AM
 */

/* This is the header file for the linked list class using stack as a template
 * CONSTRUCTOR for the stack<Item> template class:
 * list( )
 * Postcondition: The list has been initialized as an empty list.
 * 
 * void addition(const Item& entry); 
 * Post-Condition: Entry has been added to the top of the list
 * 
 * void insert(const Item& entry, const size_type& position); 
 * Pre-Condtion: Position must be greater than zero and does not exceed the total number of entries
 * Post-condition: At given position, the item entry has been added
 * 
 * void subtract();
 * post-condition: the top entry of the list has been removed
 * 
 * void remove(const size_type& position); //Can only remove entries other than the top
 * pre-condition: position is greater than one and does not exceed the total number of entries
 * postcondition: at position, the entry has been removed
 * 
 * size_type count(); //count the number of items in the list
 * postcondition: the number of items is returned
 * 
 * Item view(const size_type& position);
 * Pre-Condition: Position is greater than zero and does not exceed the total number of entries
 * postcondition: at position, the entry/data is returned
 * 
 * Item head(); //shows what at the head of the linked list
 * postcondition: the entry at the head of the list is returned
 * 
 */



#ifndef EDWARD_CHIN
#define EDWARD_CHIN
#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag
#include "stack.h"
#include "node.h"
#include<iostream>


namespace echin_list
{
template <class Item>
class list{
    public:
        typedef Item value_type;
        typedef std::size_t size_type;
        typedef echin_stack::stack_iterator<Item> iterator;
        typedef echin_stack::const_stack_iterator<Item> const_iterator;
     
        list() {A.set_ptr();};
        void erase_all();
        void addition(const Item& entry); //add an entry into linked list
        void insert(const Item& entry, const size_type& position); //insert an item at a specific position
        void subtract();// removes the content at the top of the list
        void remove(const size_type& position); //remove the top of the item at a specific position
        size_type count(); //count the number of items in the list
        Item& view(const size_type& positon); //show the item at a certain position
        Item& head(); //shows what at the head of the linked list
        
        //Functions to provide iterators
        iterator begin()
        { return iterator(A);}
        
        const_iterator begin() const
        { return const_iterator(A);}
        
        iterator end()
        {return iterator();}
        
        const_iterator end() const
        { return const_iterator();}
        
    private:
        echin_stack::stack<Item> A; //creates the stack of linked list from stack.h
        
};


/*template <class Item>
    class list_iterator
    : public std::iterator<std::forward_iterator_tag, Item>
    {
    list_iterator(list<Item>& source)
    {
        St = source.get_stack(); //Set the private stack equal to the inputted Stack
        B  = St.get_pointer(); //Iterator at top of the stack
    }
    
    Item& operator *() const
    {
        return St.top();//returns the current value
    }
    
    list_iterator& operator ++( ) // Prefix ++
	    { 
		St.pop();
                B  = St.get_pointer(); //B is now pointing to the next item of the stack
		return B;
	    }
    list_iterator operator ++(int) // Postfix ++
	    {
		list_iterator original();
		St.pop();
                B  = St.get_pointer;
		return original;      	  
	    }
    bool operator ==(const list_iterator other) const
	    { return B == other.B; }
    bool operator !=(const list_iterator other) const
	    { return B != other.B; }
    private:
        echin::node<Item>* B;
        echin_stack::stack<Item> St;
};*/
}
#include "list.template"
#endif

