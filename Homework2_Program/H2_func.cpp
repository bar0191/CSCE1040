/*
 * H2_func.cpp
 *
 *  Author: Brandon Reid
 *  CSCE1040.001
 *  Lab sec. 007
 *  consists of functions for each menu option
 *
 *
 */

#include "H2_lib_H.h"
#include "H2_func_H.h"

void menu()
{
        //print menu
    	cout << "===================GRADEBOOK-MENU==================\n";
    	cout << "|  1. Add a new course                            |\n"
             << "|  2. Add a new student                           |\n"
             << "|  3. Add a student to a course                   |\n"
             << "|  4. Add grades for a student in a course        |\n"
             << "|  5. Print a list of all courses                 |\n"
             << "|  6. Print a list of all students                |\n"
             << "|  7. Print a list of all students in a course    |\n"
             << "|  8. Compute average for a student in a course   |\n"
             << "|  9. Load Grade Book                             |\n"
             << "| 10. Store Grade Book                            |\n"
             << "| 11. Exit                                        |\n";
    	cout << "===================================================\n";
    	cout << "Cmd> ";
}

void newLine()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addCourse(int &courCount)
{
    int maxCourses = 10;
    
    if (courCount < maxCourses)
    {
        // prompt for course ID
        cout << "ENTER COURSE ID> ";
        cin.getline(courData[courCount].courseID, 10);
    
        // loop through course data for existing course ID
        for (int i = 0; i < courCount; i++)
        {
            //compare input with currently stored course IDs
            if (strcmp(courData[courCount].courseID, courData[i].courseID) == 0)
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
    else
    {
        cout << "***ERROR***: You have entered the maximum number of " << courCount << " courses." << endl;
        return;
    }
}

void addStudent(int &stuCount)
{
    int maxStudents = 25;
    
    if (stuCount < maxStudents)
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
        
        if (stuCount < 9)
        {
            // assign unique ID to student added
            stuData[stuCount].stuID = "ID001";
            stuData[stuCount].stuID[4] = (stuData[stuCount].stuID[4] + stuCount);
            
        }
        // ID010 = ID00: for some reason
        if (stuCount > 10 && stuCount < 19)
        {
            stuData[stuCount].stuID = "ID010";
            stuData[stuCount].stuID[4] = (stuData[stuCount].stuID[4] + (stuCount - 9));
        }
        // ID 020 is just not showing up 
        if (stuCount > 19)
        {
            stuData[stuCount].stuID = "ID020";
            stuData[stuCount].stuID[4] = (stuData[stuCount].stuID[4] + (stuCount - 19));
        }
        // confirm student ID has been added to student
        cout << "Added: " << stuData[stuCount].fullName << " " << stuData[stuCount].stuID << endl;
    
        stuCount++; // count on each student added
    }
    else
    {
        cout << "***ERROR***: You have Entered the maximum number of " << stuCount << " students. " << endl;
        return;
    }
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
             << setw(30 - (unsigned)strlen(courData[i].courseID) - (unsigned)strlen(courData[i].courseTitle)) << ""
             << courData[i].courseDept << endl;
	}
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
}

