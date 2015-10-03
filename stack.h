// FILE: stack.h (part of the namespace echin_stack)

// CONSTRUCTOR for the stack<Item> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   Item pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
//   Item& top( ) 
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a reference to the top item of
//     the stack (but the stack is unchanged).
//
// CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   const Item& top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a const reference to the top item of
//     the stack (but the stack is unchanged).
//
// VALUE SEMANTICS for the stack<Item> class:
//   Assignments and the copy constructor may be used with stack<Item>
//   objects.
//
// DYNAMIC MEMORY USAGE by the stack<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   the copy constructor, push, and the assignment operator.

#ifndef EDWARD_CHIN_STACK
#define EDWARD_CHIN_STACK
#include <cstdlib>   // Provides NULL and size_t
#include "node.h"   // Node template class 

namespace echin_stack
{
    template <class Item>
    class stack
    {
    public:
        // TYPEDEFS 
        typedef std::size_t size_type;
        typedef Item value_type;
      
        // CONSTRUCTORS and DESTRUCTOR
        stack( ) { top_ptr = NULL; }
        void set_ptr() {top_ptr = NULL;}
        stack(const stack& source);
        ~stack( ) { list_clear(top_ptr); }
        // MODIFICATION MEMBER FUNCTIONS
        Item push(const Item& entry);
        Item pop( );
        void operator =(const stack& source);
        Item& top( );
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const
	    { return list_length(top_ptr); }
        bool empty( ) const { return (top_ptr == NULL); }
        const Item& top( ) const;
        echin::node<Item>* get_pointer()
        {
            echin::node<Item> *C = top_ptr;
            return C;
        }
        
        
        
    private:
        echin::node<Item> *top_ptr;  // Points to top of stack
        
    };
    
    template <class Item>
    class stack_iterator
    : public std::iterator<std::forward_iterator_tag, Item>
    {
    stack_iterator(stack<Item>& source)
    {
        P = source; //Set the private stack equal to the inputted Stack
        B  = source.get_pointer(); //Iterator at top of the stack
    }
    
    Item& operator *() const
    {
        return P.top();//returns the current value
    }
    
    stack_iterator& operator ++( ) // Prefix ++
	    { 
		P.pop();
                B  = P.get_pointer(); //B is now pointing to the next item of the stack
		return B;
	    }
    stack_iterator operator ++(int) // Postfix ++
	    {
		stack_iterator original(P);
		P.pop();
                B  = P.get_pointer();
		return original;      	  
	    }
    bool operator ==(const stack_iterator other) const
	    { return B == other.B; }
    bool operator !=(const stack_iterator other) const
	    { return B != other.B; }
    private:
        echin::node<Item>* B;
        stack<Item> P;
};

   template <class Item>
    class const_stack_iterator
    : public std::iterator<std::forward_iterator_tag, Item>
    {
    const_stack_iterator(const stack<Item>& source)
    {
        P = source; //Set the private stack equal to the inputted Stack
        B  = source.get_pointer(); //Iterator at top of the stack
    }
    
    const Item& operator *() const
    {
        return P.top();//returns the current value
    }
    
    const_stack_iterator& operator ++( ) // Prefix ++
	    { 
		P.pop();
                B  = P.get_pointer(); //B is now pointing to the next item of the stack
		return B;
	    }
    const_stack_iterator operator ++(int) // Postfix ++
	    {
		const_stack_iterator original(P);
		P.pop();
                B  = P.get_pointer();
		return original;      	  
	    }
    bool operator ==(const const_stack_iterator other) const
	    { return B == other.B; }
    bool operator !=(const const_stack_iterator other) const
	    { return B != other.B; }
    private:
        const echin::node<Item>* B;
        const stack<Item> P;
};
}


#include "stack.template" // Include the implementation 
#endif