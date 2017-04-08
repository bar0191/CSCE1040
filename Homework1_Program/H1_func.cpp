#include "H1_lib_H.h"
#include "H1_func_H.h"

void menu()
{
        //print menu
    	cout << "==================GRADEBOOK-MENU==================\n";
    	cout << "| 1. Add a new course                            |\n"
             << "| 2. Add a new student                           |\n"
             << "| 3. Add a student to a course                   |\n"
             << "| 4. Add grades for a student in a course        |\n"
             << "| 5. Print a list of all courses                 |\n"
             << "| 6. Print a list of all students                |\n"
             << "| 7. Print a list of all students in a course    |\n"
             << "| 8. Compute average for a student in a course   |\n"
             << "| 9. exit                                        |\n";
    	cout << "==================================================\n";
    	cout << "Cmd> ";
    	return;
}

void addCourse(int &courCount)
{
    // prompt for course ID
    cout << "ENTER COURSE ID> ";
    cin.getline(courData[courCount].courseID, 10);
    
    // loop through course data for existing course ID
    for (int i = 0; i < courCount; i++)
    {
        //compare input with currently stored course IDs
        if (strcmp(courData[courCount].courseID, courData[i].courseID) ==0)
        {
            //output error if course exists
            cout << "***ERROR***: " << courData[i].courseID << " is already added" << endl;
            return;
        }
    }
    
    // prompt for and enter in course data
    cout << "ENTER COURSE NAME> ";
    cin.getline(courData[courCount].courseTitle, 31);
    
    cout << "ENTER DEPARTMENT NAME> ";
    cin.getline(courData[courCount].courseDept, 31);
    
    cout << courData[courCount].courseID << " has been added" << endl;
    
    courCount++; // take count on how many courses are added
}

void addStudent(int &stuCount)
{
    //promt for and enter in student data
    cout << "ENTER STUDENT NAME> ";
    cin.getline(stuData[stuCount].fullName, 11);
    
    //loop through existing student data
    for (int i = 0; i < stuCount; i++)
    {
        // compare input with currently stored student names
        if (strcmp(stuData[stuCount].fullName, stuData[i].fullName) == 0)
        {
            // output error if student exists
            cout << "***ERROR***: " << stuData[i].fullName << " is already enrolled as " << stuData[i].stuID << endl;
            return;
        }
    }
    
    // prompt for student major
    cout << "ENTER STUDENT MAJOR> ";
    cin.getline(stuData[stuCount].major, 10);
    
    // assign unique ID to student added
    stuData[stuCount].stuID = "ID001";
    stuData[stuCount].stuID[4] = (stuData[stuCount].stuID[4] + stuCount);

    // confirm student ID has been added to student
    cout << "Added: " << stuData[stuCount].fullName << " " << stuData[stuCount].stuID << endl;
    
    stuCount++; // count on each student added
}

void listCourses(int &courCount)
{
    // title courses
	cout << "COURSES" << endl;
	cout << "-------" << endl;

    // loop through existing courses and output added
	for (int i = 0; i < courCount; i++)
	{
        // to column align --> setw(# of spaces - length of first string - length of second string)
        cout << courData[i].courseID << "  " << courData[i].courseTitle
             << setw(30 - (unsigned)strlen(courData[i].courseID) - (unsigned)strlen(courData[i].courseTitle)) << "" << courData[i].courseDept << endl;
	}
	return;
}

void listStudents(int &stuCount)
{
    // title students
	cout << "STUDENTS" << endl;
	cout << "--------" << endl;

    // loop through existing students and output added
	for (int i = 0; i < stuCount; i++)
	{
        // column align same as above
		cout << stuData[i].stuID << setw(2) << "" << stuData[i].fullName << left
             << setw(33 - sizeof(stuData[i].stuID) - (unsigned)strlen(stuData[i].fullName)) << "" << stuData[i].major << endl;
	}
	return;
}