void studentToCourse(int &stuCount, int &courCount, int &scCount)
{
    char stuName[11];
    char courID[9];
    string studentID;
    
    // prompt for student
    cout << "ENTER STUDENT NAME> ";
    cin.getline(stuName, 11);
    
    // prompt for course to enroll
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    //loop through student data
    for (int i = 0; i < stuCount; i++)
    {
        // compare input with existing student names
        if(strcmp(stuName, stuData[i].fullName) == 0)
        {
            
            //loop through course data
            for (int j = 0; j < courCount; j++)
            {
                // compare input with existing course data
                if(strcmp(courID, courData[j].courseID) == 0)
                {
                    // confirm student has been added to course
                    courData[i].stuAssoc = i;
    
                    cout << "Added to " << courData[j].courseID << " -- " << stuData[i].fullName << endl;
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
    char grade[4] = {0}; // string of ints read in by user
    char eaChar[4] = {0}; // holds each individual character in string
    int gradeValue; // actual grade value
    int grade_length = 0; // string length of the grade
    int maxGrades = 5; // max grades allowed per student
    
    
    //prompt for course ID
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    //prompt for student name
    cout << "ENTER STUDENT NAME> ";
    cin.getline(stuName, 11);
    
    // loop through existing course data
    for (int i = 0; i < courCount; i++)
    {
        // compare input with existing course ID
        if (strcmp(courID, courData[i].courseID) == 0)
        {
            // loop through existing enrolled students
            for (int j = 0; j < scCount; j++)
            {
                // compare input with existing enrolled students
                if(strcmp(stuName, stuData[j].fullName) == 0)
                {
                    // while less then 5 grades have been entered
                    while (index < maxGrades)
                    {
                        // prompt for grade
                        cout << "ENTER GRADE> ";
                        cin.getline(grade, 4);
                        grade_length = (unsigned) strlen(grade);
                        
                        if (grade_length == 0) // if string length is zero, break;
                        {
                            break;
                        }
                        
                        eaChar[0] = grade[0];
                        
                        // conversion of string to integer
                        for (int i = 0; (grade[i] != '\0'); ++i)
                        {
                            eaChar[0] = grade[i];
                            
                            if (eaChar[0] != '0')
                            {
                                // use atoi to convert each character
                                if (atoi(eaChar))
                                {
                                    gradeValue = atoi(eaChar) * pow(10.0, (grade_length-i-1));
                                }
                                else
                                {
                                    cout << "***ERROR***: INVALID INPUT. " << endl;
                                    break;
                                }
                            }
                        }
                        
                        stuData[j].grades[index] = gradeValue;
                        index++; // index counter
                    }
                    //confirm grades have been added to enrolled student
                    cout << "ADDED GRADES: " << stuData[j].fullName << " " << courData[i].courseID << " ";
                    
                    //loop to output entered grades
                    for (int h = 0; h < index; h++)
                    {
                        cout << stuData[j].grades[h] << " ";
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
    
    //prompt for student ID
    cout << "ENTER STUDENT ID> ";
    getline(cin, stuID);
    
    // loop through existing course data
    for (int i = 0; i < courCount; i++)
    {
        // compare input with existing course IDs
        if (strcmp(courID, courData[i].courseID) == 0)
        {
            // loop through existing enrolled students
            for (int j = 0; j < scCount; j++)
            {
                // compare input with existing student IDs in the course
                if (stuID.compare(stuData[j].stuID) == 0)
                {
                    // compute average of entered grades
                    for (int h = 0; h < index; h++)
                    {
                        sumGrade = sumGrade + stuData[j].grades[h];
                    }
                    
                    avgGrade = sumGrade/index;
                    
                    //output entered grades
                    cout << "AVERAGE: ";
                    
                    for (int l = 0; l < index; l++)
                    {
                        cout << " " << stuData[j].grades[l];
                    }
                    
                    cout << " = " << avgGrade << endl;
                    return;
                }
            }
        }
    }
}

void listStuCourse(int &courCount , int &scCount)
{
    char courID[9];
    
    // prompt for course ID
    cout << "ENTER COURSE ID> ";
    cin.getline(courID, 9);
    
    // loop through existing course Data
    for (int i = 0; i < courCount; i++)
    {
        // compare input to existing course data
        if (strcmp(courID, courData[i].courseID) == 0)
        {
            for (int j = 0; j < scCount; j++)
            {
                cout << stuData[courData[j].stuAssoc].stuID << " " << stuData[courData[j].stuAssoc].fullName << endl;
            }
            return;
        }
    }
}

void readFile(int &courCount, int &stuCount) //reading in a file isn't working properly
{
    string fileName;
    ifstream fin;
    
    cout << "ENTER FILENAME> ";
    getline(cin, fileName);
    
    fin.open("fileName");
    
    if (fin.fail())
    {
        cout << "***ERROR***: File does not exist: " << fileName << endl;
        return;
    }
    while (!fin.eof())
    {
        for (int i = 0; i <= courCount; i++)
        {
            fin >> courData[i].courseID >> courData[i].courseTitle >> courData[i].courseDept;
        }
        for (int i = 0; i <= stuCount; i++)
        {
            fin >> stuData[i].stuID >> stuData[i].fullName;
        }
    }
    cout << "Data successfully initialized from: " << fileName << endl;
    
    fin.close();
    cout << "Input file closed: " << fileName << endl;
    
}

void writeFile(int &courCount, int &stuCount, int &scCount) // don't know how to output students with certain courses yet
{
    string fileName;
    ofstream fout;
    
    cout << "ENTER FILENAME> ";
    getline(cin, fileName);
    
    fout.open("fileName");
    
    if (fout.fail())
    {
        cout << "***ERROR***: File does not exist: " << fileName << endl;
        return;
    }
    
    cout << "Output file opened: " << fileName << endl;
    
    // write course data
    for (int i = 0; i < courCount; i++)
    {
        fout << courData[i].courseID << "  " << courData[i].courseTitle
             << setw(30 - (unsigned)strlen(courData[i].courseID) - (unsigned)strlen(courData[i].courseTitle)) << ""
             << courData[i].courseDept << endl;
    }
    
    fout << endl;
    
    // write student data
    for (int i = 0; i < stuCount; i++)
    {
        fout << stuData[i].stuID << setw(2) << "" << stuData[i].fullName << left
             << setw(33 - sizeof(stuData[i].stuID) - (unsigned)strlen(stuData[i].fullName)) << ""
             << stuData[i].major << endl;
    }
    
    fout << endl;
    
    cout << "Data successfully written to file: " << fileName << endl;
    
    fout.close();
    cout << "Output file closed: " << fileName << endl;
}






