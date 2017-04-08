/*
 * H1_func_H.h
 *
 *  Author: Brandon Reid
 *  CSCE1040.001
 *  Lab sec. 007
 *  struct and func header file
 */


#ifndef H1_FUNC_H_
#define H1_FUNC_H_

#include <iostream>
using namespace std;

// gradebook functions
void menu(); // print menu
void addCourse(int &courCount); // add a course to gradebook
void addStudent(int &stuCount); // add a student to gradebook
void listCourses(int &courCount); // list added courses
void listStudents(int &stuCount); // list added students
void studentToCourse(int &stuCount, int &courCount,int &scCount); // add student to course
void addGrade(int &courCount, int &scCount, int &index); // add grade to enrolled student
void avgGrade(int &courCount, int &scCount, int &index); // calculate avg grade
void listStuCourse(int &courCount); // list students enrolled in course

#endif // H1_FUNC_H_