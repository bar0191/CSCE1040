//============================================================================
// Name        : list.cpp
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : .cpp file containing list function definitions
// ============================================================================

#include "H4_H.h"
#include "H4_Func_H.h"

/*
 ============================================================================
 Function    : cmd
 Parameters  : nothing
 Return      : cmd (user command)
 Description : This function takes in user input as a command line and will
               return the string user has entered (command)
 ============================================================================
 */

string cmd()
{
	string cmd;				// delcare string for user cmd	

  	cout << endl;			// endline before printing new cmd line
  	cout << "cmd> ";		// output cmd line
  	getline(cin, cmd);		// get user input

  	return cmd;				// return string input by user
}

/*
 ============================================================================
 Function    : cmds
 Parameters  : nothing
 Return      : nothing
 Description : This function prints out list of commands for user to use in
	       cmd function
 ============================================================================
 */

void cmds()
{
	// print commands
  	cout << endl;
  	cout << "+--COMMANDS--+\n"
       	     << "| ADD        |\n"
             << "| REMOVE     |\n"
             << "| PRINT      |\n"
	     << "| LEFT       |\n"
	     << "| RIGHT      |\n"
             << "| SEARCH     |\n"
             << "| COMMANDS   |\n"
	     << "| CLEAR      |\n"
             << "| EXIT       |\n"
             << "+------------+\n";

}

/*
 ============================================================================
 Function    : cnvrt (convert)
 Parameters  : incmd (takes in string command for cmd func)
 Return      : enum value of specific string
 Description : This function will convert a incoming string command to an
               enumerated value for switch-case statement
 ============================================================================
 */

cmdCode cnvrt(string const& incmd)
{
  	if (incmd == "ADD") return addnode;			// to enum value 0
  	if (incmd == "REMOVE") return removenode; 	// to enum value 1
  	if (incmd == "PRINT") return print;			// to enum value 2
	if (incmd == "LEFT") return left;			// to enum value 3
	if (incmd == "RIGHT") return right;			// to enum value 4
  	if (incmd == "SEARCH") return search;		// to enum value 5
  	if (incmd == "COMMANDS") return commands; 	// to enum value 6
  	if (incmd == "CLEAR") return clear;			// to enum value 7
  	if (incmd == "EXIT") return exitprog;		// to enum value 8
  	else return invalid;						// default	     9
}

/*
 ============================================================================
 Function    : clrScreen
 Parameters  : nothing
 Return      : nothing
 Description : This function clears screen with ASCII escape codes
 ============================================================================
 */

void clrScreen()
{
  	cout << "\033[2J\033[1;1H";		// ASCII escape codes to clear screen
}

/*
 ============================================================================
 Function    : insert
 Parameters  : list<Node> list_obj, Node the_char
 Return      : nothing
 Description : This function is used to check for a duplication
	           if there is no duplication, then insert name, and sort 
 ============================================================================
 */

void insert(list<Node>& list_obj, Node the_char)
{
	list<Node>::iterator current;

	// iterate through begining to end
	for (current = list_obj.begin(); current != list_obj.end(); current++)
	{
		// if current iterator equals the name
		if (the_char == *current)
		{
			// output duplicate and do not insert
			cout << "Duplicate: " << the_char << endl;
			return;
		}
	}

	// insert char to the beginning of list 
	list_obj.insert(list_obj.begin(), the_char);

	cout << "Added: " << the_char << endl;

	list_obj.sort();	// sort after insertion		
}

/*
 ============================================================================
 Function    : deleteData
 Parameters  : list<Node> list_obj, Node the_char
 Return      : nothing
 Description : will delete target node and move current node to left or right
 ============================================================================
 */

