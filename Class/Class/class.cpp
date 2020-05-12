
#include "class.h"

using namespace std;
/*
void input_student_info(Student *&student)
{
	cout << "Please type in all the student's information." << endl;
	bool check = true;
	string data;
	while (check)
	{
		cout << "Student ID: ";
		cin >> data;
		for (int i = 0; i < data.length(); ++i)
		{
			if (!(data[i] - '0' <= 9 && data[i] - '0' >= 0))
				break;
			check = false;
		}
	}
	student->ID = stoi(data);
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
	return;
}
*/
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
			if (new_student->gender)
				temp += '1,';
			else
				temp += '0,';
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
/*
void add_new_student(ifstream &fi, ofstream &fo, string class_name)
{
	int stt = 0;
	bool check = true;
	string data, temp;
	fi.open(class_name);
	fo.open(class_name, ios::app);
	if (!(fi.is_open() && fo.is_open()))
	{
		cout << "Failed to open the class file." << endl;
		return;
	}
	else
	{
		Student *new_student = new Student;
		input_student_info(new_student);

		while (!fi.eof())
		{
			++stt;
			getline(fi, data);
		}

		fo << ++stt << "," << new_student->ID << ',' << new_student->lastname << "," << new_student->firstname << ","
		   << new_student->gender << "," << new_student->DoB << '\n';
	}
	fi.close();
	fo.close();
	return;
}

void edit_student(ifstream &fi, ofstream &fo, string class_name, string student_id)
{
	bool check = false;
	int stt = 0, i = 0;
	string data, backup_file_name = "backup_" + class_name;
	char *classname = new char[class_name.length() + 1 + 4]; // a char* version of the string class_name, +4 for ".csv"
	strcpy(classname, (class_name + ".csv").c_str());

	fi.open(class_name);
	fo.open(backup_file_name);
	if (!(fi.is_open() && fo.is_open()))
		cout << "Failed to open the class csv file" << endl;
	else
	{
		fo << fi.rdbuf(); // Backup the class csv to another csv file
		fo.close();
		while (!fi.eof()) //check if the student id is in this class
		{
			++stt;
			getline(fi, data, ',');
			getline(fi, data, ',');
			if (stoi(data) == stoi(student_id))
			{
				check = true;
				break;
			}
			else
				getline(fi, data);
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
		fi.open(class_name);
		fo.open("temp.csv");
		while (!fi.eof()) //Remove the old student info and replace with the new one
		{
			++i;
			if (i == stt)
			{
				fo << stt << "," << new_student->ID << ',' << new_student->lastname << "," << new_student->firstname << ","
				   << new_student->gender << "," << new_student->DoB << '\n';
				continue;
			}
			getline(fi, data);
			fo << data;
		}
		if (remove(classname) == 0 && rename("temp.csv", classname) == 0) //Remove the original class csv and rename the temp.csv
		{
			cout << "Sucessfully remove the student" << endl;
			remove(backup_file_name.c_str());
		}
		else
		{
			cout << "Failed to edit the student" << endl;
			remove(classname);
			remove("temp.csv");
			rename(backup_file_name.c_str(), classname);
		}
		fi.close();
		fo.close();
	}
	delete[] classname;
	return;
}

string remove_student(ifstream &fi, ofstream &fo, string class_name, string student_id)
{
	bool check = false;
	int stt = 0, i = 0;
	string data, backup_file_name = "backup_" + class_name, removed_student;

	fi.open(class_name);
	fo.open(backup_file_name);
	if (!(fi.is_open() && fo.is_open()))
		cout << "Failed to open the class csv file" << endl;
	else
	{
		fo << fi.rdbuf(); // Backup the class csv to another csv file
		fo.close();
		while (!fi.eof()) //check if the student id is in this class
		{
			++stt;
			getline(fi, data, ',');
			getline(fi, data, ',');
			if (stoi(data) == stoi(student_id))
			{
				getline(fi, data);
				check = true;
				break;
			}
			else
				getline(fi, data);
		}
		fi.close();
		if (!check)
			cout << "Couldn't find the student in the given class" << endl;
		else
		{
			char *classname = new char[class_name.length() + 1 + 4]; // a char* version of the string class_name, +4 for ".csv"
			strcpy(classname, (class_name + ".csv").c_str());
			fi.open(class_name);
			fo.open("temp.csv");
			while (!fi.eof()) //Remove the student by passing data from old csv file to a new one without that student info
			{
				++i;
				getline(fi, data);
				if (i == stt)
					removed_student = data;
				else
					fo << data;
			}
			if (remove(classname) == 0 && rename("temp.csv", classname) == 0) //Remove the original class csv and rename the temp.csv
			{
				cout << "Sucessfully remove the student" << endl;
				remove(backup_file_name.c_str());
				return removed_student;
			}
			else
			{
				cout << "Failed to remove the student" << endl;
				remove(classname);
				remove("temp.csv");
				rename(backup_file_name.c_str(), classname);
			}
			fi.close();
			fo.close();
			delete[] classname;
		}
	}
	return "Null";
}

void change_students(ifstream &fi, ofstream &fo, string class_name_A, string class_name_B, string student_id)
{
	string removed_student = remove_student(fi, fo, class_name_A, student_id);
	if (removed_student != "Null")
	{
		fo.open(class_name_B, ios::app);
		if (!(fi.is_open() && fo.is_open()))
		{
			cout << "Failed to open " << class_name_B << "'s csv file" << endl;
			return;
		}
		else
		{
			fo << removed_student << '\n';
			cout << "Successfully change the student " << student_id << " from class " << class_name_A << "to " << class_name_B << endl;
		}
		fo.close();
	}
	return;
}

void view_list_classes(ifstream &fi, string class_name)
{
	fi.open(class_name);
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
			getline(fi, data);
			cout << data << endl;
		}
	}
	fi.close();
	return;
}

void view_list_students(ifstream &fi, string class_name)
{
	fi.open(class_name);
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
			getline(fi, data, ',');
			cout << data << ". "; //stt
			getline(fi, data, ',');
			cout << data << " "; //Last name
			getline(fi, data, ',');
			cout << data << endl; //first name
			getline(fi, data);	  // goto next line
		}
	}
	fi.close();
	return;
}
*/