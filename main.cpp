/*
 * main.cpp
 *
 *  Created on: 2018. 5. 14.
 *      Author: jt0808.kim
 */
#include "List.h"
#include "Stack.h"
#include <iostream>
#include <stdio.h>

#define LIST_TYPE 0
int main(int argc, char *argv[])
{
	std::cout<<"start a code"<<std::endl;
	int menu;
	int data;
	bool status;
	List* list;
	//Stack *list;

#if LIST_TYPE == 0
	list = new Stack;
	status = list->create_List();
	if(!status){
		return -1;
	}

	//Do stack
	while(1)
	{
		std::cout<<"------------------------------------------------------"<<std::endl;
		std::cout<<"Insert: 1 / Modify: 2 / Delete: 3 / Search:4 / Sort: 5"<<std::endl;
		std::cout<<"------------------------------------------------------"<<std::endl;
		menu = 0;
		data = 0;
		std::cout<<"Input menu: ";
		std::cin>>menu;
		if(menu!=5)
		{
			std::cout<<"Input data: ";
			std::cin>>data;
		}


		switch(menu)
		{
			//Insert node
			case 1:
				if(list->add_Node(data))
				{
					list->display_List();
				}
				else
				{
					std::cout<<"Fail add"<<std::endl;
				}
				break;

			//Modify node
			case 2:
				if(list->mod_Node(data))
				{
					list->display_List();
				}
				else
				{
					std::cout<<"Fail modify"<<std::endl;
				}
				break;

			//Delete node
			case 3:
				if(list->del_Node(data))
				{
					list->display_List();
				}
				else
				{
					std::cout<<"Fail delete"<<std::endl;
				}
				break;

			//Search node
			case 4:
				if(!list->search_Node(data))
				{
					std::cout<<"Search fail"<<std::endl;
				}
				break;

			//Sort
			case 5:
				list->sort_List();
				list->display_List();
				break;
			default:
				break;
		}
	}
	delete list;

#elif LIST_TYPE == 1
	while(1)
	{

	}
#endif
	return 0;
}



