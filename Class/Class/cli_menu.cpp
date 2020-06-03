#include "define_cli_menu.h"
#include "class.h"
//#include "header.h"

void staff_cli(){
	cout << "[1]: Import student as csv file" << endl;
	cout << "[2]: Add new student to class" << endl;
	cout << "[3]: Edit an existing student" << endl;
	cout << "[4]: Remove a student" << endl;
	cout << "[5]: Change student to other class" << endl;
	cout << "[6]: View list of classes" << endl;
	cout << "[7]: View list of students in a class" << endl;
	cout << "[8]: Academic year" << endl;
	cout << "[9]: Import course" << endl;
	cout << "[10]: Manually add new course" << endl;
	cout << "[11]: Remove a course" << endl;
	cout << "[12]: Remove student in course" << endl;
	cout << "[13]: Add student in course" << endl;
	cout << "[14]: View list course" << endl;
	cout << "[15]: Lecturers" << endl;
}

void student_cli(){
	cout << "[16]: Check-in" << endl;
	cout << "[17]: View check-in result" << endl;
	cout << "[18]: View schedules" << endl;
	cout << "[19]: View scores of a course" << endl;

}

void lecturer_cli(){
	cout << "[20]: View list course in current semester" << endl;
	cout << "[21]: View list of students of a course" << endl;
	cout << "[22]: View attendance list of a course" << endl;
	cout << "[23]: Edit an attendance" << endl;
	cout << "[24]: Import scoreboard of a course" << endl;
	cout << "[25]: Edit grade of a student" << endl;
	cout << "[26]: View scoreboard" << endl;

}

void Print_home_page(int& i, int type){
	cout << "This is Home page of Program" << endl;
	cout << "what do you want ??" << endl; 

	switch (type)
		{
		case 1:
			staff_cli();
			break;
		case 2:
			lecturer_cli();
			break;	
		case 3:
			student_cli();
			break;
		default:
			cout << "---" << endl;
			break;
		}
	cout << "[30]: Change Password" << endl;
	cout << "[32]: Exit program" << endl;
	cin >> i;
}

