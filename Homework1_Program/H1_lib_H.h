/*
 * H1_lib_H.h
 *
 *  Author: Brandon Reid
 *  CSCE1040.001
 *  Lab sec. 007
 *  include libraries header file
 *
 */

#ifndef H1_LIB_H_
#define H1_LIB_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

struct gradebook
{
    char courseID[9]; // char arr for course ID
    char courseTitle[31]; // char arr for course title
    char courseDept[31]; // char arr for course Dept
    char fullName[11]; // char arr for student name
    char major[10]; // char array for major
    string stuID; // unique student ID
    int grades[5]; // array of grades per student
    
}courData[10], stuData[25], enrolled[25];; // array data types for courses and students

#endif // H1_LIB_H