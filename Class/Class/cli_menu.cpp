#include "define_cli_menu.h"
#include "class.h"
#include "header.h"

void staff_cli()
{
	cout << "[1]: Import student from csv file" << endl;
	cout << "[2]: Manually add new student to class" << endl;
	cout << "[3]: Edit an existing student" << endl;
	cout << "[4]: Remove a student" << endl;
	cout << "[5]: Change student to other class" << endl;
	cout << "[6]: View list of classes" << endl;
	cout << "[7]: View list of students in a class" << endl;
	cout << "[8]: Academic year" << endl;
	cout << "[9]: Import course from csv file" << endl;
	cout << "[10]: Manually add new course" << endl;
	cout << "[11]: Edit an existing course" << endl;
	cout << "[12]: Remove a course" << endl;
	cout << "[13]: Remove student in course" << endl;
	cout << "[14]: Add student to course" << endl;
	cout << "[15]: View list course in the current semester" << endl;
	cout << "[16]: View list of student of a course" << endl;
	cout << "[17]: View attendace list of a course" << endl;
	cout << "[18]: Lecturers" << endl;
	cout << "[19]: Search and view the scoreboard of a course" << endl;
	cout << "[20]: Export a scoreboard to a csv file" << endl;
	cout << "[21]: Search and view attendance list of a course" << endl;
	cout << "[22]: Export a attendance list to a csv file" << endl;
}

void student_cli()
{
	cout << "[23]: Check-in" << endl;
	cout << "[24]: View check-in result" << endl;
	cout << "[25]: View schedules" << endl;
	cout << "[26]: View scores of a course" << endl;
}

void lecturer_cli()
{
	cout << "[27]: View list course in current semester" << endl;
	cout << "[28]: View list of students of a course" << endl;
	cout << "[29]: View attendance list of a course" << endl;
	cout << "[30]: Edit an attendance" << endl;
	cout << "[31]: Import scoreboard of a course from csv file" << endl;
	cout << "[32]: Edit grade of a student" << endl;
	cout << "[33]: View scoreboard" << endl;
}

void Print_home_page(int &i, int type)
{
	cout << "This is Home page of Program" << endl;
	cout << "what do you want ??" << endl;
	cout << "[0]: View your account" << endl;
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
	cout << "[40]: Change Password" << endl;
	cout << "[41]: Exit program" << endl;
	cin >> i;
}

