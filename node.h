#include<windows.h>
#include<string>
#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
class Node
{
public:
    string name;
    string source;
    string destination;
    string bus_no;
    int seat_no;
     Node *next;
     Node();
     ~Node();
};
     Node::Node()
	{

		next=NULL;
	}
	 Node::~Node()
	{
	//	delete nxt;
	}

#endif
