/*
 * List.h
 *
 *  Created on: 2018. 5. 14.
 *      Author: jt0808.kim
 */

#ifndef LIST_H_
#define LIST_H_

class Node{
public:
		int data;
		Node* prev;
		Node* next;
		Node* head;
		Node* tail;
};

class List{
public:
	Node* node;

	virtual bool create_List() = 0;
	virtual bool add_Node(int data) = 0;
	virtual bool mod_Node(int data) = 0;
	virtual bool search_Node(int data) = 0;
	virtual bool del_Node(int data) = 0;
	virtual bool sort_List() = 0;
	virtual void display_List() = 0;
	virtual ~List(){}
};



#endif /* LIST_H_ */
