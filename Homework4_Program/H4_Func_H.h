//============================================================================
// Name        : H4_Func_H.h
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : header file containing function prototypes 
// ============================================================================

#ifndef H4_Func_H
#define H4_Func_H

#include "H4_H.h"

string cmd();
void cmds();
cmdCode cnvrt(string const& incmd);
void clrScreen();
void insert(list<Node>& list_obj, Node the_char);
void deleteData(list<Node>& list_obj, Node& the_char);
void dataSearch(list<Node> list_obj, Node& the_char);
void printList(list<Node>& list_obj, Node& the_char);
void dataLeft(list<Node>& list_obj, Node& the_char);
void dataRight(list<Node>& list_obj, Node& the_char);
void clearList(list<Node>& list);

#endif // H4_Func_H
