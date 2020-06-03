#include "function.h"

void menu()
{
	cout << "You are: [1] :staff    [2]: lecturer    [3]: student" << endl;
	int choose, choose2;
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		cout << "This is Home page of Program" << endl;
		cout << "what do you want ? ?" << endl;
		cout << "[1] : import student as csv file" << endl;
		cout << "[2] : add new student to class" << endl;
		cout << "[3] : Edit an existing student" << endl;
		cout << "[4] : Remove a student" << endl;
		cout << "[5] : Change student to other class" << endl;
		cout << "[6] : View list of classes" << endl;
		cout << "[7] : View list of students in a class" << endl;
		cout << "[8] : Academic year" << endl;
		cout << "[9] : import course" << endl;
		cout << "[10] : Manually add new course" << endl;
		cout << "[11] : Remove a course" << endl;
		cout << "[12] : Remove student in course" << endl;
		cout << "[13] : Add student in course" << endl;
		cout << "[14] : View list course" << endl;
		cout << "[15] : Lecturers" << endl;
		cout << "[30] : Change Password" << endl;
		cout << "[32] : Exit program" << endl;

		cin >> choose2;
		switch (choose2)
		{
		default:
		{
			Sleep(1);
			break;
		}
		}
		break;
	}

	case 2:
	{
		cout << "This is Home page of Program" << endl;
		cout << "what do you want ? ?" << endl;
		cout << "[20] : View list course in current semester" << endl;
		cout << "[21] : View list of students of a course" << endl;
		cout << "[22] : View attendance list of a course" << endl;
		cout << "[23] : Edit an attendance" << endl;
		cout << "[24] : Import scoreboard of a course" << endl;
		cout << "[25] : Edit grade of a student" << endl;
		cout << "[26] : View scoreboard" << endl;
		cout << "[30] : Change Password" << endl;
		cout << "[32] : Exit program" << endl;

		cin >> choose2;
		switch (choose2)
		{

		case 20:
		{
			break;
		}

		case 21:
		{
			break;
		}

		case 22:
		{
			break;
		}

		case 24:
		{
			break;
		}

		case 25:
		{
			break;
		}

		case 26:
		{
			break;
		}

		default:
		{
			Sleep(1);
			break;
		}
		}
		break;
	}

	case 3:
	{
		cout << "This is Home page of Program" << endl;
		cout << "what do you want ? ?" << endl;
		cout << "[16] : Check - in" << endl;
		cout << "[17] : View check - in result" << endl;
		cout << "[18] : View schedules" << endl;
		cout << "[19] : View scores of a course" << endl;
		cout << "[30] : Change Password" << endl;
		cout << "[32] : Exit program" << endl;

		cin >> choose2;
		switch (choose2)
		{

		case 16:
		{
			break;
		}

		case 17:
		{
			break;
		}

		case 18:
		{
			break;
		}

		case 19:
		{
			break;
		}

		default:
		{
			Sleep(1);
			break;
		}
		}
		break;
	}

	default:
		break;
	}
}

studentType readStudent_element(ifstream& fin)
{
	studentType student;
	string tmp;
	int n;

	fin >> student.iD;
	fin >> student.password;
	fin.ignore();
	getline(fin, student.fullname, '\n');
	getline(fin, tmp, ' ');
	n = stoi(tmp) - 1900;
	student.dOB.tm_year = n;
	getline(fin, tmp, ' ');
	n = stoi(tmp) - 1;
	student.dOB.tm_mon = n;
	getline(fin, tmp, '\n');
	n = stoi(tmp);
	student.dOB.tm_mday = n;
	student.dOB = { 0, 0, 0, student.dOB.tm_mday, student.dOB.tm_mon, student.dOB.tm_year };
	getline(fin, student.className, '\n');
	fin >> student.attendingStatus;

	student.point = { -1, -1, -1, -1 };
	for (int i = 0; i < 10; ++i)
	{
		student.checkIn[i].time.startTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
		student.checkIn[i].time.endTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
		student.checkIn[i].checkIn = -1;
	}
	student.droppedStatus = -1;

	return student;
}

studentType* readStudent_array(ifstream& fin, int& size)
{
	fin >> size;
	studentType* array;
	array = new studentType[size];

	for (int i = 0; i < size; ++i)
		array[i] = readStudent_element(fin);

	return array;
}

studentType* readStudent(string dir, int& size)
{
	ifstream fin;
	studentType* array = nullptr;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		fin >> size;

		array = new studentType[size];

		for (int i = 0; i < size; ++i)
			array[i] = readStudent_element(fin);

		fin.close();
	}

	return array;
}

void writeStudent(studentType* students, int size, string dir)
{
	ofstream fout;

	fout.open(dir);
	if (!fout.is_open())
		cout << "Cannot write file." << endl;
	else
	{
		fout << size << endl;

		for (int i = 0; i < size; ++i)
		{
			fout << students[i].iD << endl;
			fout << students[i].password << endl;
			fout << students[i].fullname << endl;
			fout << students[i].dOB.tm_year + 1900 << " " << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << " " << setw(2) << setfill('0') << students[i].dOB.tm_mday << endl;
			fout << students[i].className << endl;
			fout << students[i].attendingStatus << endl;
			fout << endl;
		}

		fout.close();
	}
}

durationType readDuration(ifstream& fin)
{
	durationType t;
	string tmp;
	getline(fin, tmp, ' ');
	t.startTime.tm_year = stoi(tmp) - 1900;
	t.endTime.tm_year = t.startTime.tm_year;
	getline(fin, tmp, ' ');
	t.startTime.tm_mon = stoi(tmp) - 1;
	t.endTime.tm_mon = t.startTime.tm_mon;
	getline(fin, tmp, ' ');
	t.startTime.tm_mday = stoi(tmp);
	t.endTime.tm_mday = t.startTime.tm_mday;
	getline(fin, tmp, ' ');
	t.startTime.tm_hour = stoi(tmp);
	getline(fin, tmp, ' ');
	t.startTime.tm_min = stoi(tmp);
	getline(fin, tmp, ' ');
	t.endTime.tm_hour = stoi(tmp);
	getline(fin, tmp, ' ');
	t.endTime.tm_min = stoi(tmp);

	t.startTime = { 0, t.startTime.tm_min, t.startTime.tm_hour, t.startTime.tm_mday, t.startTime.tm_mon, t.startTime.tm_year };
	t.endTime = { 0, t.endTime.tm_min, t.endTime.tm_hour, t.endTime.tm_mday, t.endTime.tm_mon, t.endTime.tm_year };

	return t;
}