void home_cli(string username, string pass, int type)
{
	pass.erase(pass.end() - 1, pass.end());
	int checksign = 0;
	while (checksign == 0)
	{
		int i = 0;
		system("CLS");
		Print_home_page(i, type);
		switch (i)
		{
		case 0:{
			
			
			int check_view = 1;
			while(check_view != 0)
			{
			system("CLS");
			//checkUser_to_print_inf(username,pass,type);
					cout << "[0] back to main" << endl;
					cin >> check_view;
				}
			break;
		}
		case 1:
		{
			if (type == 1)
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
			}
			break;
		}
		case 2:
		{
			//add new student to class
			if (type == 1)
			{
				system("CLS");
				cout << ">>>>>>>>>> <<<<<<<<<<" << endl;
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
			}
			break;
		}
		case 3:
		{
			if (type == 1)
			{
				//Edit an existing student
				//--------choose class to edit student-----
				system("CLS");
				cout << ">>>>>>>>>> <<<<<<<<<<" << endl;
				string class_file;
				system("type data\\Class.txt");
				cout << "choose class to edit student: ";
				cin >> class_file;
				//--------------------Choose student from file class ----------
				ifstream student_fin;
				view_list_students(student_fin, class_file);
				string studentId;
				cout << endl;
				cout << "choose student to edit(input student ID):";
				cin >> studentId;
				//--------------Call Function-----------------
				int check_edit = 0;
				ifstream fin;
				ofstream fout;
				while (check_edit == 0)
				{
					edit_student(fin, fout, class_file, studentId, check_edit);
				}
			}
			break;
		}
		case 4:
		{
			if (type == 1)
			{
				//
				//Remove a student;
				//
				//--------Get class to remove student-----
				system("CLS");
				cout << ">>>>>>>>>> <<<<<<<<<<" << endl;
				string class_file;
				system("type data\\Class.txt");
				cout << "choose class to remove student: ";
				cin >> class_file;
				//--------------Choose student from file class---------
				ifstream student_fin;
				view_list_students(student_fin, class_file);
				string studentId;
				cout << endl;
				cout << "choose student to remove(Pls, input student ID):";
				cin >> studentId;
				//----------------Call Function-----------
				ifstream fin;
				ofstream fout;
				if (remove_student(fin, fout, class_file, studentId) == "Null")
					Sleep(3000);
			}
			break;
		}
		case 5:
		{
			if (type == 1)
			{
				// Change student to other class;
				//-----------------Choose class A and class B-------------------
				system("CLS");
				cout << ">>>>>>>>>> <<<<<<<<<<" << endl;
				string class_a;
				string class_b;
				system("type data\\Class.txt");
				cout << "Which class get student (Class A):";
				cin >> class_a;
				cout << "Choose class remove to (class B):";
				cin >> class_b;
				//---------- Get Student To Moving in Class A ------------
				ifstream student_fin;
				view_list_students(student_fin, class_a);

				string studentId;
				cout << endl;
				cout << "Choose student to Move (Input student ID):";
				cin >> studentId;
				//--------Call Function----------------
				ifstream fin;
				ofstream fout;
				int check_change = 0;
				while (check_change == 0)
				{
					change_students(fin, fout, class_a, class_b, studentId, check_change);
				}
			}
			break;
		}
		case 6:
		{ //View list of classes
			if (type == 1)
			{
				system("CLS");
				cout << ">>>>>>>>>> <<<<<<<<<<" << endl;
				cout << "There are class in course" << endl;
				ifstream fin;
				view_list_classes(fin);
			}
			break;
		}
		case 7:
		{ // View list of students in a class
			if (type == 1){
				system("CLS");
			cout << ">>>>>>>>>> <<<<<<<<<<" << endl;
			ifstream class_file;
			class_file.open("data/Class.txt");
			if (!class_file.is_open())
			{
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
			}
			break;
		}
		case 8:
		{ //Academic yead
			if (type == 1)
			{
				CRUD_years_semesters();
			}
			break;
		}
		case 9:
		{ // import course from csv file
			if (type == 1)
			{
				importCourses();
			}
			break;
		}
		case 10:
		{ //Manually add new course
			if (type == 1)
			{
				addCourseManually();
			}
			break;
		}
		case 11:
		{
			// Edit an existing course
			if (type == 1)
			{
				editExistingCourse();
			}
			break;
		}
		case 12:
		{ // Remove a course
			if (type == 1)
			{
				removeCourse();
			}
			break;
		}
		case 13:
		{ //Remove student in course
			if (type == 1)
			{
				removeStudentFromScore();
			}
			break;
		}
		case 14:
		{ //Add student in course
			if (type == 1)
			{
				addStudentToScore();
			}
			break;
		}
		case 15:
		{
			//View course in semester
			if (type == 1)
			{
				viewCourseInSemester();
			}
			break;
		}
		case 16:
		{
			// view student of course
			if (type == 1)
			{
				viewStudentsInCourse();
			}
			break;
		}
		case 17:
		{
			// view attendace list
			if (type == 1)
			{
				viewAttendanceList();
			}
			break;
		}
		case 18:
		{ //Lecturers
			if (type == 1)
			{
				CRUD_Lecturer();
			}
			break;
		}
		case 19:
		{
			//Search and view the scoreboard of a course
			if (type == 1)
			{
				searchViewScore();
			}
			break;
		}
		case 20:
		{
			// Export a scoreboard to a csv file
			if (type == 1)
			{
				exportScore();
			}
			break;
		}
		case 21:
		{
			// Search and view attendance of a course
			if (type == 1)
			{
				searchViewAttendance();
			}
			break;
		}
		case 22:
		{
			// Export a attendance to a csv file
			if (type == 1)
			{
				exportAttendances();
			}
			break;
		}
		case 23:
		{
			// Check-in
			if (type == 3)
			{
				stringstream getID(username);
				int ID = 0;
				getID >> ID;
				searchCheckIn(ID);
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 24:
		{
			//View check-in result
			if (type == 3)
			{
				stringstream getID(username);
				int ID = 0;
				getID >> ID;
				searchViewCheckIn(ID);
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 25:
		{ // View schedules
			if (type == 3)
			{
				stringstream getID(username);
				int ID = 0;
				getID >> ID;
				searchViewSchedule(ID);
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 26:
		{
			//View scores of a course
			if (type == 3)
			{
				stringstream getID(username);
				int ID = 0;
				getID >> ID;
				searchViewScore_student(ID);
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 27:
		{ //View list course in current semester
			if (type == 2)
			{
				viewCourseInSemester();
			}
			break;
		}
		case 28:
		{ // View list of students of a course
			if (type == 2)
			{
				viewStudentsInCourse();
			}
			break;
		}
		case 29:
		{ // View attendance list of a course
			if (type == 2)
			{
				searchViewAttendance();
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 30:
		{
			//Edit an attendance
			if (type == 2)
			{
				editAttendance();
			}
			break;
		}
		case 31:
		{
			// Import scoreboard of a course"
			if (type == 2)
			{
				importScore();
			}
			break;
		}
		case 32:
		{ //Edit grade of a student
			if (type == 2)
			{
				searchEditGrade();
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 33:
		{
			//View scoreboard
			if (type == 2)
			{
				searchViewScore();
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			}
			break;
		}
		case 40:
		{
			// Change password
			changePassword(username, pass, type);
			cout << "pass" << pass << endl;
				int check_view = 1;
				while (check_view != 0)
				{
					cout << "Type [0] to back to main:";
					cin >> check_view;
				}
			break;
		}
		case 41:
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
	{
		string username, passw;
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
		char s[100] = {0};
		int i;
		for (i = 0; i < 100; i++)
		{
			s[i] = _getch();
			if (s[i] == 13)
			{
				break;
			}
			else
			{
				_putch('*');
			}
		};
		getchar();
		for (int i = 0; s[i] != '\0'; i++)
		{
			passw = passw + s[i];
		}
		if (checkUser(username, passw, type))
		{

			home_cli(username, passw, type);
			checksign_in = 1;
		}
		else

			system("CLS");
		cout << "User not valid !!" << endl;
		cout << "May username or password were uncorrect !!" << endl;
	}
}

void RemoveList(readStudent *&head)
{
	readStudent *tmp = head;
	while (head != nullptr)
	{
		head = head->pNext_student;
		delete tmp;
		tmp = head;
	}
}

bool checkUser(string username, string pass, int type)
{
	ifstream fin;
	pass.erase(pass.end() - 1, pass.end());
	if (type == 1)
	{
		fin.open("data/Staff.txt");
		if (fin.is_open())
		{
			Staff *staff;
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
			for (int i = 0; i < amount_staff; ++i)
			{
				fin >> staff[i].user.username;
				fin >> staff[i].user.password;
				fin.ignore(100, '\n');
				getline(fin, staff[i].Fullname);
				fin >> staff[i].gender;
				if (username.compare(staff[i].user.username) == 0 && pass.compare(staff[i].user.password) == 0)
				{
					return true;
				}
			}
			delete[] staff;
			return false;
		}
		else
			cout << "Cannot open file !!" << endl;
		fin.close();
	}
	else if (type == 2)
	{
		
			Lecturer *Hlecturer = new Lecturer;
			Lecturer* plec = Hlecturer;
			int size = 0;
			getLecrurer_file(plec, size);
			plec = Hlecturer;
			while (plec->lec_pNext)
			{
				if (username.compare(plec->lec_username) == 0 && pass.compare(plec->lec_password) == 0)
				{
					return true;
				}
				else
					plec = plec->lec_pNext;
			}
			deleteAllNode(Hlecturer);
			return false;
		
	}
	else if (type == 3)
	{
		readStudent *student = nullptr;
		readStudent *tmp = student;
		tmp = new readStudent;
		fin.open("data/Student.txt");
		if (fin.is_open())
		{
			for (int i = 0; !fin.eof(); i++)
			{
				fin >> tmp->userID;
				fin >> tmp->password;
				fin.ignore(100, '\n');
				getline(fin, tmp->FullName);
				getline(fin, tmp->DoB);
				fin >> tmp->class_name;
				fin >> tmp->gender;
				if (username.compare(tmp->userID) == 0 && pass.compare(tmp->password) == 0)
				{
					RemoveList(student);
					return true;
				}
				else
				{
					tmp->pNext_student = new readStudent;
					tmp = tmp->pNext_student;
				}
			}
			tmp = nullptr;
			RemoveList(student);
			return false;
		}
		else
			cout << "Cannot open file !!" << endl;
		fin.close();
	}
	else
	{
		cout << "\n Pls, input user from 1-3" << endl;
		Sleep(3000);
		return false;
	}
	//	return true;
}

void changePassword(string username, string &pass, int type)
{
	// -------------- CONFIRM ----------------------
	string oldpass = "oldpass";
	string newPass = "newpass";
	string confirm_newPass = "confirm";
	while (newPass.compare(confirm_newPass)!=0 && pass.compare(oldpass) != 0)
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
		Staff *staff = nullptr;
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
		if (fout.is_open())
		{
			fout << amount_staff << endl;
			for (int i = 0; i < amount_staff; ++i)
			{
				fout << staff[i].user.username << endl;
				fout << staff[i].user.password << endl;
				fout << staff[i].Fullname << endl;
				fout << staff[i].gender << endl;
			}
		}
		fout.close();
		delete[] staff;
		return;
	}
	else if (type == 2)
	{
		Lecturer *Hlecturer = new Lecturer;
		int size = 0;
		Lecturer * plec = Hlecturer;
		getLecrurer_file(plec, size);
		plec = Hlecturer;
		while (plec)
		{		
			if(username.compare(plec->lec_username)==0){
				plec->lec_password = newPass;
				pass = newPass;
				plec = plec->lec_pNext;
			}else	plec = plec->lec_pNext;
		}
		plec = Hlecturer;
		ofstream fout;
		fout.open("data/Lecturer.txt");
   		if (!fout.is_open()) cout << "Error !!!" << endl;
    	else {
        	fout << size << endl;
        	for (; plec->lec_pNext!= nullptr; ) {
            	fout << plec->lec_username << endl;
            	fout << plec->lec_password << endl;
            	fout << plec->lec_Fullname << endl;
            	fout << plec->lec_degree << endl;
            	fout << plec->gender << endl;
            	plec = plec->lec_pNext;
        	}
   		}
    	fout.close();
		deleteAllNode(Hlecturer);
			
		
	}
	else if (type == 3)
	{
		readStudent *student = new readStudent;
		readStudent *tmp = student;
		fin.open("data/Student.txt");
		if (fin.is_open())
		{
			
			for (int i = 0; !fin.eof(); i++)
			{
				fin >> tmp->userID;
				fin >> tmp->password;
				fin.ignore(100, '\n');
				getline(fin, tmp->FullName);
				getline(fin, tmp->DoB);
				fin >> tmp->class_name;
				fin >> tmp->gender;
				
				tmp->pNext_student = new readStudent;
				tmp = tmp->pNext_student;
				
			}
			tmp = nullptr;
			tmp = student;
		}
		else
			cout << "Cannot open file !!" << endl;
		fin.close();
		
		while(tmp->pNext_student != nullptr){
	
			if(username.compare(tmp->userID)==0){
				
				tmp->password = newPass;
				pass = newPass;
			
				tmp = tmp->pNext_student;
			}else tmp = tmp->pNext_student;
		}
		
		ofstream fout;
		fout.open("data/Student.txt");
		if(!fout.is_open()){
			cout << "Error !!" << endl;
		}
		else{
			while(student->pNext_student->pNext_student){
				fout << student->userID << endl;
				fout << student->password << endl;
				fout << student->FullName << endl;
				fout << student->DoB << endl;
				fout << student->class_name << endl;
				fout << student->gender << endl;
				student = student->pNext_student;
			}
		}
		fout.close();
		RemoveList(student);
	}
}



/*
void checkUser_to_print_inf(string username, string pass, int type)
{
	cout << ">>>>> VIEW ACCOUNT <<<<<" << endl;
	ifstream fin;
	pass.erase(pass.end() - 1, pass.end());
	if (type == 1)
	{
		fin.open("data/Staff.txt");
		if (fin.is_open())
		{
			Staff *staff;
			int amount_staff;
			
			amount of staff
			username
			password
			Full name 	
			Gender
			
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
					
					cout << username << endl;
					cout << staff[i].Fullname << endl;
					if(staff[i].gender==0) cout << "Female" << endl;
					else cout << "Male" << endl;
					return;
				}
			}
			delete[] staff;

		}
		else
			cout << "Cannot open file !!" << endl;
		fin.close();
	}
	else if (type == 2)
	{
		
			Lecturer *Hlecturer = new Lecturer;
			Lecturer* plec = Hlecturer;
			int size = 0;
			getLecrurer_file(plec, size);
			plec = Hlecturer;
			while (plec->lec_pNext)
			{
				if (username.compare(plec->lec_username) == 0 && pass.compare(plec->lec_password) == 0)
				{
					cout << plec->lec_username << endl;
					cout << plec->lec_Fullname << endl;
					cout << plec->lec_degree << endl;
					if(plec->gender==0) cout << "Male" << endl;
					else cout << "Female" << endl;
					return;
				}
				else
					plec = plec->lec_pNext;
			}
			deleteAllNode(Hlecturer);

		
	}
	else if (type == 3)
	{
		readStudent *student = nullptr;
		readStudent *tmp = student;
		tmp = new readStudent;
		fin.open("data/Student.txt");
		if (fin.is_open())
		{
			for (int i = 0; !fin.eof(); i++)
			{
				fin >> tmp->userID;
				fin >> tmp->password;
				fin.ignore(100, '\n');
				getline(fin, tmp->FullName);
				getline(fin, tmp->DoB);
				fin >> tmp->class_name;
				fin >> tmp->gender;
				if (username.compare(tmp->userID) == 0 && pass.compare(tmp->password) == 0)
				{
					cout << tmp->userID << endl;
					cout << tmp->FullName << endl;
					cout << tmp->DoB << endl;
					cout << tmp->class_name << endl;
					if(tmp->gender==0) cout << "Female" << endl;
					else cout << "Male" << endl;
					RemoveList(student);
					return;
				}
				else
				{
					tmp->pNext_student = new readStudent;
					tmp = tmp->pNext_student;
				}
			}
			tmp = nullptr;
			RemoveList(student);

		}
		else
			cout << "Cannot open file !!" << endl;
		fin.close();
	}
	else
	{
		cout << "\n Pls, input user from 1-3" << endl;
		Sleep(3000);
	}
	//	return true;
}
*/