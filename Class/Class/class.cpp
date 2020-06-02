#include "class.h"
#include <iostream>
#include <fstream>

using namespace std;

void input_student_info(Student *&student)
{
	cout << "Please type in all the student's information." << endl;
	bool check = true;
	string data;
	while (check)
	{
		cout << "Student ID: ";
		getline(cin, data);
		for (int i = 0; i < data.length(); ++i)
		{
			if (!(data[i] - '0' <= 9 && data[i] - '0' >= 0))
				break;
			check = false;
		}
	}
	student->ID = data;
	cout << "Last name: ";
	getline(cin, student->lastname);
	cout << "First name: ";
	getline(cin, student->firstname);
	cout << "Gender: ";
	getline(cin, data);
	while (!(data.compare("Male") == 0 || data.compare("male") == 0 || data.compare("Female") == 0 || data.compare("female") == 0))
	{
		cout << "Enter male or female for gender: ";
		getline(cin, data);
	}
	if (data.compare("Male") == 0 || data.compare("male") == 0)
		student->gender = true;
	else if (data.compare("Female") == 0 || data.compare("female") == 0)
		student->gender = false;
	cout << "Date of birth (DD-MM-YYYY format): ";
	cin >> student->DoB;
	cin.ignore(100, '\n');
	return;
}

void import_students_csv(ifstream &fi, ofstream &fo, string csv_name, int &status)
{
	int stt;
	string data = "", new_file_name = "data/class_" + csv_name + ".txt", class_name = csv_name;
	csv_name = "data/" + csv_name + ".csv";

	fi.open(csv_name.c_str());		//Open the loaded csv file
	fo.open(new_file_name.c_str()); //Create a new csv file to store the data

	if (!(fi.is_open() && fo.is_open()))
	{
		cout << "Failed to open the files." << endl;
		return;
	}
	else
	{
		User *student_users = nullptr; //Student users linked list init

		while (!fi.eof())
		{
			string temp, pwd;
			Student *new_student = new Student; //Init a student object
			//Read every line in the loaded csv file
			getline(fi, data, ',');
			getline(fi, data, ',');
			new_student->ID = data;
			fo << data << endl;
			getline(fi, data, ',');
			new_student->lastname = data;
			fo << data << endl;
			getline(fi, data, ',');
			new_student->firstname = data;
			fo << data << endl;
			getline(fi, data, ',');
			if (data.compare("Male") == 0 || data.compare("male") == 0)
				new_student->gender = true;
			else if (data.compare("Female") == 0 || data.compare("female") == 0)
				new_student->gender = false;
			if (new_student->gender)
				data = "1";
			else
				data = "0";
			fo << data << endl;
			getline(fi, data);
			new_student->DoB = data;
			fo << data << endl;

			//Init user's password
			for (int i = 0; i < new_student->DoB.length(); ++i)
			{
				if (new_student->DoB[i] != '-')
					pwd += new_student->DoB[i];
			}

			//Init an user object (Type 2(student))
			User *new_user = new User;
			new_user->type = 2;
			new_user->password = pwd;			  // Default password: DoB
			new_user->username = new_student->ID; // Default username: student ID

			//Store the current user to the linked list
			if (!student_users)
			{
				student_users = new_user;
			}
			else
			{
				User *cur = student_users;
				while (cur && cur->next)
					cur = cur->next;
				cur->next = new_user;
			}
		}
		fi.close();
		fo.close();

		//Output the linked list to the students.txt
		fo.open("data/students.txt", ios::app);
		User *del;
		while (student_users)
		{
			del = student_users;
			fo << student_users->username << endl;
			fo << student_users->password << endl;
			student_users = student_users->next;
			delete del;
		}
		fo.close();

		//Output the class name to the classes.txt for view_list_classes function
		fo.open("data/classes.txt", ios::app);
		fo << class_name << endl;
		fo.close();
		cout << "Successfully import " << csv_name << endl;
		Sleep(3000);
		status = 1;
	}
	return;
}