studentType readCourse_element(ifstream& fin)
{
	string tmp;
	studentType student;

	fin.ignore();
	fin >> student.iD;
	fin.ignore();
	fin >> student.password;
	fin.ignore();
	getline(fin, student.fullname, '\n');
	getline(fin, tmp, ' ');
	student.dOB.tm_year = stoi(tmp) - 1900;
	getline(fin, tmp, ' ');
	student.dOB.tm_mon = stoi(tmp) - 1;
	getline(fin, tmp, '\n');
	student.dOB.tm_mday = stoi(tmp);
	student.dOB = { 0, 0, 0, student.dOB.tm_mday, student.dOB.tm_mon, student.dOB.tm_year };
	getline(fin, student.className, '\n');
	fin >> student.attendingStatus;
	fin >> student.point.midterm;
	fin >> student.point.final;
	fin >> student.point.bonus;
	fin >> student.point.total;
	fin.ignore();
	for (int i = 0; i < 10; ++i)
	{
		student.checkIn[i].time = readDuration(fin);
		getline(fin, tmp, '\n');
		student.checkIn[i].checkIn = stoi(tmp);
	}
	fin >> student.droppedStatus;
	fin.ignore();

	return student;
}

studentType* readCourse_array(ifstream& fin, int& size)
{
	studentType* students;
	fin >> size;
	students = new studentType[size];

	for (int i = 0; i < size; ++i)
		students[i] = readCourse_element(fin);

	return students;
}

studentType* readCourse(string dir, int& size)
{
	ifstream fin;
	studentType* students = nullptr;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		students = readCourse_array(fin, size);
		fin.close();
	}

	return students;
}

void writeCourse(studentType* students, int size, string dir)
{
	ofstream fout;

	fout.open(dir);
	if (!fout.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		fout << size << endl;
		for (int i = 0; i < size; ++i)
		{
			fout << students[i].iD << endl;
			fout << students[i].password << endl;
			fout << students[i].fullname << endl;
			fout << students[i].dOB.tm_year + 1900 << " " << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << " " << setw(2) << setfill('0') << students[i].dOB.tm_mday << endl;
			fout << students[i].className << endl;
			fout << students[i].attendingStatus << endl;
			fout << students[i].point.midterm << endl;
			fout << students[i].point.final << endl;
			fout << students[i].point.bonus << endl;
			fout << students[i].point.total << endl;
			for (int j = 0; j < 10; ++j)
			{
				fout << students[i].checkIn[j].time.startTime.tm_year + 1900 << " ";
				fout << setw(2) << setfill('0') << students[i].checkIn[j].time.startTime.tm_mon + 1 << " ";
				fout << setw(2) << setfill('0') << students[i].checkIn[j].time.startTime.tm_mday << " ";
				fout << setw(2) << setfill('0') << students[i].checkIn[j].time.startTime.tm_hour << " ";
				fout << setw(2) << setfill('0') << students[i].checkIn[j].time.startTime.tm_min << " ";
				fout << setw(2) << setfill('0') << students[i].checkIn[j].time.endTime.tm_hour << " ";
				fout << setw(2) << setfill('0') << students[i].checkIn[j].time.endTime.tm_min << " ";
				fout << students[i].checkIn[j].checkIn << endl;
			}
			fout << students[i].droppedStatus << endl;
			fout << endl;
		}

		fout.close();
	}
}

int positionOfStudent_array(int& no, studentType* students, int size)
{
	int iD = 0;
	int n = 0;

	if (no < 500)
	{
		n = no - 1;
		iD = students[n].iD;
		no = iD;
		return n;
	}
	else
		iD = no;

	for (int i = 0; i < size; ++i)
		if (students[i].iD == iD)
			return i;

	return -1;
}

studentType* attendanceCourse_array(studentType* students, int size, int& newSize)
{
	studentType* attendance;
	newSize = 0;

	for (int i = 0; i < size; ++i)
		if (students[i].attendingStatus == 1)
			++newSize;

	attendance = new studentType[newSize];
	int j = 0;

	for (int i = 0; i < size; ++i)
		if (students[i].attendingStatus == 1)
		{
			attendance[j] = students[i];
			++j;
		}

	return attendance;
}

void viewCourse(string dir)
{
	studentType* students;
	int size;
	students = readCourse(dir, size);

	string space = "                         ";

	space = space.replace(0, 8, "Fullname");
	cout << "No ID        " << space << "DOB       " << "  Class" << endl;

	space = "                         ";
	for (int i = 0; i < size; ++i)
	{
		space = space.replace(0, students[i].fullname.length(), students[i].fullname);
		cout << i + 1 << ". " << students[i].iD << "  " << space;
		cout << setw(2) << setfill('0') << students[i].dOB.tm_mday << "/" << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << "/" << students[i].dOB.tm_year + 1900;
		cout << "  " << students[i].className << endl;
		space = "                         ";
	}
}

void viewCourse_attendance(string dir)
{
	studentType* students;
	int size;
	students = readCourse(dir, size);
	students = attendanceCourse_array(students, size, size);

	string space = "                         ";

	space = space.replace(0, 8, "Fullname");
	cout << "No ID        " << space << "DOB       " << "  Class" << endl;

	space = "                         ";
	for (int i = 0; i < size; ++i)
	{
		space = space.replace(0, students[i].fullname.length(), students[i].fullname);
		cout << i + 1 << ". " << students[i].iD << "  " << space;
		cout << setw(2) << setfill('0') << students[i].dOB.tm_mday << "/" << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << "/" << students[i].dOB.tm_year + 1900;
		cout << "  " << students[i].className << endl;
		space = "                         ";
	}
}

