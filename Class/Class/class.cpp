#include "class.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void import_students_csv(ifstream& f, string csv_name)
{
	//Open existed csv file or just simply create a new one.
	f.open(csv_name, ios::in);

	//Init a new class object to store the new csv file.
	Class *new_class = new Class;
	new_class->class_name = csv_name;

	string data;
	while (!f.eof())
	{
		//Init a student object
		int stt;
		Student *new_student = new Student;
		getline(f, data, ',');
		stt = stoi(data) - 1;
		getline(f, data, ',');
		new_student->lastname = data;
		getline(f, data, ',');
		new_student->firstname = data;
		getline(f, data, ',');
		if (data.compare("Male") == 0 || data.compare("male") == 0)
			new_student->gender = true;
		else
			new_student->gender = false;
		getline(f, data);
		new_student->DoB = data;
		new_student->student_class = new_class;

		//Init an user object (Type 2(student))
		User* new_user = new User;
		new_user->type = 2;
		new_user->password = "12345678"; // Default password
		new_user->username = new_student->firstname + new_student->lastname; // Default username
		new_class->student_in_class[stt] = new_user; //Student class assignment
	}	
	return;
}