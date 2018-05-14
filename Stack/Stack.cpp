/*
 * Stack.cpp
 *
 *  Created on: 2018. 5. 14.
 *      Author: jt0808.kim
 */

#include "Stack.h"
#include <iostream>
#include <stdio.h>
bool Stack::create_List()
{

	if(this->node == NULL)
	{
		return false;
	}

	this->node = new Node;
	this->node->head = new Node;
	this->node->tail = new Node;

	this->node->head->next = this->node->tail;
	this->node->head->prev = this->node->tail;
	this->node->tail->next = this->node->head;
	this->node->tail->prev = this->node->head;

	return true;
}
bool Stack::add_Node(int data)
{
	if(this->node == NULL)
	{
		return false;
	}

	//The node to search index to insert node
	Node* curNode;
	curNode = this->node->head;

	//Create node to insert
	Node* newNode;
	newNode = new Node;
	newNode->data = data;

	//Start to search index
	while(curNode->next != this->node->tail)
	{
		curNode = curNode->next;
	}

	//Insert Node
	newNode->next = this->node->tail;
	curNode->next = newNode;
	newNode->prev = curNode;
	this->node->tail->prev = newNode;


	return true;
}

bool Stack::mod_Node(int data)
{
	bool isModify = false;
	if(this->node == NULL)
	{
		return isModify;
	}

	//The node to search index to insert node
	Node* curNode;

	curNode = this->node->head;

	//Start to search index
	while(curNode != this->node->tail)
	{
		curNode = curNode->next;

		//Modify a data of Node
		if(curNode->data == data)
		{
			int newData;
			std::cout<<"Input new data: ";
			std::cin>>newData;
			curNode->data  = newData;
			isModify = true;
		}
	}
	delete curNode;
	return isModify;
}

bool Stack::search_Node(int data)
{
	bool isSearch = false;

	if(this->node == NULL)
	{
		return isSearch;
	}

	//The node to search node
	Node* curNode;

	curNode = this->node->head;

	//Start to search index
	while(curNode != this->node->tail)
	{
		curNode = curNode->next;

		//Search a data of node
		if(curNode->data == data){
			printf("The found data is: %d\n", curNode->data);
			isSearch = true;
		}
	}

	return isSearch;
}
bool Stack::del_Node(int data)
{
	bool isDelete = false;

	if(this->node == NULL)
	{
		return isDelete;
	}

	//The node to search node
	Node* curNode;

	curNode = this->node->head;

	//Start to search index
	while(curNode != this->node->tail)
	{
		curNode = curNode->next;

		//Search a data of node
		if(curNode->data == data){
			curNode->prev->next = curNode->next;
			curNode->next->prev = curNode->prev;
			delete curNode;
			isDelete = true;
		}
	}

	return isDelete;
}

bool Stack::sort_List()
{
	if(this->node == NULL){
		return false;
	}

	int tmp;
	Node* i = this->node->head->next;
	Node* j = i->next;

	while(i != this->node->tail)
	{
		while(j != this->node->tail)
		{
			if(i->data > j->data)
			{
				tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
			j = j->next;
		}
		i = i->next;
		j = i->next;
	}

	return true;
}

void Stack::display_List()
{
	if(this->node == NULL){
		return;
	}

	Node* curNode;
	curNode = this->node->head->next;
	std::cout<<"\n head->";
	while(curNode != this->node->tail)
	{
		printf("%d->", curNode->data);
		curNode = curNode->next;
	}
	std::cout<<"tail->head"<<std::endl;

}
Stack::~Stack()
{
	Node* pre = this->node->head;
	Node* cur = pre->next;

	while(cur != this->node->tail){
		pre->next = cur->next;
		delete cur;
		cur = pre->next;
	}
	delete this->node;

}