string getDir(string folder, string file)
{
	string dir = folder + "/" + file;
	return dir;
}

string getDir_course(string folder, string academicYear, string semester, string className, string courseName)
{
	string dir = folder + "/" + academicYear + "-" + semester + "-" + className + "-" + courseName + "-Student.txt";
	return dir;
}

string getDir_schedule(string folder, string academicYear, string semester, string className)
{
	string dir = folder + "/" + academicYear + "-" + semester + "-Schedule-" + className + ".txt";
	return dir;
}

string getDir_class(string folder, string className)
{
	string dir = folder + "/Student-" + className + ".txt";
	return dir;
}

string getDir_score(string folder, string className, string courseName)
{
	string dir = folder + "/" + className + "-" + courseName + "-Scoreboard.csv";
	return dir;
}

class_courseType* readClass(string dir, int& size)
{
	class_courseType* classes = nullptr;
	ifstream fin;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		fin >> size;
		fin.ignore();
		classes = new class_courseType[size];
		for (int i = 0; i < size; ++i)
			getline(fin, classes[i].className, '\n');
		fin.close();
	}

	return classes;
}

void writeCourse_csv(studentType* students, int size, string dir)
{
	ofstream fout;
	fout.open(dir);
	if (!fout.is_open())
		cout << "Cannot write file." << endl;
	else
	{
		fout << "No,Student ID,fullname,DOB,Class" << endl;
		for (int i = 0; i < size; ++i)
		{
			fout << i + 1 << "," << students[i].iD << "," << students[i].fullname << ",";
			fout << setw(2) << setfill('0') << students[i].dOB.tm_mday << "/" << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << "/" << students[i].dOB.tm_year + 1900 << ",";
			fout << students[i].className << endl;
		}
		fout.close();
	}
}

void viewScore(string dir)
{
	studentType* students;
	int size;
	students = readCourse(dir, size);

	string space = "                         ";

	space = space.replace(0, 8, "Fullname");
	cout << "No ID        " << space << "DOB       " << "  Midterm Final   Bonus   Total   " << "Class" << endl;

	space = "                         ";
	for (int i = 0; i < size; ++i)
	{
		space = space.replace(0, students[i].fullname.length(), students[i].fullname);
		cout << i + 1 << ". " << students[i].iD << "  " << space;
		space = "                         ";
		cout << setw(2) << setfill('0') << students[i].dOB.tm_mday << "/" << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << "/" << students[i].dOB.tm_year + 1900;
		cout << "  ";
		cout << setw(8) << setfill(' ');
		cout.setf(ios::adjustfield, ios::left);
		cout << setw(8) << students[i].point.midterm;
		cout << setw(8) << students[i].point.final;
		cout << setw(8) << students[i].point.bonus;
		cout << setw(8) << students[i].point.total;
		cout.unsetf(ios::adjustfield);
		cout << students[i].className << endl;
	}
}

void writeScore(studentType* students, int size, string dir)
{
	ofstream fout;
	fout.open(dir);
	if (!fout.is_open())
		cout << "Cannot write file." << endl;
	else
	{
		fout << "No,Student ID,Fullname,Midterm,Final,Bonus,Total" << endl;
		for (int i = 0; i < size; ++i)
		{
			fout << i + 1 << "," << students[i].iD << "," << students[i].fullname << ",";
			fout << students[i].point.midterm << "," << students[i].point.final << ",";
			fout << students[i].point.bonus << "," << students[i].point.total << endl;
		}
		fout.close();
	}
}

studentType* readScore(string dir, int& size)
{
	ifstream fin;
	studentType* students = nullptr;
	size = 0;
	string tmp;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		getline(fin, tmp, '\n');
		while (getline(fin, tmp, '\n'))
			++size;

		students = new studentType[size];
		
		// Return to the beginning position
		fin.clear();
		fin.seekg(0, fin.beg);

		getline(fin, tmp, '\n');

		for (int i = 0; i < size; ++i)
		{
			getline(fin, tmp, ',');
			getline(fin, tmp, ',');
			students[i].iD = stoi(tmp);
			getline(fin, students[i].fullname, ',');
			getline(fin, tmp, ',');
			students[i].point.midterm = stof(tmp);
			getline(fin, tmp, ',');
			students[i].point.final = stof(tmp);
			getline(fin, tmp, ',');
			students[i].point.bonus = stof(tmp);
			getline(fin, tmp, '\n');
			students[i].point.total = stof(tmp);

			students[i].password = -1;
			students[i].dOB.tm_year = -1 - 1900;
			students[i].dOB.tm_mon = -1 - 1;
			students[i].dOB.tm_mday = -1;
			students[i].attendingStatus = -1;
			for (int j = 0; j < 10; ++j)
			{
				students[i].checkIn[j].time.startTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
				students[i].checkIn[j].time.endTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
				students[i].checkIn[j].checkIn = -1;
			}
			students[i].droppedStatus = -1;
		}

		fin.close();
	}

	return students;
}

bool checkFile(string dir)
{
	ifstream fin(dir);
	return fin.good();
}

bool checkUpdate_string(string oldOne, string newOne)
{
	if (newOne == "")
		return false;
	else if (newOne != oldOne)
		return true;
	else
		return false;
}

bool checkUpdate_int(int oldOne, int newOne)
{
	if (newOne == -1)
		return false;
	else if (newOne != oldOne)
		return true;
	else
		return false;
}

bool checkUpdate_float(float oldOne, float newOne)
{
	if (newOne == -1)
		return false;
	else if (newOne != oldOne)
		return true;
	else
		return false;
}

bool checkUpdate_tm(tm oldOne, tm newOne)
{
	if (newOne.tm_mday == -1)
		return false;
	else if (newOne.tm_min != oldOne.tm_min || newOne.tm_hour != oldOne.tm_hour || newOne.tm_mday != oldOne.tm_mday || newOne.tm_mon != oldOne.tm_mon || newOne.tm_year != oldOne.tm_year)
		return true;
	else
		return false;
}

