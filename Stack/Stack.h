/*
 * Stack.h
 *
 *  Created on: 2018. 5. 14.
 *      Author: jt0808.kim
 */

#ifndef STACK_H_
#define STACK_H_

#include "List.h"
class Stack : public List{
public:

	bool create_List();
	bool add_Node(int data);
	bool mod_Node(int data);
	bool search_Node(int data);
	bool del_Node(int data);
	bool sort_List();
	void display_List();
	~Stack();

};


#endif /* STACK_H_ */
