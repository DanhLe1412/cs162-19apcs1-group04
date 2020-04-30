#pragma once
#ifndef _Class_H_
#define _Class_H_
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
	string password;
	string username;
	int type = -1;
};

struct Class {
	string class_name;
	User* student_in_class[50];
};

struct Student {
	string lastname;
	string firstname;
	string DoB;
	bool gender;
	string list_course[20];
	Class* student_class;
};

void import_students_csv(ifstream& f, string csv_name);
void manual_add_students(ifstream& f, string class_name);
void edit_student(ifstream& f, string class_name);
void remove_student(ifstream& f, string class_name);
void change_student(ifstream& f, string class_name);
void view_list_classes();
void view_list_students(string class_name);

#endif // !_Class_H_