bool checkUpdate_checkin(checkInType oldOne, checkInType newOne)
{
	if (newOne.checkIn == -1)
		return false;
	else if (newOne.checkIn != oldOne.checkIn)
		return true;
	else
		return false;
}

scheduleType readSchedule_element(ifstream& fin)
{
	scheduleType schedule;
	string tmp;
	int n;

	fin.ignore();
	getline(fin, schedule.courseName, '\n');
	getline(fin, schedule.courseNameFull, '\n');
	getline(fin, schedule.className, '\n');
	getline(fin, schedule.lecturer, '\n');
	getline(fin, schedule.lecturerFull, '\n');
	getline(fin, schedule.lecturerDegree, '\n');
	fin >> schedule.status;
	fin.ignore();
	getline(fin, tmp, ' ');
	schedule.startTime.tm_year = stoi(tmp) - 1900;
	getline(fin, tmp, ' ');
	schedule.startTime.tm_mon = stoi(tmp) - 1;
	getline(fin, tmp, '\n');
	schedule.startTime.tm_mday = stoi(tmp);
	getline(fin, tmp, ' ');
	schedule.endTime.tm_year = stoi(tmp) - 1900;
	getline(fin, tmp, ' ');
	schedule.endTime.tm_mon = stoi(tmp) - 1;
	getline(fin, tmp, '\n');
	schedule.endTime.tm_mday = stoi(tmp);
	fin >> n;
	schedule.startTime.tm_wday = n - 1;
	schedule.endTime.tm_wday = schedule.startTime.tm_wday;
	fin.ignore();
	getline(fin, tmp, ' ');
	schedule.startTime.tm_hour = stoi(tmp);
	getline(fin, tmp, '\n');
	schedule.startTime.tm_min = stoi(tmp);
	getline(fin, tmp, ' ');
	schedule.endTime.tm_hour = stoi(tmp);
	getline(fin, tmp, '\n');
	schedule.endTime.tm_min = stoi(tmp);
	schedule.startTime = { 0, schedule.startTime.tm_min, schedule.startTime.tm_hour, schedule.startTime.tm_mday, schedule.startTime.tm_mon, schedule.startTime.tm_year, schedule.startTime.tm_wday };
	schedule.endTime = { 0, schedule.endTime.tm_min, schedule.endTime.tm_hour, schedule.endTime.tm_mday, schedule.endTime.tm_mon, schedule.endTime.tm_year, schedule.endTime.tm_wday };
	getline(fin, schedule.room, '\n');

	return schedule;
}

scheduleType* readSchedule_array(ifstream& fin, int& size)
{
	fin >> size;
	scheduleType* schedules;
	schedules = new scheduleType[size];

	for (int i = 0; i < size; ++i)
		schedules[i] = readSchedule_element(fin);

	return schedules;
}

scheduleType* readSchedule(string dir, int& size)
{
	ifstream fin;
	scheduleType* schedules = nullptr;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		schedules = readSchedule_array(fin, size);
		fin.close();
	}

	return schedules;
}

void updateStudent_element(studentType& oldStudent, studentType newStudent)
{
	if (checkUpdate_int(oldStudent.iD, newStudent.iD) == true)
		oldStudent.iD = newStudent.iD;
	if (checkUpdate_int(oldStudent.password, newStudent.password) == true)
		oldStudent.password = newStudent.password;
	if (checkUpdate_string(oldStudent.fullname, newStudent.fullname) == true)
		oldStudent.fullname = newStudent.fullname;
	if (checkUpdate_tm(oldStudent.dOB, newStudent.dOB) == true)
		oldStudent.dOB = newStudent.dOB;
	if (checkUpdate_string(oldStudent.className, newStudent.className) == true)
		oldStudent.className = newStudent.className;
	if (checkUpdate_int(oldStudent.attendingStatus, newStudent.attendingStatus) == true)
		oldStudent.attendingStatus = newStudent.attendingStatus;
	if (checkUpdate_float(oldStudent.point.midterm, newStudent.point.midterm) == true)
		oldStudent.point.midterm = newStudent.point.midterm;
	if (checkUpdate_float(oldStudent.point.final, newStudent.point.final) == true)
		oldStudent.point.final = newStudent.point.final;
	if (checkUpdate_float(oldStudent.point.bonus, newStudent.point.bonus) == true)
		oldStudent.point.bonus = newStudent.point.bonus;
	if (checkUpdate_float(oldStudent.point.total, newStudent.point.total) == true)
		oldStudent.point.total = newStudent.point.total;
	for (int i = 0; i < 10; ++i)
		if (checkUpdate_checkin(oldStudent.checkIn[i], newStudent.checkIn[i]) == true)
			oldStudent.checkIn[i] = newStudent.checkIn[i];
	if (checkUpdate_int(oldStudent.droppedStatus, newStudent.droppedStatus) == true)
		oldStudent.droppedStatus = newStudent.droppedStatus;
}

void updateStudent_array(studentType*& students, int size, studentType newStudent)
{
	for (int i = 0; i < size; ++i)
		if (students[i].iD == newStudent.iD)
			updateStudent_element(students[i], newStudent);
}

void updateStudent(studentType newStudent, studentType*& students, int& size, string dir)
{
	students = readStudent(dir, size);
	updateStudent_array(students, size, newStudent);
	writeStudent(students, size, dir);
}

void updateCourse(studentType newStudent, studentType*& students, int& size, string dir)
{
	students = readCourse(dir, size);
	updateStudent_array(students, size, newStudent);
	writeCourse(students, size, dir);
}