void studentToCourse(int &stuCount, int &courCount, int &scCount)
{
    char stuName[11];
    char courID[9];
    string studentID;
    
    // prompt for student
    cout << "ENTER STUDENT NAME> ";
    cin.getline(enrolled[scCount].fullName, 11);
    
    // prompt for course to enroll
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    //loop through student data
    for(int i = 0; i <= stuCount; i++)
    {
        // compare input with existing student names
        if(strcmp(enrolled[scCount].fullName, stuData[i].fullName) == 0)
        {
            // enroll student into course area
            enrolled[scCount].stuID = stuData[i].stuID;
            
            //loop through course data
            for(int j = 0; j <= courCount; j++)
            {
                // compare input with existing course data
                if(strcmp(courID, courData[j].courseID) == 0)
                {
                    // confirm student has been added to course
                    cout << "Added to " << courData[j].courseID << " -- " << enrolled[scCount].fullName << endl;
                    scCount++; // count students added to course
                    return;
                }
            }
        }
    }
}

void addGrade(int &courCount, int &scCount, int &index)
{
    char courID[9];
    char stuName[11];
    int grade;
    int maxGrades = 5;
    
    //prompt for course ID
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    //prompt for student name
    cout << "ENTER STUDENT NAME> ";
    cin.getline(stuName, 11);
    
    // loop through existing course data
    for (int i = 0; i <= courCount; i++)
    {
        // compare input with existing course ID
        if (strcmp(courID, courData[i].courseID) == 0)
        {
            // loop through existing enrolled students
            for (int j = 0; j <= scCount; j++)
            {
                // compare input with existing enrolled students
                if(strcmp(stuName, enrolled[j].fullName) == 0)
                {
                    // while less then 5 grades have been entered
                    while (index < maxGrades)
                    {
                        //prompt for grade
                        cout << "ENTER GRADE(-1 to exit)> ";
                        cin  >> grade;
                        
                        // if newline(ENTER) stop input, break
                        if (grade == -1)
                        {
                            break;
                        }
                        // add grade to enrolled student
                        enrolled[j].grades[index] = grade;
                        index++; // index counter
                    }
                    //confirm grades have been added to enrolled student
                    cout << "ADDED GRADES: " << enrolled[j].fullName << " " << courData[i].courseID << " ";
                    
                    //loop to output entered grades
                    for (int h = 0; h < index; h++)
                    {
                        cout << enrolled[j].grades[h] << " ";
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
}

void avgGrade(int &courCount, int &scCount, int &index)
{
    char courID[9];
    string stuID;
    int avgGrade = 0;
    int sumGrade = 0;
    
    //prompt for course ID
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    //prompt for student UD
    cout << "ENTER STUDENT ID> ";
    getline(cin, stuID);
    
    // loop through existing course data
    for (int i = 0; i <= courCount; i++)
    {
        // compare input with existing course IDs
        if (strcmp(courID, courData[i].courseID) == 0)
        {
            // loop through existing enrolled students
            for (int j = 0; j <= scCount; j++)
            {
                // compare input with existing student IDs in the course
                if (stuID.compare(enrolled[j].stuID) == 0)
                {
                    // compute average of entered grades
                    for (int h = 0; h < index; h++)
                    {
                        sumGrade = sumGrade + enrolled[j].grades[h];
                    }
                    
                    avgGrade = sumGrade/index;
                    
                    //output entered grades
                    cout << "AVERAGE: ";
                    
                    for (int l = 0; l < index; l++)
                    {
                        cout << " " << enrolled[j].grades[l];
                    }
                    
                    cout << " = " << avgGrade << endl;
                    return;
                }
            }
        }
    }
}

void listStuCourse(int &courCount)
{
    char courID[9];
    
    // prompt for course ID
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    // loop through existing course Data
    for (int i = 0; i <= courCount; i++)
    {
        // compare input to existing course data
        if (strcmp(courID, courData[i].courseID) == 0)
        {
            // output enrolled students in course
            cout << enrolled[i].stuID << "  " << enrolled[i].fullName << endl;
            return;
        }
    }
}










