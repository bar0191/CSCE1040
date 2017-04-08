
//============================================================================
// Name        : H3_H.h
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : Header file consisting of libraries, standard definitions used
//	         Class managing linklist, enum values for string input from 
//	         user, and function prototypes
//	         THIS PROGRAM USES C++11 TOOLS TO COMPILE USE -std=c++0x
// ============================================================================


#ifndef H3_H_
#define H3_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> 

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Class Node is dedicated to set up and manage Nodes with-in a singly linkedlist
class Node
{
private:
	char data;
  	Node* link;
public:
	// functions to create and manage nodes in list
  	Node() : data(0), link(nullptr) {} 
  	Node(char value, Node* next) : data(value), link(next) {}
  	char getData() const { return data; } 
  	Node* getLink() const { return link; }
  	void setData(char value) { data = value; }
  	void setLink(Node* next) { link = next; }
	
	// functions below were defined in class definition because 
	// they work directly with the Nodes in the list by adding or 
	// removing a node. They can be defined in H3_func.cpp file but 
	// cause complications. 
  	Node* insertNode(Node* head, char &name)
  	{
  		Node* prev = nullptr;			// declare a node ptr prev to current value
    		Node* current = head;			// declare current as head of list

		// while current and name is NOT less then data in link list
    		while (current && !(name < current->data))
    		{
      			prev = current;			// make previous node equal to current
      			current = current->link;	// make current equal to next node
    		}

		// if prev equals null (end of list)
    		if (prev == nullptr)
      			head = new Node(name, head);	// create new node at the top (head) of list
    		else 					// else create new node after prev ptr
      			prev->link = new Node(name, prev->link); 

      		cout << "Added: " << name << endl;

      		return head;				// return head
  	}

  	void removeNode(Node** head, char target)
  	{
  		Node** prev = head;			// delcare double ptr node equal to head
    		Node* discard = *head;			// delcare node to discard as refrence to head
		
		// while discard does not equal null and target is not found
    		while ((discard != nullptr) && (target != discard->data)) 
    		{
      			prev  = &discard->link;		// make prev equal to refrence of next node after discard
      			discard = discard->link;	// make discard equal to next node after discard
    		}

		// if discard does not equal null (end of list)
    		if (discard != nullptr) 
    		{
      			*prev = discard->link;		// make refrence to prev equal to next node after discard 
      			delete discard;			// delete node to discard

      			cout << "Removed: " << target << endl;
    		}
    		else 					// else discard made it to end of list without finding target
    		{
      			cout << "*ERROR* not found for removal: " << target << endl;
    		}	
  	}
};

// typedef NodePtr to communicate(point to) public class
typedef Node* NodePtr;

// enum to for string conversion values to use in switch-case
enum cmdCode { addnode, removenode, search, print, commands, clear, exitprog, invalid };

// function prototypes
inline cmdCode cnvrt(string const& incmd);
inline string cmd();
void cmds();
void inputData(NodePtr list);
inline void printNodes(NodePtr list);
inline void insertNodes(NodePtr& list, char the_char);
inline void freeNodes(NodePtr list);
inline void NodeSearch(NodePtr list, char target);
inline void clrScreen();

#endif // H3_H_