void add_new_student(ifstream &fi, ofstream &fo, string class_name, int &status)
{
	bool check = true;
	string data, temp, classname = "data/class_" + class_name + ".txt", pwd;
	Student *new_student = new Student;
	fo.open(classname.c_str(), ios::app);
	fi.open(classname.c_str());
	if (!(fo.is_open() && fi.is_open()))
	{
		cout << "Failed to open the class file." << endl;
		return;
	}
	else
	{
		input_student_info(new_student);

		while (!fi.eof())
			getline(fi, data);

		fo << new_student->ID << endl;
		fo << new_student->lastname << endl;
		fo << new_student->firstname << endl;
		fo << new_student->gender << endl;
		fo << new_student->DoB << endl;
	}
	fi.close();
	fo.close();

	//Create new student's account
	fo.open("students.txt", ios::app);
	fo << new_student->ID << endl;
	for (int i = 0; i < new_student->DoB.length(); ++i)
	{
		if (new_student->DoB[i] != '-')
			pwd += new_student->DoB[i];
	}
	fo << pwd << endl;
	fo.close();
	cout << "Successfully import " << endl;
	Sleep(3000);
	status = 1;
	delete new_student;
	return;
}

void edit_student(ifstream &fi, ofstream &fo, string class_name, string student_id, int &status)
{
	bool check = false;
	int i = 0, j = 0, count = 0;
	string data, backup_file_name = "data/backup_" + class_name + ".txt";
	char *classname = new char[class_name.length() + 16]; // a char* version of the string class_name
	strcpy_s(classname, class_name.length() + 16, ("data/class_" + class_name + ".txt").c_str());

	fi.open(classname);
	fo.open(backup_file_name.c_str());

	if (!(fi.is_open() && fo.is_open()))
		cout << "Failed to open the class csv file" << endl;
	else
	{
		fo << fi.rdbuf(); // Backup the class csv to another csv file

		fo.close();
		fi.close();

		fi.open(classname); //Reopen the original class csv file
		while (!fi.eof())	//check if the student id is in this class
		{
			++i;
			getline(fi, data);
			if (data.compare(student_id) == 0) //If there is the same student id, then break this while loop
			{
				check = true;
				break;
			}
			else
			{
				//Go to next student
				for (j = 0; j < 4; ++j)
					getline(fi, data);
			}
		}
		fi.close();

		if (!check)
		{
			cout << "Couldn't find the student in the given class" << endl;
			return;
		}

		//Edit a student
		Student *new_student = new Student;
		input_student_info(new_student);

		fi.open(classname);
		fo.open("data/temp.txt");

		while (!fi.eof()) //Remove the old student info and replace with the new one
		{
			++count;
			if (count == i)
			{
				// Paste the new student in the right index
				fo << new_student->id << endl;
				fo << new_student->lastname << endl;
				fo << new_student->firstname << endl;
				fo << new_student->gender << endl;
				fo << new_student->DoB << endl;
			}
			else
			{
				for (j = 0; j < 5; ++j)
				{
					getline(fi, data);
					fo << data << endl;
				}
			}
		}
		fi.close();
		fo.close();

		if (remove(classname) == 0 && rename("data/temp.txt", classname) == 0) //Remove the original class csv and rename the temp.csv
		{
			cout << "Sucessfully edited the student!" << endl;
			remove(backup_file_name.c_str());
			status = 1;
			Sleep(3000);
		}
		else
		{
			cout << "Failed to edit the student" << endl;
			remove(classname);
			remove("temp.txt");
			rename(backup_file_name.c_str(), classname);
		}
	}
	delete[] classname;
	return;
}

