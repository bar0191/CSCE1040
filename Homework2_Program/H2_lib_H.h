/*
 * H2_lib_H.h
 *
 *  Author: Brandon Reid
 *  CSCE1040.001
 *  Lab sec. 007
 *  include libraries header file
 *
 */

#ifndef H2_LIB_H_
#define H2_LIB_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>
using namespace std;

struct courseGradebook
{
    char courseID[9]; // char arr for course ID
    char courseTitle[31]; // char arr for course title
    char courseDept[31]; // char arr for course
    int stuAssoc; // number of students associated with each course MAKE THIS AN ARRAY
}courData[10];

struct studentGradebook
{
    char fullName[11]; // char arr for student name
    char major[10]; // char array for major
    string stuID; // unique student ID
    int grades[5]; // array of grades per student
}stuData[25];


#endif // H2_LIB_H