void home_cli(string username, string pass, int type){
	pass.erase(pass.end()-1,pass.end());	
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
			
			system("dir data\\*.csv");
			string file_csv;
			while (check_import == 0)
			{
				cout << "choose file import (ex: 19APCS1): ";
				cin >> file_csv;
				cin.ignore(100, '\n');
				//-----------------Call function ----------
				ifstream fin;
				ofstream fout;
				import_students_csv(fin, fout, file_csv, check_import);
			}
			break;
		}
		case 2:
		{
			//add new student to class
			int check_add = 0;
		
			ifstream class_file;
			class_file.open("data/Class.txt");
			if (!class_file.is_open())
			{
				cout << "Empty class" << endl;
			}
			else
			{
				class_file.close();
				system("type data\\Class.txt");
				string file_class;
				while (check_add == 0)
				{
					cout << "choose class (ex: 19apcs): ";
					cin >> file_class;
					cin.ignore(100, '\n');
					//--------------Call function -------
					ifstream fin;
					ofstream fout;
					add_new_student(fin, fout, file_class, check_add);
				}
			}
			break;
		}
		case 3:
		{
			//Edit an existing student
				//--------choose class to edit student-----
			string class_file;
			system("type data\\Class.txt");
			cout << "choose class to edit student: ";
			cin >> class_file;
			//--------------------Choose student from file class ----------
			ifstream student_fin;
			view_list_students(student_fin,class_file);
			string studentId;
			cout << endl;
			cout << "choose student to edit(input student ID):";
			cin >> studentId;
			//--------------Call Function-----------------
			int check_edit = 0;
			ifstream fin;
			ofstream fout;
			while(check_edit == 0){
				edit_student(fin,fout,class_file,studentId,check_edit);
			}
			break;
		}
		case 4:{
			////////////////////
			//Remove a student;
			//.........................
			//--------Get class to remove student-----
			string class_file;
			system("type data\\Class.txt");
			cout << "choose class to remove student: ";
			cin >> class_file;
			//--------------Choose student from file class---------
			ifstream student_fin;
			view_list_students(student_fin,class_file);
			string studentId;
			cout << endl;
			cout << "choose student to remove(Pls, input student ID):";
			cin >> studentId;
			//----------------Call Function-----------
			ifstream fin;
			ofstream fout;
			if(remove_student(fin,fout,class_file,studentId)=="Null")
			Sleep(3000);

			break;
		}
		case 5:{
			// Change student to other class;
			//-----------------Choose class A and class B-------------------
			string class_a;
			string class_b;
			system("type data\\Class.txt");
			cout << "Which class get student (Class A):";
			cin >> class_a;
			cout << "Choose class remove to (class B):";
			cin >> class_b;
			//---------- Get Student To Moving in Class A ------------
			ifstream student_fin;
			view_list_students(student_fin,class_a);

			string studentId;
			cout << endl;
			cout << "Choose student to Move (Input student ID):";
			cin >> studentId;
			//--------Call Function----------------
			ifstream fin;
			ofstream fout;
			int check_change = 0;
			while(check_change ==0){
				change_students(fin,fout,class_a,class_b,studentId,check_change);
			}
			break;
		}
		case 6:
		{	//View list of classes
			cout << "There are class in course" << endl;
			ifstream fin;
			view_list_classes(fin);
			break;
		}
		case 7:
		{	// View list of students in a class

			ifstream class_file;
			class_file.open("data/Class.txt");
			if(!class_file.is_open()){
				cout << "Empty class" << endl;
			}
			else
			{
				//----- Show list class --------
				class_file.close();
				cout << "List of classes:" << endl;
				system("type data\\Class.txt");
				string file_class;
				cout << endl;
				cout << "choose class to view student: ";
				cin >> file_class;
				//-------------Call Function --------------
				ifstream fin; // argument
				view_list_students(fin, file_class);
			}
			break;
		}
		case 8:
		{	//Academic yead
			break;
		}
		case 9:
		{	// import course
		//	importCourses();
			break;
		}
		case 10:
		{	//Manually add new course			
			//addCourseManually();
			break;
		}
		case 11:
		{	// Remove a course
			break;
		}
		case 12:
		{	//Remove student in course
			break;
		}
		case 13:
		{	//Add student in course
			break;
		}
		case 14:
		{
			//View list course
			break;
		}
		case 15:
		{	//Lecturers
			break;
		}
		case 16:
		{	// Check-in
			break;
		}
		case 17:
		{	//View check-in result
			break;
		}
		case 18:
		{	// View schedules
			break;
		}
		case 19:
		{	//View scores of a course
			break;
		}
		case 20:
		{	//View list course in current semester
			break;
		}
		case 21:
		{	// View list of students of a course
			break;
		}
		case 22:
		{	// View attendance list of a course
			break;
		}
		case 23:
		{	//Edit an attendance
			break;
		}
		case 24:
		{
			// Import scoreboard of a course"
			break;
		}
		case 25:
		{	//Edit grade of a student
			break;
		}
		case 26:
		{	//View scoreboard
			break;
		}
		case 30:
		{	
			// Change password
			changePassword(username,pass,type);
			Sleep(5000);
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
		cout << "**        MANAGE STUDENT SYSTEM      **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "You are: [1] :staff    [2]: lecturer    [3]: student" << endl;
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
		home_cli(username,passw,type);
	}
	else
		
		system("CLS");
		cout << "User not valid !!" << endl;
		cout << "May username or password were uncorrect !!" << endl;
	}
}

