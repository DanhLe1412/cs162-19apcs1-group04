#include <iostream>
#include <fstream>
#include <string>
#include "class.h"

using namespace std;

void import_students_csv(ifstream &fi, ofstream &fo, string csv_name)
{
	int stt;
	string data, temp, new_file_name = "class_" + csv_name, pwd;

	fi.open(csv_name, ios::in); //Import a .csv file
	fo.open(new_file_name, ios::app);

	if (!(fi.is_open() && fo.is_open()))
	{
		cout << "Failed to open the files." << endl;
		return;
	}
	else
	{
		//new csv_file first line: class_name
		for (int i = 0; i < csv_name.length(); ++i)
		{
			if (csv_name[i] == '.')
				break;
			else
				fo << csv_name[i];
		}
		fo << '\n';

		while (!fi.eof())
		{
			Student *new_student = new Student; //Init a student object

			getline(fi, data, ',');
			stt = stoi(data) - 1;
			temp += data + ',';
			getline(fi, data, ',');
			new_student->ID = stoi(data);
			getline(fi, data, ',');
			new_student->lastname = data;
			temp += data + ',';
			getline(fi, data, ',');
			new_student->firstname = data;
			temp += data + ',';
			getline(fi, data, ',');
			if (data.compare("Male") == 0 || data.compare("male") == 0)
				new_student->gender = true;
			else if (data.compare("Female") == 0 || data.compare("female") == 0)
				new_student->gender = false;
			temp += data + ',';
			getline(fi, data);
			new_student->DoB = data;
			temp += data;

			fo << temp << '\n'; //Copy the whole to the new csv file

			for (int i = 0; i < new_student->DoB.length(); ++i)
			{
				if (new_student->DoB[i] != '-')
					pwd += new_student->DoB[i];
			}

			//Init an user object (Type 2(student))
			User *new_user = new User;
			new_user->type = 2;
			new_user->password = pwd;											 // Default password: DoB
			new_user->username = new_student->firstname + new_student->lastname; // Default username: first + last name

			delete new_student;
			delete new_user;
		}
		fi.close();
		fo.close();
	}
	return;
}

void add_new_student(ifstream &fi, ofstream &fo, string class_name)
{
	int stt;
	bool check = true;
	string data = '', temp, gender;
	fi.open(class_name, ios::app);
	fo.open(class_name, ios::app);
	if (!(fi.is_open() && fo.is_open()))
	{
		cout << "Failed to open the class file." << endl;
		return;
	}
	else
	{
		Student *new_student = new Student;
		while (check)
		{
			cout << "Student ID: ";
			cin >> data;
			for (int i = 0; i < data.length(); ++i)
			{
				if (!(data - '0' <= 9 && data - '0' >= 0))
					break;
				check = false;
			}
		}
		new_student->ID = stoi(data);
		cout << "Last name: ";
		getline(cin, new_student->lastname);
		cout << "First name: ";
		getline(cin, new_student->firstname);
		cout << cout << "Gender: ";
		getline(cin, data);
		while (!(data.compare("Male") == 0 || data.compare("male") == 0 || data.compare("Female") == 0 || data.compare("female") == 0))
		{
			cout << "Enter male or female for gender: ";
			getline(cin, data);
			strcpy(gender, data);
		}
		if (data.compare("Male") == 0 || data.compare("male") == 0)
			new_student->gender = true;
		else if (data.compare("Female") == 0 || data.compare("female") == 0)
			new_student->gender = false;
		cout << "Date of birth (DD/MM/YYYY format): ";
		cin >> new_student->DoB;

		while (!fi.eof())
			getline(fi, data);
		for (int i = 0; i < data.length(); ++i)
		{
			if (data[i] == ',')
				break;
			temp += data[i];
		}
		stt = stoi(temp);

		fo << stt << "," << new_student->ID << ',' << new_student->lastname << "," << new_student->firstname << ","
		   << gender << "," << new_student->DoB << '\n';
	}
	return;
}

void edit_student(ifstream &f, string class_name, )
{

	return;
}

void remove_student(ifstream &fi, ofstream &fo, string class_name, string student_id)
{
	bool check = false;
	int counter = 0, i = 0;
	string data, backup_file_name = 'backup_' + class_name;
	class_name += '.csv';

	fi.open(class_name);
	fo.open(backup_file_name);
	if (!(fi.open() && fo.open()))
		cout << "Failed to open the class csv file" << endl;
	else
	{
		fo << fi.rdbuf(); // Backup the class csv to another csv file
		fo.close();
		while (!fi.eof()) //check if the student id is in this class
		{
			getline(fi, data, ',');
			getline(fi, data, ',');
			if (stoi(data) == stoi(student_id))
			{
				check = true;
				break;
			}
			else
				getline(fi, data);
			++counter;
		}
		fi.close();
		if (!check)
		{
			cout << "Couldn't find the student in the given class" << endl;
			return;
		}
		else
		{
			fi.open(class_name);
			fo.open("temp.csv") << endl;
			while (!fi.eof()) //Remove the student by passing data from old csv file to a new one without that student info
			{
				if (counter == i)
					continue;
				getline(fi, data);
				fo << data;
			}
			if (remove(class_name) == 0 && rename("temp.csv", class_name) == 0) //Remove the original class csv and rename the temp.csv
			{
				cout << "Sucessfully remove the student" << endl;
				remove(backup_file_name);
			}
			else
			{
				cout << "Failed to remove the student" << endl;
				remove(class_name);
				remove("temp.csv");
				rename(backup_file_name, class_name);
			}
			fi.close();
			fo.close();
		}
	}
	return;
}

void change_students(ifstream &f, string class_name_A, string class_name_B)
{

	return;
}

void view_list_classes(string class_name)
{

	return;
}

void view_list_students(string class_name)
{

	return;
}