void deleteData(list<Node>& list_obj, Node& the_char)
{
	list<Node>::iterator current;
	Node temp;

	// iterate through list from beginning to end
	for (current = list_obj.begin(); current != list_obj.end(); current++)
	{
		// if current equals name and current is not head of list
		if (*current == the_char && *current != list_obj.front())
		{
			// make current Node in list go to left
			current--;
			temp = *current;
			break;
		}
		// if current equals name and current is not end of list
		if (*current == the_char && *current != list_obj.back())
		{
			// make current Node in list go to right
			current++;
			temp = *current;
			break;
		}
	}

	// remove target name 
	list_obj.remove(the_char);
			 	
	cout << "Removed: " << the_char << endl;
	the_char = temp;
}

/*
 ============================================================================
 Function    : printList
 Parameters  : list<Node> list_obj, Node the_char
 Return      : nothing
 Description : prints list of nodes and moves current node to front
 ============================================================================
 */

void printList(list<Node>& list_obj, Node& the_char)
{
	list<Node>::iterator current;

	// if list is empty print message
	if (list_obj.empty())
	{
		cout << "List is empty... " << endl;
	}

	// iterate through list and print each Node
	for (current = list_obj.begin(); current != list_obj.end(); current++)
	{
		cout << *current << endl;
	}

	// put current Node to front of list
	the_char = list_obj.front();

}

/*
 ============================================================================
 Function    : dataLeft
 Parameters  : list<Node> list_obj, Node the_char
 Return      : nothing
 Description : moves current node to the left if possible
 ============================================================================
 */

void dataLeft(list<Node>& list_obj, Node& the_char)
{
	list<Node>::iterator current;

	// iterate through list
	for (current = list_obj.begin(); current != list_obj.end(); current++)
	{
		// if current exists
		if (*current == the_char)
		{
			// if current is at head
			if (current == list_obj.begin())
			{
				// output error node is at head
				cout << "Head of list is " << *current << ": Cannot move left. " << endl;
				//cout << "Data: " << *current << endl;
				return;
			}

		// move node to left otherwise			
		current--;	
		the_char = *current;		

		cout << "Data: " << *current << endl;
		return;	
		}
	}
}

/*
 ============================================================================
 Function    : dataRight
 Parameters  : list<Node> list_obj, Node the_char
 Return      : nothing
 Description : moves current node to right if possible
 ============================================================================
 */

void dataRight(list<Node>& list_obj, Node& the_char)
{
	list<Node>::iterator current;

	// iterate through list
	for (current = list_obj.begin(); current != list_obj.end(); current++)
	{
		// if current exists
		if (*current == the_char)
		{
			// if current is at tail
			if (*current == list_obj.back())
			{
				// output error node is at tail
				cout << "Tail of list is " << *current << ": Cannot move right. " << endl;
				return;
			}
		
		// move node to right otherwise
		current++;	
		the_char = *current;	
	
		cout << "Data: " << *current << endl;
		return;	
		}
	}
}

/*
 ============================================================================
 Function    : dataSearch
 Parameters  : list<Node> list_obj, Node the_char
 Return      : nothing
 Description : search for target name specified by user
 ============================================================================
 */

void dataSearch(list<Node> list_obj, Node& the_char)
{
	list<Node>::iterator current = list_obj.begin();

	// if list is empty output
	if (list_obj.empty())
	{
		cout << "List is empty... " << endl;
		return;
	}

	// while current does not equal the target and current is not tail
	while (*current != the_char && current != list_obj.end())
	{
		// go to next Node
		current++;
	}
		
		// if current finds target
		if (*current == the_char)
		{
			cout << "True: " << the_char << endl; 
		}
		// else output false and push current to front
		else
		{
			cout << "False: " << the_char << endl;
			the_char = list_obj.front();
		}

}

/*
 ============================================================================
 Function    : clearList
 Parameters  : list<Node> list_obj
 Return      : nothing
 Description : clear memory of allocated data
 ============================================================================
 */

void clearList(list<Node>& list)
{
	// clear memory of allocated data
	cout << "Clearing memory... " << endl;
	list.clear();
	cout << "Exiting program...goodbye! " << endl;

}