void show_student_in_file_class(string file_class){
	ifstream fin;
	fin.open(file_class.c_str());
	if(!fin.is_open()){
		cout << "Vo hoc" << endl;
	}
	else {
		for(int i = 0 ; !fin.eof(); i++){

		}
	}
}
void RemoveList(readStudent*& head){
	readStudent* tmp = head;
	while(head!=nullptr){
		head=head->pNext_student;
		delete tmp;
		tmp = head;
	}
}
bool checkUser(string username, string pass, int type){
	ifstream fin;
	pass.erase(pass.end()-1,pass.end());	
	if (type == 1)
	{
		fin.open("data/Staff.txt");
		if (fin.is_open())
		{
			Staff* staff;
			int amount_staff;
			/*
			amount of staff
			username
			password
			Full name
			Gender
			*/
			fin >> amount_staff;
			staff = new Staff[amount_staff];
			for(int i = 0; i < amount_staff; ++i){
				fin >> staff[i].user.username;
				fin >> staff[i].user.password;
				fin.ignore(100, '\n');
				getline(fin,staff[i].Fullname);
				fin >> staff[i].gender;
				if(username.compare(staff[i].user.username) == 0 && pass.compare(staff[i].user.password) == 0) {
					return true;
				}
			}
			delete [] staff;
			return false;
		} else cout << "Cannot open file !!" << endl;
	}
	else if (type == 2)
	{
		fin.open("data/Lecturer.txt");
		if (fin.is_open())
		{
			
		}else cout << "Cannot open file !!" << endl;
	}
	else if (type == 3)
	{	
		string slat_n;
		readStudent* student = nullptr;
		readStudent* tmp = student;
		tmp = new readStudent;
		fin.open("data/Student.txt");
		if (fin.is_open())
		{
			for(int i = 0; !fin.eof(); i++){
				fin >> tmp->userID;
				fin >> tmp->password;
				fin.ignore(100,'\n');
				getline(fin,tmp->FullName);
				getline(fin,tmp->DoB);
				fin >> tmp->class_name;
				fin >> tmp->gender;

				cout << tmp->userID << endl;
				cout << tmp->password << endl;
				cout << tmp->FullName << endl;
				cout << tmp->DoB << endl;
				cout << tmp->class_name << endl;
				cout << tmp->gender << endl;
				//
				if (username.compare(tmp->userID)==0 && pass.compare(tmp->password)==0)
				{
					cout << endl << "--------------" << endl;
					cout << username << "---" << pass << endl;
					cout << "here: " << tmp->userID << endl;
					cout << tmp->password << endl;
					cout << "Here okey" << endl;
					RemoveList(student);
					return true;
				}
				else
				{
					tmp->pNext_student = new readStudent;
					tmp = tmp->pNext_student;
				}

			}
			tmp=nullptr;
			RemoveList(student);
			return false;
		}else cout << "Cannot open file !!" << endl;
	}
	else
	{
		cout << "\n Pls, input user from 1-3" << endl;
		Sleep(3000);
		return false;
	}
//	return true;
}

void changePassword(string username, string& pass, int type)
{	
	// -------------- CONFIRM ----------------------
	string oldpass = "oldpass";
	string newPass = "newpass";
	string confirm_newPass = "confirm";
	while (newPass.compare(confirm_newPass) && pass.compare(oldpass))
	{
		system("CLS");
		cout << "Your userID: " << username << endl;
		cout << "Current Password: ";
		cin.ignore(100, '\n');
		getline(cin, oldpass);
		cout << "New passord: ";
		getline(cin, newPass);
		cout << "Confirm password:";
		getline(cin, confirm_newPass);
	}
	//----------------CHANGE PASSWORD------------
	ifstream fin;
	if (type == 1)
	{
		Staff* staff = nullptr;
		int amount_staff;
		fin.open("data/Staff.txt");
		if (fin.is_open())
		{
			fin >> amount_staff;
			staff = new Staff[amount_staff];
			for (int i = 0; i < amount_staff; ++i)
			{
				fin >> staff[i].user.username;
				fin >> staff[i].user.password;
				fin.ignore(100, '\n');
				getline(fin, staff[i].Fullname);
				fin >> staff[i].gender;
				if (username.compare(staff[i].user.username) == 0 && pass.compare(staff[i].user.password) == 0)
				{
					staff[i].user.password = newPass;
					pass = newPass;
					cout << "Success changing password" << endl;
				}
			}
		}
		else
		{
			cout << "Cannot open file !!" << endl;
		}
		fin.close();
		ofstream fout;
		fout.open("data/Staff.txt");
		if(fout.is_open()){
			fout << amount_staff << endl;
			for(int i = 0 ; i < amount_staff; ++i){
				fout << staff[i].user.username << endl;
				fout << staff[i].user.password << endl;
				fout << staff[i].Fullname<< endl;
				fout << staff[i].gender << endl;
			}
			
		}
		delete [] staff;
		return;
	}
	else if (type == 2)
	{
		fin.open("data/lecturer.txt");
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				//Read data
			}
		}else cout << "Cannot open file !!" << endl;
	}
	else if (type == 3)
	{	
		int size=0;
		User user[300];
		fin.open("data/students.txt");
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				fin >> user[size].username;
				fin >> user[size].password;
				if (username.compare(user[size].username) == 0 && pass.compare(user[size].password))
				{
					user[size].password = newPass;
					cout << "success changing password" << endl;
				}
				size++;
			}
		}
		else
			cout << "Cannot open file !!" << endl;
		fin.close();
		ofstream fout;
		fout.open("data/students.txt");
		if(fout.is_open()){
			for(int i = 0 ; i< size; ++i){
				fout << user[i].username << endl;
				fout << user[i].password << endl;
			}
		}
		for(int i = 0; i < size; ++i){
			cout << user[i].username << endl;
			cout << user[i].password << endl;
		}
		return;
	}
}