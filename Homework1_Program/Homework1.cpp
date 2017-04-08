#include "H1_func_H.h"

int main()
{
    
    char choice; // hold user menu choice
    int courCount = 0; //count for courses added
    int stuCount = 0; //count for students added
    int scCount = 0; //count for students enrolled in course
    int index = 0; // index count
 
    do
    {
        menu(); // print menu
        cin >> choice; //prompt for choice
        cin.ignore(); // clear cin buffer
        
        switch (choice)
        {
                case '1':
                // add a course to the gradebook
                addCourse(courCount);
                break;
                
                case '2':
                // add a student to the gradebook
                addStudent(stuCount);
                break;
                
                case '3':
                // add a student to a course
                studentToCourse(stuCount, courCount, scCount);
                break;
                
                case '4':
                // add a grade to a student in a  course
                addGrade(courCount, scCount, index);
                break;
                
                case '5':
                // list added courses
                listCourses(courCount);
                break;
                
                case '6':
                // list added students
                listStudents(stuCount);
                break;
            
                case '7':
                // print a list of all students in a course
                listStuCourse(courCount);
                break;
                
                case '8':
                // print average for a student in a course
                avgGrade(courCount, scCount, index);
                break;
                
                case '9':
                // exit statement
                cout << "Good-bye -- Thank you for flying with CSCE1040!" << endl;
                break;
                
                default:
                //if choice 1-9 is not choosen
                cout << "Invalid selection. Please enter choice 1 - 9 " << endl;
        }
    } while (choice != '9'); // exits on choice 9

    return 0;
}

