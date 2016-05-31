#include<windows.h>
#include<iostream>

#ifndef LINKLIST_H
#define LINKLIST_H

#include "node.h"
using namespace std;
class List
{
public:
   Node *head;
   List()
   {
       head=NULL;
   }
    bool  insert_at_end(string name,string source,string des,string bus_no,int seat_no)
{
	Node *n = new Node;
	n->bus_no= bus_no;
	n->destination=des;
	n->source=source;
	n->name=name;
	n->seat_no=seat_no;

	if (head == NULL)
	{
		head = n;
		return true;
	}
	else
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		return true;
	}
	return false;
}
Node*  search_list(string name)
{
	Node *temp = head;
	while (temp != NULL)
	{
		if (temp->name ==name )
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
bool isempty()
{
    if(head==NULL)
    {
        return true;
    }
    else
        return false;
}

};
#endif

