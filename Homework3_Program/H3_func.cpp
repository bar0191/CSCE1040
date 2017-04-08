//============================================================================
// Name        : H3_func.cpp
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : Function .cpp file containing each command option function
//               with specific functions working with inserting nodes. 
// ============================================================================

#include "H3_H.h"

/*
 ============================================================================
 Function    : cmd
 Parameters  : nothing
 Return      : cmd (user command)
 Description : This function takes in user input as a command line and will
               return the string user has entered (command)
 ============================================================================
 */
inline string cmd()
{
	string cmd;			// delcare string for user cmd	

  	cout << endl;			// endline before printing new cmd line
  	cout << "cmd> ";		// output cmd line
  	getline(cin, cmd);		// get user input

  	return cmd;			// return string input by user
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
inline cmdCode cnvrt(string const& incmd)
{
  	if (incmd == "ADD") return addnode;		// to enum value 0
  	if (incmd == "REMOVE") return removenode; 	// to enum value 1
  	if (incmd == "PRINT") return print;		// to enum value 2
  	if (incmd == "SEARCH") return search;		// to enum value 3
  	if (incmd == "COMMANDS") return commands; 	// to enum value 4
  	if (incmd == "CLEAR") return clear;		// to enum value 5
  	if (incmd == "EXIT") return exitprog;		// to enum value 6
  	else return invalid;				// default
}

/*
 ============================================================================
 Function    : inputData
 Parameters  : NodePtr list (points to data in class)(calls from main)
 Return      : nothing
 Description : This function works as the core to the entire program similar
               to main, it will take in the parameter of from main (list),
               and depending on what user command is executed will run its
	       function.
 ============================================================================
 */
void inputData(NodePtr list)
{
  	string input;
	char name;
	
  	do
  	{
    		input = cmd();			// takes in returned string value from cmd()
		
		// transform user input to uppercase
		transform(input.begin(), input.end(), input.begin(), toupper);

		//(if returned enum value is between print(3) and exit(6))
		if (cnvrt(input) >= print && cnvrt(input) <= exitprog)
		{
						// purposely empty
						// don't want to modify these strings				
		}
		else
		{				// this conversion works, but is not good practice
    			name = *input.rbegin(); // takes last char from string
    			input = input.substr(0, input.size() - 2);
		}

    		switch (cnvrt(input))
    		{
      			case addnode:		// add node 			
        			insertNodes(list, name);	
        			break;
      			case removenode:	// remove node
				list->removeNode(&list, name);	
        			break;
			case search:		// search nodes
				NodeSearch(list, name);
        			break;
      			case print:		// print linklist
				printNodes(list);
        			break;
      			case commands:		// print user commands
        			cmds();
        			break;
      			case clear:		// clear screen 
				clrScreen();
        			break;
      			case exitprog:		// exit program
				freeNodes(list);
        			break;
      			default:		// default statement
        			cout << "*ERROR* invalid command... " << endl;
    		}
 	 } while (cnvrt(input) != exitprog);
}

/*
 ============================================================================
 Function    : printNodes
 Parameters  : NodePtr list (takes parameter from inputData())
 Return      : nothing
 Description : This function prints out the data in linklist
 ============================================================================
 */
inline void printNodes(NodePtr list)
{
  	NodePtr temp = list; 			// declare temporary ptr to equal top of list
	
	cout << endl;

  	if (temp == nullptr) 			// if temp is null (end of list), list is empty
    		cout << "List is empty... " << endl;

  	while (temp != nullptr) 		// while temp (list) is not null
  	{
    		cout << temp->getData() << endl;
    		temp = temp->getLink(); 	// after printing first Node, temp equals next Node
  	}
}

/*
 ============================================================================
 Function    : insertNodes
 Parameters  : NodePtr& list, the char (entered by user)
 Return      : nothing
 Description : This function is used to mainly check for a duplication
	       if there is no duplication, then this function will call
               the insert fuction from the class definition and add the char
               to the list
 ============================================================================
 */
inline void insertNodes(NodePtr& list, char the_char)
{
  	NodePtr iter = nullptr;			// declare an iterator ptr value 

	// (iter starts at top of list, while its not null(empty), then go to next Node)
  	for (iter = list; iter != nullptr; iter = iter->getLink())
  	{
		// if the iterated value equals the char entered then it already exists
    		if (iter->getData() == the_char)
    		{
      			cout << "*ERROR* duplicate: " << iter->getData() << endl;
      			return;
    		}
  	}

	 // makes list equal to value that was called by function in class definiton
 	 list = list->insertNode(list, the_char);
}

/*
 ============================================================================
 Function    : freeNodes
 Parameters  : NodePtr list
 Return      : nothing
 Description : this function will run just before exiting the program, 
               it will run through the linklist and delete each node from 
               memory, and free the addresses. 
 ============================================================================
 */
inline void freeNodes(NodePtr list)
{
  	NodePtr temp = list;			// delcare temp ptr value as the top of list
	
	cout << "\nRemoving all Nodes from memory... " << endl;
 
  	while (temp != nullptr)			// while temp is not NULL (bottom of list)
  	{
    		NodePtr nodeToDelete = temp;	// delcare node to delete and equal to temp
    		temp = temp->getLink();		// equal temp to next node after node to delete

    		delete nodeToDelete;		// delete node, repeat until end of list
  	}

  	cout << "Exiting program...goodbye! " << endl;
}

/*
 ============================================================================
 Function    : NodeSearch
 Parameters  : NodePtr list, target char to be searched
 Return      : nothing
 Description : This function prints out student information
 ============================================================================
 */
inline void NodeSearch(NodePtr list, char target)
{
  	NodePtr here = list;			// declare ptr value here as the top of list

	cout << endl;

  	if (here == nullptr)			// if here is null (list is empty), output 
  	{
    		cout << "List is empty... " << endl;
  	}
  	else					// else search for the target char
  	{
		// while here does not equal target char and the next node is not null 
    		while (here->getData() != target && here->getLink() != nullptr)
		{
			// make here equal next node in list
      			here = here->getLink();	
		}

    		if (here->getData() == target)	// if here equals target output true
      			cout << "True: " << target << endl;
    		else 				// else output false, was not found
      			cout << "False: " << target << endl;
  	}
}

/*
 ============================================================================
 Function    : clrScreen
 Parameters  : nothing
 Return      : nothing
 Description : This function clears screen with ASCII escape codes
 ============================================================================
 */
inline void clrScreen()
{
  	cout << "\033[2J\033[1;1H";		// ASCII escape codes to clear screen
}

