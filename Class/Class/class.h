#pragma once
#ifndef _Class_H_
#define _Class_H_
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct User
{
	string username;
	string password;
	int type = -1; //(default: -1)(1: staff, 2 : lecturer, 3 : student)
	User *next = nullptr;
};

struct Class
{
	string class_name;
	User *student_in_class[50];
};

struct Student
{
	string lastname;
	string firstname;
	string ID;
	string DoB;
	bool gender; // 0: Female, 1: Male
	string list_course[20];
	Class *student_class;
};

void input_student_info(Student *&student);
void import_students_csv(ifstream &fi, ofstream &fo, string csv_name, int& status);
void add_new_student(ifstream& fi, ofstream& fo, string class_name, int& status);
void edit_student(ifstream &fi, ofstream &fo, string class_name, string student_id);
string remove_student(ifstream &fi, ofstream &fo, string class_name, string student_id);
void change_students(ifstream &fi, ofstream &fo, string class_name_A, string class_name_B, string student_id);
void view_list_classes(ifstream &fi);
void view_list_students(ifstream &fi, string class_name);

#endif