#include "define_cli_menu.h"
#include "class.h"

void staff_cli(){
	cout << "[1]: import student as csv file" << endl;
	cout << "[2]: add new student to class" << endl;
	cout << "[3]: Edit an existing student" << endl;
	cout << "[4]: View list of classes" << endl;
	cout << "[5]: View list of students in a class" << endl;
	cout << "[6]: Academic yead" << endl;
	cout << "[7]: import course" << endl;
	cout << "[8]: Manually add new course" << endl;
	cout << "[9]: Remove a course" << endl;
	cout << "[10]:  Remove student in course" << endl;
	cout << "[11]: Add student in course" << endl;
	cout << "[12]: View list course" << endl;
	cout << "[13]: Lecturers" << endl;
}

void student_cli(){
	cout << "[14]: Check-in" << endl;
	cout << "[15]: View check-in result" << endl;
	cout << "[16]: View schedules" << endl;
	cout << "[17]: View scores of a course" << endl;

}

void lecturer_cli(){
	cout << "[18]: View list course in current semester" << endl;
	cout << "[19]: View list of students of a course" << endl;
	cout << "[20]: View attendance list of a course" << endl;
	cout << "[21]: Edit an attendance" << endl;
	cout << "[22]: Import scoreboard of a course" << endl;
	cout << "[23]: Edit grade of a student" << endl;
	cout << "[24]: View scoreboard" << endl;

}

void Print_home_page(int& i, int type){
	cout << "This is Home page of Program" << endl;
	cout << "what do you want ??" << endl; 
	cout << "[0]: View Profile" << endl;
	switch (type)
		{
		case 1:
			staff_cli();
			break;
		case 2:
			student_cli();
			break;	
		case 3:
			staff_cli();
			break;
		default:
			cout << "---" << endl;
			break;
		}
	cout << "[30]: Change Password" << endl;
	cout << "[32]: Log out" << endl;
	cin >> i;
}

void home_cli(int type){
	int checksign = 0;
	while(checksign==0){
		int i = 0;
		system ("CLS");		
		Print_home_page(i,type);
		switch (i)
		{
		case 1:
		{
			int check_import = 0;
			ifstream fin;
			ofstream fout;
			system("ls -a");
			string file_csv;
			while (check_import == 0)
			{
				cout << "choose file import (ex: 19Apcs.csv): ";
				cin >> file_csv;
				cin.ignore(100, '\n');
				import_students_csv(fin, fout, file_csv, check_import);
			}
			break;
		}
		case 2:
		{
			//add new student to class
			int check_add = 0;
			ifstream fin;
			ofstream fout;
			ifstream class_file;
			class_file.open("classes.txt");
			if (class_file.is_open())
			{
				string file_class;
				while(!class_file.eof()){
					class_file >> file_class;
					cout << file_class << endl;		
				}

				while (check_add == 0)
				{
					cout << "choose class (ex: 19apcs): ";
					cin >> file_class;
					cin.ignore(100, '\n');
					add_new_student(fin, fout, file_class, check_add);
				}
			}
			break;
		}
		case 3:
		{
			//Edit an existing student
			break;
		}
		case 4:
		{	//View list of classes
			break;
		}
		case 5:
		{	// View list of students in a class
			break;
		}
		case 6:
		{	//Academic yead
			break;
		}
		case 7:
		{	// import course
			break;
		}
		case 8:
		{	//Manually add new course
			break;
		}
		case 9:
		{	// Remove a course
			break;
		}
		case 10:
		{	//Remove student in course
			break;
		}
		case 11:
		{	//Add student in course
			break;
		}
		case 12:
		{
			//View list course
			break;
		}
		case 13:
		{	//Lecturers
			break;
		}
		case 14:
		{	// Check-in
			break;
		}
		case 15:
		{	//View check-in result
			break;
		}
		case 16:
		{	// View schedules
			break;
		}
		case 17:
		{	//View scores of a course
			break;
		}
		case 18:
		{	//View list course in current semester
			break;
		}
		case 19:
		{	// View list of students of a course
			break;
		}
		case 20:
		{	// View attendance list of a course
			break;
		}
		case 21:
		{	//Edit an attendance
			break;
		}
		case 22:
		{
			// Import scoreboard of a course"
			break;
		}
		case 23:
		{	//Edit grade of a student
			break;
		}
		case 24:
		{	//View scoreboard
			break;
		}
		case 30:
		{
			break;
		}
		case 32:
		{
			checksign = 1;
			break;
		}
		default:
			break;
		}

	}
}
void SignIn_Menu()
{
	int checksign_in = 0;
	while (checksign_in == 0)
	{ 	string username, passw;
		int type;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "**                                   **" << endl;
		cout << "**        MANAGE STUGENT SYSTEM      **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "You are: [1] :staff    [2]: student    [3]: lecturer" << endl;
		cin >> type;
		cout << "userID: ";
		cin >> username;
		cout << "passwd: ";
		char s[100] = { 0 };
    int i;
    for (i = 0; i < 100;i++) {
        s[i] = _getch();
        if (s[i] == 13) {
            break;
        }
        else {
            _putch('*');
        }
    };
	getchar();	
	for(int i = 0; s[i] != '\0'; i++){
		passw = passw+s[i];
	}
	if (checkUser(username, passw, type))
	{
		checksign_in = 1;
		home_cli(type);
	}
	else
		cout << "your user not valid!" << endl;
	}

	
}

bool checkUser(string username, string pass, int type){
	ifstream fin;/*
	if(type == 1){
		fin.open("staff.txt");
		while (!fin.eof())
		{
			//Read data
		}
	}
	else if (type == 2)
	{
		fin.open("lecturer.txt");
		while (!fin.eof())
		{
			//Read data
		}
	}
	else if (type == 3)
	{
		fin.open("student.txt");
		while (!fin.eof())
		{
			//Read data
		}
	}
	else
	{
		cout << "user not valid!!" << endl;
	}*/
	return true;
}