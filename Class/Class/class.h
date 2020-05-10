#pragma once
#ifndef _Class_H_
#define _Class_H_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct User
{
	string password;
	string username;
	int type = -1; //(default: -1)(1: staff, 2 : lecturer, 3 : student)
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
	int ID;
	string DoB;
	bool gender;
	string list_course[20];
	Class* student_class;
};

void import_students_csv(ifstream &fi, ofstream &fo, string csv_name);
void add_new_student(ifstream &fi, ofstream &fo, string class_name);
void edit_student(ifstream &f, string class_name);
void remove_student(ifstream &fi, ofstream &fo, string class_name, string student_id);
void change_students(ifstream &f, string class_name_A, string class_name_B);
void view_list_classes(string class_name);
void view_list_students(string class_name);

#endif