void filterClasses(string folder, class_courseType*& classes, int& size)
{
	int newSize = 0;
	for (int i = 0; i < size; ++i)
		if (checkFile(getDir(folder, "2019-2020-HK2-Schedule-" + classes[i].className + ".txt")) == true)
			++newSize;

	class_courseType* newClasses = new class_courseType[newSize];

	int j = 0;
	for (int i = 0; i < size; ++i)
		if (checkFile(getDir(folder, "2019-2020-HK2-Schedule-" + classes[i].className + ".txt")) == true)
		{
			newClasses[j].className = classes[i].className;
			++j;
		}

	size = newSize;
	delete[] classes;
	classes = newClasses;
}

void filterCourses_element(string folder, class_courseType& cls_crs)
{
	int n = 0;
	for (int i = 0; i < cls_crs.n_crs; ++i)
		if (checkFile(getDir(folder, "2019-2020-HK2-" + cls_crs.className + "-" + cls_crs.courseName[i] + "-Student.txt")) == true)
			++n;

	string* filteredCourses;
	filteredCourses = new string[n];

	int j = 0;
	for (int i = 0; i < cls_crs.n_crs; ++i)
		if (checkFile(getDir(folder, "2019-2020-HK2-" + cls_crs.className + "-" + cls_crs.courseName[i] + "-Student.txt")) == true)
		{
			filteredCourses[j] = cls_crs.courseName[i];
			++j;
		}

	cls_crs.n_crs = n;
	delete[] cls_crs.courseName;
	cls_crs.courseName = filteredCourses;
}

void filterCourses_student_element(int iD, string folder, class_courseType& cls_crs)
{
	filterCourses_element(folder, cls_crs);
	studentType* students;
	int n;
	int size = 0;
	
	for (int i = 0; i < cls_crs.n_crs; ++i)
	{
		students = readCourse(getDir(folder, "2019-2020-HK2-" + cls_crs.className + "-" + cls_crs.courseName[i] + "-Student.txt"), n);
		if (positionOfStudent_array(iD, students, n) != -1)
			++size;
	}

	string* courses = new string[size];
	int j = 0;
	for (int i = 0; i < cls_crs.n_crs; ++i)
	{
		students = readCourse(getDir(folder, "2019-2020-HK2-" + cls_crs.className + "-" + cls_crs.courseName[i] + "-Student.txt"), n);
		if (positionOfStudent_array(iD, students, n) != -1)
		{
			courses[j] = cls_crs.courseName[i];
			++j;
		}
	}

	cls_crs.n_crs = size;
	delete[] cls_crs.courseName;
	cls_crs.courseName = courses;
}

void filterCourses(string folder, class_courseType*& classes, int& size)
{
	filterClasses(folder, classes, size);
	for (int i = 0; i < size; ++i)
	{
		classes[i].courseName = readSchedule_course(getDir(folder, "2019-2020-HK2-Schedule-" + classes[i].className + ".txt"), classes[i].n_crs);
		filterCourses_element(folder, classes[i]);
	}
}

void filterCourses_student(int iD, string folder, class_courseType*& classes, int& size)
{
	filterClasses(folder, classes, size);
	for (int i = 0; i < size; ++i)
	{
		classes[i].courseName = readSchedule_course(getDir(folder, "2019-2020-HK2-Schedule-" + classes[i].className + ".txt"), classes[i].n_crs);
		filterCourses_student_element(iD, folder, classes[i]);
	}
}

academicYear_courseType* initAcademicYear_courses(string folder, int& size)
{
	ifstream fin;
	academicYear_courseType* A;
	size = 1;
	A = new academicYear_courseType[size];
	A[0].academicYear = "2019-2020";
	A[0].n_smt = 1;
	A[0].semester_courses = new semester_courseType[1];
	A[0].semester_courses[0].semesterName = "HK2";

	class_courseType* classes;
	int n;
	string dir = getDir(folder, "Class.txt");

	classes = readClass(dir, n);
	filterCourses(folder, classes, n);

	A[0].semester_courses[0].n_cls = n;
	A[0].semester_courses[0].class_courses = classes;

	// Complete version of this function will be update soon
	/*
	ifstream fin;
	academicYear_courseType* A;
	string dir = getDir(folder, "Semester-Example.txt");

	A = readSemester(dir, size);
	cout << A[2].semester_courses[0].semesterName << endl;
	cout << "n_smt" << endl;
	for (int i = 0; i < size; ++i)
		cout << A[i].n_smt << endl;
	cout << "size" << endl;
	cout << size << endl;

	string* classes;
	int clsNum;
	dir = getDir(folder, "Class.txt");

	classes = readClass(dir, clsNum);
	cout << classes[5] << endl;
	cout << clsNum << endl;


	int newSize = 0;
	int tmp_i = 0;
	int tmp_j = 0;
	int* new_n_smt;
	new_n_smt = new int[size];
	int** new_n_cls;
	new_n_cls = new int* [size];
	for (int i = 0; i < size; ++i)
		new_n_cls[i] = new int[A[i].n_smt];

	for (int i = 0; i < size; ++i)
	{
		new_n_smt[i] = 0;
		for (int j = 0; j < A[i].n_smt; ++j)
			new_n_cls[i][j] = 0;
	}

	for (int i = 0; i < size; ++i)
	{
		cout << "new_n_smt[" << i << "]" << endl;
		cout << new_n_smt[i] << endl;
		cout << endl;
		for (int j = 0; j < A[i].n_smt; ++j)
		{
			cout << "new_n_cls[" << i << "][" << j << "]" << endl;
			cout << new_n_cls[i][j] << endl;
		}
		cout << endl;
		cout << endl;
	}

	for (int i = 0; i < size; ++i)
	{
		tmp_i = i;
		for (int j = 0; j < A[i].n_smt; ++j)
		{
			tmp_j = j;

			for (int k = 0; k < clsNum; ++k)
				if (checkFile(getDir_schedule(folder, A[i].academicYear, A[i].semester_courses[j].semesterName, classes[k])) == true)
				{
					++new_n_cls[i][j];
					if (tmp_j == j)
					{
						++tmp_j;
						++new_n_smt[i];
						if (tmp_i == i)
						{
							++tmp_i;
							++newSize;
						}
					}
				}
		}
	}

	cout << "newSize" << endl;
	cout << newSize << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << "new_n_smt[" << i << "]" << endl;
		cout << new_n_smt[i] << endl;
		cout << endl;
		for (int j = 0; j < A[i].n_smt; ++j)
		{
			cout << "new_n_cls[" << i << "][" << j << "]" << endl;;
			cout << new_n_cls[i][j] << endl;
		}
		cout << endl;
		cout << endl;
	}

	academicYear_courseType* newA;
	newA = new academicYear_courseType[newSize];

	int ni = 0;
	int nj = 0;
	int count = 0;

	for (int i = 0; i < size; ++i)
	{
		tmp_i = i;

		for (int j = 0; j < A[i].n_smt; ++j)
		{
			tmp_j = j;

			for (int k = 0; k < clsNum; ++k)
			{
				if (checkFile(getDir_schedule("Files", A[i].academicYear, A[i].semester_courses[j].semesterName, classes[k])) == true)
				{
					++count;
					if (tmp_j == j)
					{
						if (tmp_i == i)
						{
							newA[ni].n_smt = new_n_smt[i];
							newA[ni].semester_courses = new semester_courseType[new_n_smt[i]];
							++tmp_i;
						}

						newA[ni].semester_courses[nj].n_cls = new_n_cls[i][j];
						newA[ni].semester_courses[nj].class_courses = new class_courseType[new_n_cls[i][j]];

						++tmp_j;
					}
				}
			}

			if (count > 0)
				++nj;
		}

		if (count > 0)
		{
			++ni;
			nj = 0;
			count = 0;
		}
	}
	*/

	return A;
}

