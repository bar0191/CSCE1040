//============================================================================
// Name        : main.cpp
// Author      : Brandon A. Reid
// Version     : V.1
// Copyright   : 2016
// Description : main runs switch statement for each command entered by user
// ============================================================================

#include "H4_Func_H.h"

int main()
{
	list <Node> list;	// declare list object for Node class
	Node current;		// declare Node object for current Node
	string input;		// declare string to take in user input

	cmds();

	do
  	{
    	input = cmd();	// takes in returned string value from cmd()
		
		// transform user input to uppercase
		transform(input.begin(), input.end(), input.begin(), toupper);

		//(if returned enum value is between print(3) and exit(6))
		if (cnvrt(input) >= print && cnvrt(input) <= exitprog)
		{
						// purposely empty
						// do not want to modify these strings				
		}
		else
		{				// this conversion works, but is not good practice
    			current = *input.rbegin(); // takes last char from string
    			input = input.substr(0, input.size() - 2);
		}

    		switch (cnvrt(input))
    		{
      			case addnode:		// insert Node in list			
					insert(list, current);	
        			break;
      			case removenode:	// remove Node in list
					deleteData(list, current);
        			break;
				case search:		// search in list
					dataSearch(list, current);
        			break;
      			case print:			// print list
					printList(list, current);
        			break;
				case left:			// print left of current Node
					dataLeft(list, current);
					break;
				case right:			// print right of current Node
					dataRight(list, current);
					break;
      			case commands:		// print user commands
        			cmds();
        			break;
      			case clear:			// clear screen 
					clrScreen();
        			break;
      			case exitprog:		// exit program
					clearList(list);
        			break;
      			default:			// default statement
        			cout << "*ERROR* invalid command... " << endl;
					current = list.front();
    		}
 	 } while (cnvrt(input) != exitprog);
	
	return 0;
}

