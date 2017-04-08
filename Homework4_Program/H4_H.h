//============================================================================
// Name        : H4_H.h
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : header file consisting of libraries, std, and class def
// ============================================================================

#ifndef H4_H_
#define H4_H_

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using std::cout;
using std::cin;
using std::list;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Node
{
private:
	char data;
public:
	// class functions to set up data
	Node() : data(0) {}
    Node(char name) : data(name) {}
	char getData() const { return data; }
    void setData(char name) { data = name; } 
	
	// overloaded operators
	friend ostream& operator << (ostream& output, Node& obj) { return output << obj.data; }
	friend istream& operator >> (istream& input, Node& obj) { return input >> obj.data; }
    bool operator < (const Node& rhs) { return data < rhs.data; }  
    bool operator == (const Node& rhs) { return data == rhs.data; }
	bool operator != (const Node& rhs) { return data != rhs.data; }
	bool operator = (const Node& rhs) { return data = rhs.data; }
}; 

enum cmdCode { addnode, removenode, search, print, left, right, commands, clear, exitprog, invalid };

// H4_H.h

#endif // H4_H_