academicYear_courseType* initAcademicYear_courses_student(int iD, string folder, int& size)
{
	ifstream fin;
	academicYear_courseType* A;
	size = 1;
	A = new academicYear_courseType[size];
	A[0].academicYear = "2019-2020";
	A[0].n_smt = 1;
	A[0].semester_courses = new semester_courseType[1];
	A[0].semester_courses[0].semesterName = "HK2";

	class_courseType* classes;
	int n;
	string dir = getDir(folder, "Class.txt");

	classes = readClass(dir, n);
	filterCourses_student(iD, folder, classes, n);

	A[0].semester_courses[0].n_cls = n;
	A[0].semester_courses[0].class_courses = classes;

	return A;
}

academicYear_courseType readSemester_element(ifstream& fin, int pos)
{
	academicYear_courseType acdmY_crs;

	fin.clear();
	fin.seekg(pos, fin.beg);
	getline(fin, acdmY_crs.academicYear, '\n');
	pos += acdmY_crs.academicYear.length() + 1;

	int n_smt = 0;
	string tmp;

	while (getline(fin, tmp, '\n') && tmp != "")
		++n_smt;
	
	fin.clear();
	fin.seekg(pos, fin.beg);

	acdmY_crs.n_smt = n_smt;
	acdmY_crs.semester_courses = new semester_courseType[n_smt];

	for (int i = 0; i < n_smt; ++i)
		getline(fin, acdmY_crs.semester_courses[i].semesterName, '\n');

	fin.ignore();

	return acdmY_crs;
}

academicYear_courseType* readSemester_array(ifstream& fin, int& size)
{
	fin >> size;
	int pos = 2;
	academicYear_courseType* acdmY_crses;
	acdmY_crses = new academicYear_courseType[size];

	for (int i = 0; i < size; ++i)
	{
		acdmY_crses[i] = readSemester_element(fin, pos);
		pos += acdmY_crses[i].academicYear.length() + 1;
		for (int j = 0; j < acdmY_crses[i].n_smt; ++j)
			pos += acdmY_crses[i].semester_courses[j].semesterName.length() + 1;
		++pos;
	}

	return acdmY_crses;
}

academicYear_courseType* readSemester(string dir, int& size)
{
	academicYear_courseType* acdmY_crses = nullptr;
	ifstream fin;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{	
		acdmY_crses = readSemester_array(fin, size);
		fin.close();
	}

	return acdmY_crses;
}

string* readSchedule_course(string dir, int& size)
{
	scheduleType* schedules;
	schedules = readSchedule(dir, size);

	string* courses;
	courses = new string[size];

	for (int i = 0; i < size; ++i)
	{
		courses[i] = schedules[i].courseName;
	}

	return courses;
}

void chooseCourse(academicYear_courseType* A, int size, int& a, int& s, int& c, int& cs)
{
	cout << "Please choose academic year: " << endl;
	for (int i = 0; i < size; ++i)
		cout << "[" << i + 1 << "]: " << A[i].academicYear << endl;
	cin >> a;
	--a;

	cout << "Please choose semester: " << endl;
	for (int i = 0; i < A[a].n_smt; ++i)
		cout << "[" << i + 1 << "]: " << A[a].semester_courses[i].semesterName << endl;
	cin >> s;
	--s;

	cout << "Please choose class: " << endl;
	for (int i = 0; i < A[a].semester_courses[s].n_cls; ++i)
		cout << "[" << i + 1 << "]: " << A[a].semester_courses[s].class_courses[i].className << endl;
	cin >> c;
	--c;

	cout << "Please choose course: " << endl;
	for (int i = 0; i < A[a].semester_courses[s].class_courses[c].n_crs; ++i)
		cout << "[" << i + 1 << "]: " << A[a].semester_courses[s].class_courses[c].courseName[i] << endl;
	cin >> cs;
	--cs;
}

time_t getCurrentTime()
{
	system_clock::time_point t = system_clock::now();
	time_t currentTime;

	currentTime = system_clock::to_time_t(t);

	return currentTime;
}

bool checkDuration(durationType duration, time_t time)
{
	time_t startTime, endTime;
	tm tmp;
	tmp = duration.startTime;
	startTime = mktime(&tmp);
	tmp = duration.endTime;
	endTime = mktime(&tmp);

	if (difftime(time, startTime) >= 0 && difftime(time, endTime) <= 0)
		return true;
	return false;
}

