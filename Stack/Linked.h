/*
 * Linked.h
 *
 *  Created on: 2018. 5. 14.
 *      Author: jt0808.kim
 */

#ifndef LINKED_H_
#define LINKED_H_
#include "List.h"
class Linked_List : public List{
	bool create_List(Node* list);
	bool add_Node(Node* list, int data);
	bool mod_Node(Node* list, int data);
	bool search_Node(Node* list, int data);
	bool del_Node(Node* list, int data);
	bool sort_List(Node* list);
	void display_List(Node* list);
};

#endif /* LINKED_H_ */