string remove_student(ifstream &fi, ofstream &fo, string class_name, string student_id)
{
	bool check = false;
	int i = 0, j = 0, count = 0;
	string data, backup_file_name = "data/backup_" + class_name + ".txt", removed_student = "";
	char *classname = new char[class_name.length() + 16]; // a char* version of the string class_name
	strcpy_s(classname, class_name.length() + 16, ("data/class_" + class_name + ".txt").c_str());

	fi.open(classname);
	fo.open(backup_file_name.c_str());
	if (!(fi.is_open() && fo.is_open()))
		cout << "Failed to open the class csv file" << endl;
	else
	{
		fo << fi.rdbuf(); // Backup the class csv to another csv file

		fo.close();
		fi.close();

		fi.open(classname); //Reopen the original class csv file
		while (!fi.eof())	//check if the student id is in this class
		{
			++i;
			getline(fi, data);
			if (data.compare(student_id) == 0) //If there is the same student id, then break this while loop
			{
				check = true;
				break;
			}
			else
			{
				//Go to next student
				for (j = 0; j < 4; ++j)
					getline(fi, data);
			}
		}
		fi.close();

		if (!check)
			cout << "Couldn't find the student in the given class" << endl;
		else
		{
			fi.open(classname);
			fo.open("data/temp.txt");
			check = true;
			while (!fi.eof()) //Remove the student by passing data from old csv file to a new one without that student info
			{
				++count;
				if (i == count && check)
				{
					//If the current student is the student to be removed, output his/her info
					for (j = 0; j < 5; ++j)
					{
						getline(fi, data);
						if (j == 4)
							removed_student += data;
						else
							removed_student += data + " ";
					}
					cout << removed_student << endl;
				}
				else
				{
					for (j = 0; j < 5; ++j)
					{
						getline(fi, data);
						if (data.length() != 1)
							fo << data << endl;
					}
				}
			}
			fi.close();
			fo.close();

			if (remove(classname) == 0 && rename("data/temp.txt", classname) == 0) //Remove the original class csv and rename the temp.csv
			{
				cout << "Sucessfully removed the student!" << endl;
				Sleep(3000);
				remove(backup_file_name.c_str());
				return removed_student;
			}
			else
			{
				cout << "Failed to remove the student" << endl;
				remove(classname);
				remove("temp.txt");
				rename(backup_file_name.c_str(), classname);
			}
			delete[] classname;
		}
	}
	Sleep(3000);
	return "Null";
}

void change_students(ifstream &fi, ofstream &fo, string class_name_A, string class_name_B, string student_id, int &status)
{
	string removed_student = remove_student(fi, fo, class_name_A, student_id);
	string classname = "data/class_" + class_name_B + ".txt";
	string temp;

	if (removed_student != "Null")
	{
		fo.open(classname.c_str(), ios::app);
		if (!fo.is_open())
			cout << "Failed to open class_" << class_name_B << ".txt file" << endl;
		else
		{
			for (int i = 0; i < removed_student.length(); ++i)
			{
				if (removed_student[i].compare(" ") == 0)
					fo << endl;
				else
					fo << removed_student[i];
			}
			cout << "Successfully changed the student " << student_id << " from class " << class_name_A << " to class " << class_name_B << endl;
			Sleep(3000);
			status = 1;
		}
		fo.close();
	}
	else
		cout << "Could not change class for that student" << endl;
	return;
}

void view_list_classes(ifstream &fi)
{
	fi.open("classes.txt");
	if (!fi.is_open())
	{
		cout << "Failed to open the classes file" << endl;
		return;
	}
	else
	{
		cout << "List of classes:" << endl;
		string data;
		while (!fi.eof())
		{
			getline(fi, data);
			cout << data << endl;
		}
	}
	fi.close();
	Sleep(3000);
	return;
}

void view_list_students(ifstream &fi, string class_name)
{
	cout << "Students of class " << class_name << endl;
	class_name = "data/class_" + class_name + ".txt";
	fi.open(class_name.c_str());
	if (!fi.is_open())
	{
		cout << "Failed to open the class csv file" << endl;
		return;
	}
	else
	{
		string data;
		while (!fi.eof())
		{
			for (int i = 0; i < 5; ++i)
			{
				getline(fi, data);
				cout << data << " ";
			}
			cout << endl;
		}
	}
	fi.close();
	Sleep(5000);
	return;
}