void checkIn_element(studentType& student, time_t time)
{
	tm tmp;
	time_t t;
	for (int i = 0; i < 10; ++i)
	{
		tmp = student.checkIn[i].time.endTime;
		t = mktime(&tmp);
		if (checkDuration(student.checkIn[i].time, time) == true)
			student.checkIn[i].checkIn = 1;
		else if (student.checkIn[i].checkIn == -1 && difftime(time, t) > 0)
			student.checkIn[i].checkIn = 0;
	}
}

void checkIn(int iD, string dir)
{
	studentType* students;
	int size;

	students = readCourse(dir, size);
	int pos = positionOfStudent_array(iD, students, size);

	time_t t = getCurrentTime();
	checkIn_element(students[pos], t);

	updateCourse(students[pos], students, size, dir);
}

void viewCheckIn(int iD, string dir)
{
	studentType* students;
	int size;
	students = readCourse(dir, size);
	int pos = positionOfStudent_array(iD, students, size);
	for (int i = 0; i < 10; ++i)
	{
		cout << setw(2) << setfill('0') << students[pos].checkIn[i].time.startTime.tm_mday << "/";
		cout << setw(2) << setfill('0') << students[pos].checkIn[i].time.startTime.tm_mon + 1 << "/";
		cout << setw(2) << setfill(' ') << students[pos].checkIn[i].time.startTime.tm_year + 1900 << "  ";
		if (students[pos].checkIn[i].checkIn == 1)
			cout << "Yes" << endl;
		else if (students[pos].checkIn[i].checkIn == 0)
			cout << "No" << endl;
		else
			cout << endl;
	}
}

int positionOfCourse_array(string courseName, scheduleType* schedules, int size)
{
	for (int i = 0; i < size; ++i)
		if (schedules[i].courseName == courseName)
			return i;
	return -1;
}

void viewSchedule(string courseName, string dir)
{
	scheduleType* schedules;
	int size;
	schedules = readSchedule(dir, size);
	int pos = positionOfCourse_array(courseName, schedules, size);

	cout << schedules[pos].courseName << endl;
	cout << schedules[pos].courseNameFull << endl;
	cout << schedules[pos].className << endl;
	cout << schedules[pos].lecturerFull << endl;
	cout << schedules[pos].lecturerDegree << endl;
	cout << setw(2) << setfill('0') << schedules[pos].startTime.tm_mday << "/" << setw(2) << setfill('0') << schedules[pos].startTime.tm_mon + 1 << "/";
	cout << schedules[pos].startTime.tm_year + 1900 << endl;
	cout << setw(2) << setfill('0') << schedules[pos].endTime.tm_mday << "/" << setw(2) << setfill('0') << schedules[pos].endTime.tm_mon + 1 << "/";
	cout << setw(2) << setfill(' ') << schedules[pos].endTime.tm_year + 1900 << endl;
	cout << schedules[pos].startTime.tm_wday + 1 << endl;
	cout << schedules[pos].startTime.tm_hour << ":" << schedules[pos].startTime.tm_min << endl;
	cout << schedules[pos].endTime.tm_hour << ":" << schedules[pos].endTime.tm_min << endl;
	cout << schedules[pos].room << endl;
	cout << endl;
}

void viewScore_student(int iD, string dir)
{
	studentType* students;
	int size;
	students = readCourse(dir, size);
	int pos = positionOfStudent_array(iD, students, size);

	string space = "                         ";

	space = space.replace(0, 8, "Fullname");
	cout << "No ID        " << space << "DOB       " << "  Midterm Final   Bonus   Total   " << "Class" << endl;

	space = "                         ";
	{
		space = space.replace(0, students[pos].fullname.length(), students[pos].fullname);
		cout << pos + 1 << ". " << students[pos].iD << "  " << space;
		space = "                         ";
		cout << setw(2) << setfill('0') << students[pos].dOB.tm_mday << "/" << setw(2) << setfill('0') << students[pos].dOB.tm_mon + 1 << "/" << students[pos].dOB.tm_year + 1900;
		cout << "  ";
		cout << setw(8) << setfill(' ');
		cout.setf(ios::adjustfield, ios::left);
		cout << setw(8) << students[pos].point.midterm;
		cout << setw(8) << students[pos].point.final;
		cout << setw(8) << students[pos].point.bonus;
		cout << setw(8) << students[pos].point.total;
		cout.unsetf(ios::adjustfield);
		cout << students[pos].className << endl;
	}
}

void searchViewScore()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);
	viewScore(dir);
}

void exportScore()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	studentType* students;
	int size;
	students = readCourse(dir, size);
	dir = getDir_score(folder, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);
	writeScore(students, size, dir);
	cout << "Mission complete." << endl;
}

void searchViewAttendance()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	viewCourse_attendance(dir);
}

string getDir_course_csv(string folder, string academicYear, string semester, string className, string courseName)
{
	string dir = folder + "/" + academicYear + "-" + semester + "-" + className + "-" + courseName + "-Attendances.csv";
	return dir;
}

void exportAttendances()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	studentType* students;
	int size;
	students = readCourse(dir, size);
	students = attendanceCourse_array(students, size, size);
	dir = getDir_course_csv(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);
	writeCourse_csv(students, size, dir);
	cout << "Mission complete." << endl;
}

void searchViewCourse()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	viewCourse(dir);
}

void editAttendance()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	studentType* students;
	int size;
	students = readCourse(dir, size);
	students = attendanceCourse_array(students, size, size);
	viewCourse_attendance(dir);

	cout << "Enter student's ordinal number or ID:" << endl;
	int choice;
	cin >> choice;
	int pos = positionOfStudent_array(choice, students, size);
	cout << "Please choose type of information:" << endl;
	cout << "[1]: Fullname" << endl;
	cout << "[2]: Date of birth" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Student's current fullname:" << endl;
		cout << students[pos].fullname << endl;
		cout << "Enter new fullname:" << endl;
		cin.ignore();
		string input;
		getline(cin, input, '\n');
		students[pos].fullname = input;
		break;
	}

	case 2:
	{
		cout << "Student's current DOB:" << endl;
		cout << setw(2) << setfill('0') << students[pos].dOB.tm_mday << "-" << setw(2) << setfill('0') << students[pos].dOB.tm_mon + 1 << "-" << students[pos].dOB.tm_year + 1900 << endl;
		cout << "Enter new DOB in format \"dd mm yyyy\":" << endl;
		int day, mon, year;
		cin >> day >> mon >> year;
		students[pos].dOB.tm_mday = day;
		students[pos].dOB.tm_mon = mon - 1;
		students[pos].dOB.tm_year = year - 1900;
		break;
	}

	default:
		break;
	}
	studentType tmp = students[pos];
	studentType* newStudents;
	int newSize;
	dir = getDir(folder, "Student.txt");
	updateStudent(tmp, newStudents, newSize, dir);
	dir = getDir_class(folder, A[a].semester_courses[s].class_courses[c].className);
	updateStudent(tmp, newStudents, newSize, dir);

	academicYear_courseType* B;
	int m;
	B = initAcademicYear_courses_student(tmp.iD, folder, m);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < B[i].n_smt; ++j)
			for (int k = 0; k < B[i].semester_courses[j].n_cls; ++k)
				for (int l = 0; l < B[i].semester_courses[j].class_courses[k].n_crs; ++l)
				{
					dir = getDir_course(folder, B[i].academicYear, B[i].semester_courses[j].semesterName, B[i].semester_courses[j].class_courses[k].className, B[i].semester_courses[j].class_courses[k].courseName[l]);
					updateCourse(tmp, newStudents, newSize, dir);
				}


	cout << "Edit complete." << endl;
}

void importScore()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);

	folder = "Import";

	cout << "Enter file directory:" << endl;
	cout << "[1]: Use default directory" << endl;
	cout << "[2]: Enter new directory" << endl;
	int choice;
	cin >> choice;
	string dir;

	switch (choice)
	{
	case 1:
	{
		dir = getDir_score(folder, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);
		break;
	}

	case 2:
	{
		cin.ignore();
		getline(cin, dir, '\n');
		break;
	}

	default:
		break;
	}

	studentType* students;
	int size;
	students = readScore(dir, size);
	studentType tmp;
	studentType* newStudents;
	int newSize;
	folder = "Files";

	for (int k = 0; k < size; ++k)
	{
		tmp = students[k];

		dir = getDir(folder, "Student.txt");
		updateStudent(tmp, newStudents, newSize, dir);
		dir = getDir_class(folder, A[a].semester_courses[s].class_courses[c].className);
		updateStudent(tmp, newStudents, newSize, dir);

		academicYear_courseType* B;
		int m;
		B = initAcademicYear_courses_student(tmp.iD, folder, m);

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < B[i].n_smt; ++j)
				for (int k = 0; k < B[i].semester_courses[j].n_cls; ++k)
					for (int l = 0; l < B[i].semester_courses[j].class_courses[k].n_crs; ++l)
					{
						dir = getDir_course(folder, B[i].academicYear, B[i].semester_courses[j].semesterName, B[i].semester_courses[j].class_courses[k].className, B[i].semester_courses[j].class_courses[k].courseName[l]);
						updateCourse(tmp, newStudents, newSize, dir);
					}
	}

	cout << "Import complete." << endl;
}

void searchEditGrade()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	viewScore(dir);
	studentType* students;
	int size;
	students = readCourse(dir, size);

	cout << "Enter student's ordinal number or ID:" << endl;
	int choice;
	cin >> choice;
	int pos = positionOfStudent_array(choice, students, size);
	cout << "Please choose kind of point:" << endl;
	cout << "[1]: Midterm Point" << endl;
	cout << "[2]: Final Point" << endl;
	cout << "[3]: Bonus Point" << endl;
	cout << "[4]: Total Point" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Student's current point:" << endl;
		cout << students[pos].point.midterm << endl;
		cout << "Enter new point:" << endl;
		float input;
		cin >> input;
		students[pos].point.midterm = input;
		break;
	}

	case 2:
	{
		cout << "Student's current point:" << endl;
		cout << students[pos].point.final << endl;
		cout << "Enter new point:" << endl;
		float input;
		cin >> input;
		students[pos].point.final = input;
		break;
	}

	case 3:
	{
		cout << "Student's current point:" << endl;
		cout << students[pos].point.bonus << endl;
		cout << "Enter new point:" << endl;
		float input;
		cin >> input;
		students[pos].point.bonus = input;
		break;
	}

	case 4:
	{
		cout << "Student's current point:" << endl;
		cout << students[pos].point.total << endl;
		cout << "Enter new point:" << endl;
		float input;
		cin >> input;
		students[pos].point.total = input;
		break;
	}

	default:
		break;
	}

	studentType tmp = students[pos];
	studentType* newStudents;
	int newSize;
	dir = getDir(folder, "Student.txt");
	updateStudent(tmp, newStudents, newSize, dir);
	dir = getDir_class(folder, A[a].semester_courses[s].class_courses[c].className);
	updateStudent(tmp, newStudents, newSize, dir);

	academicYear_courseType* B;
	int m;
	B = initAcademicYear_courses_student(tmp.iD, folder, m);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < B[i].n_smt; ++j)
			for (int k = 0; k < B[i].semester_courses[j].n_cls; ++k)
				for (int l = 0; l < B[i].semester_courses[j].class_courses[k].n_crs; ++l)
				{
					dir = getDir_course(folder, B[i].academicYear, B[i].semester_courses[j].semesterName, B[i].semester_courses[j].class_courses[k].className, B[i].semester_courses[j].class_courses[k].courseName[l]);
					updateCourse(tmp, newStudents, newSize, dir);
				}

	cout << "Edit complete." << endl;
}

void searchViewScore()
{
	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	cout << "Scoreboard of " << A[a].semester_courses[s].class_courses[c].className << " - " << A[a].semester_courses[s].class_courses[c].courseName[cs] << ":" << endl;
	viewScore(dir);
}