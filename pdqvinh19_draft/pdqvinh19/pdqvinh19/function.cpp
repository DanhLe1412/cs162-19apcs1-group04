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
				displayListCoursesSemester();
				break;
			}

			case 21:
			{
				ifstream fin;
				int n;
				studentType* a;

				fin.open("pdqvinh19data/2019-2020-HK2-19APCS1-CS162-Student.txt");
				if (!fin.is_open())
					cout << "Cannot open file." << endl;
				else
				{
					a = loadStudentArray(fin, n);
					listStudentCourse(a, n);

					fin.close();
				}

				break;
			}

			case 22:
			{
				ifstream fin;
				int n;
				studentType* a;

				fin.open("pdqvinh19data/2019-2020-HK2-19APCS1-CM101-Student.txt");
				if (!fin.is_open())
					cout << "Cannot open file." << endl;
				else
				{
					a = loadStudentAttendanceArray(fin, n);
					listStudentAttendanceCourse(a, n);

					fin.close();
				}
				break;
			}

			case 24:
			{
				studentType* scoreBoard;
				importScoreBoard(scoreBoard);
				break;
			}

			case 25:
			{
				editGrade();
				break;
			}

			case 26:
			{
				ifstream fin;

				studentType* a;
				int n;

				fin.open("pdqvinh19data/19APCS1-CS162-Scoreboard.txt");
				if (!fin.is_open())
					cout << "Cannot open file." << endl;
				else
				{
					a = loadScoreBoard(fin, n);
					printScoreBoard(a, n);
					fin.close();
				}
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
			// Need to change student ID input
			int iD = 19127001;
			chooseCourseAndCheckIn(iD);
			break;
		}

		case 17:
		{
			// Need to change student ID input
			int iD = 19127001;
			chooseCourseAndDisplayCheckInResult(iD);
			break;
		}

		case 18:
		{
			// Need to change student ID input
			int iD = 19127001;
			viewSchedule(iD);
			break;
		}

		case 19:
		{
			// Need to change student ID input
			int iD = 19127001;
			viewScore(iD);
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

int loadN(ifstream &fin)
{
	int n;
	fin >> n;
	return n;
}

studentType loadStudent(ifstream &fin)
{
	studentType s;
	fin >> s.iD;
	fin.ignore();
	getline(fin,s.fullName,'\n');
	return s;
}

studentType* loadStudentArray(ifstream& fin, int &n)
{
	studentType* a;
	n = loadN(fin);
	a = new studentType[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = loadStudent(fin);
	}
	return a;
}

void listStudentCourse(studentType* a, int n)
{
	cout << "Students in 19APCS1 - CS162: " << n << ": ";
	for (int i = 0; i < n - 1; ++i)
		cout << a[i].fullName << ", ";
	cout << a[n - 1].fullName << endl;
}

studentType loadStudentAttendance(ifstream& fin)
{
	studentType s;
	fin >> s.iD;
	fin.ignore();
	getline(fin, s.fullName, '\n');
	fin >> s.status;

	return s;
}

studentType* loadStudentAttendanceArray(ifstream& fin, int& n)
{
	studentType* a;
	n = loadN(fin);
	a = new studentType[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = loadStudentAttendance(fin);
	}
	return a;
}

int countStudentAttendance(studentType* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i].status == 1)
			++count;
	}

	return count;
}

void listStudentAttendanceCourse(studentType* a, int n)
{
	cout << "Students attending in 19APCS1 - CM101: " << countStudentAttendance(a, n) << ": ";
	int tmp = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i].status == 1)
		{
			cout << a[i].fullName;
			tmp = i;
		}

		if (tmp == n - 1)
			cout << endl;
		else
		{
			if (i > tmp)
				cout << endl;
			else
				if (a[i].status == 1)
					cout << ", ";
		}
	}
}

int countCSV(ifstream& fin)
{
	string no, finalPoint, tmp, iDStr;
	studentType s;

	getline(fin, tmp, '\n');

	while (getline(fin, tmp, '\n'))
	{
		getline(fin, no, ',');
		getline(fin, iDStr, ',');
		getline(fin, s.fullName, ',');
		getline(fin, finalPoint, '\n');
	}

	int count;
	count = stoi(no);

	return count;
}

studentType* loadScoreBoardCSV(ifstream& fin, int size)
{
	studentType* a;
	a = new studentType[size];
	string tmp, no, finalPointStr, iDStr;
	getline(fin, tmp, '\n');

	for (int i = 0; i < size; ++i)
	{
		getline(fin, no, ',');
		getline(fin, iDStr, ',');
		a[i].iD = stoi(iDStr);
		getline(fin, a[i].fullName, ',');
		getline(fin, finalPointStr, '\n');
		a[i].finalPoint = stof(finalPointStr);
	}

	return a;
}

void saveScoreBoard(ofstream& fout, studentType* student, int size)
{
	fout << size << endl;
	for (int i = 0; i < size; ++i)
	{
		fout << student[i].iD << endl;
		fout << student[i].fullName << endl;
		fout << student[i].finalPoint << endl;
		if (i < size - 1)
			fout << endl;
	}
}

void importScoreBoard(studentType* &scoreBoard)
{
	ifstream fin;
	ofstream fout;

	cout << "Enter the directory of the file you want to import: " << endl;
	string dir;
	cin.ignore();
	getline(cin, dir, '\n');
	// Example for dir:
	// dir = "pdqvinh19data/19APCS1-CS162-Scoreboard.csv";

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		int scoreBoardSize = countCSV(fin);

		// Return to the beginning position
		fin.clear();
		fin.seekg(0, fin.beg);

		scoreBoard = loadScoreBoardCSV(fin, scoreBoardSize);

		fout.open("pdqvinh19data/19APCS1-CS162-Scoreboard.txt");
		if (!fout.is_open())
			cout << "Cannot write file." << endl;
		else
		{
			saveScoreBoard(fout, scoreBoard, scoreBoardSize);
			fout.close();
		}

		fin.close();
	}
}

studentType loadStudentScore(ifstream& fin)
{
	studentType s;

	fin >> s.iD;
	fin.ignore();
	getline(fin, s.fullName, '\n');
	fin >> s.finalPoint;

	return s;
}

studentType* loadScoreBoard(ifstream& fin, int& n)
{
	studentType* a;
	n = loadN(fin);
	a = new studentType[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = loadStudentScore(fin);
	}
	return a;
}

void printScoreBoard(studentType* scoreBoard, int size)
{
	string space = "                         ";
	for (int i = 0; i < size; ++i)
	{
		cout << scoreBoard[i].iD << "   " << space.replace(0, scoreBoard[i].fullName.length(), scoreBoard[i].fullName) << scoreBoard[i].finalPoint;
		space = "                         ";
		if (i < size - 1)
			cout << endl;
	}
}

int findPositionStudent(studentType* scoreBoard, int size, int x)
{
	if (x < 500)
	{
		if (x >= 0 && x <= size - 1)
			return x - 1;
		else
			return -1;
	}
	else
	{
		for (int i = 0; i < size; ++i)
			if (scoreBoard[i].iD == x)
				return i;
		return -1;
	}
}


void editGrade()
{
	ifstream fin;
	ofstream fout;
	int size, x, pos;
	studentType* scoreBoard;
	float newFinalPoint;

	fin.open("pdqvinh19data/19APCS1-CS162-Scoreboard.txt");
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		scoreBoard = loadScoreBoard(fin, size);

		cout << "Enter ordinal number / ID of student you want to edit grade: " << endl;
		cin >> x;
		pos = findPositionStudent(scoreBoard, size, x);

		cout << "Current grade: " << endl;
		cout << scoreBoard[pos].finalPoint << endl;

		cout << "Enter new grade: " << endl;
		cin >> newFinalPoint;
		scoreBoard[pos].finalPoint = newFinalPoint;

		fout.open("pdqvinh19data/19APCS1-CS162-Scoreboard.txt");
		if (!fout.is_open())
			cout << "Cannot write file." << endl;
		else
		{
			saveScoreBoard(fout, scoreBoard, size);
			fout.close();
		}

		fin.close();
	}
}

string* listCoursesFromClass(string className, int &size)
{
	ifstream fin;
	size = 0;
	string dir = "pdqvinh19data/2019-2020-HK2-Schedule-" + className + ".txt";
	string* coursesArray = nullptr;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		coursesArray = loadCoursesArray(fin, size);
		fin.close();
	}

	return coursesArray;
}

string loadCourse(ifstream& fin)
{
	string courseName;

	getline(fin, courseName, '\n');

	return courseName;
}

string* loadCoursesArray(ifstream& fin, int& size)
{
	size = loadN(fin);
	fin.ignore();

	string* coursesArray;
	coursesArray = new string[size];

	for (int i = 0; i < size; ++i)
	{
		coursesArray[i] = loadCourse(fin);
	}

	return coursesArray;
}

bool checkStudentCourseAttendance(string courseName, int& size, int iD)
{
	studentType* student;
	student = loadStudentFromCourse(courseName, size);

	return checkStudentID(student, size, iD);
}

bool checkStudentID(studentType* student, int size, int iD)
{
	for (int i = 0; i < size; ++i)
		if (iD == student[i].iD)
			return true;
	return false;
}


studentType* loadStudentFromCourse(string courseName, int& size)
{
	ifstream fin;
	string dir;
	studentType* student = nullptr;
	size = 0;

	dir = "pdqvinh19data/2019-2020-HK2-" + courseName + "-Student+Time.txt";

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		student = loadStudentArrayNew(fin, size);
		fin.close();
	}

	return student;
}

studentType loadStudentNew(ifstream& fin)
{
	studentType s;
	durationType t;
	string tmp;
	fin >> s.iD;
	fin.ignore();
	getline(fin, s.fullName, '\n');
	for (int i = 0; i < 10; ++i)
	{
		t = loadDuration(fin);
		getline(fin, tmp, '\n');
	}

	return s;
}

studentType* loadStudentArrayNew(ifstream& fin, int& n)
{
	studentType* a;
	n = loadN(fin);
	fin.ignore();
	a = new studentType[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = loadStudentNew(fin);
	}
	return a;
}

void displayCoursesOfStudentID(int iD)
{
	string className[2] = { "19APCS1", "19CLC1" };
	string* coursesArrayFromClass[2];
	int coursesArraySizeFromClass[2];
	int size;
	int pos = 1;

	for (int i = 0; i < 2; ++i)
		coursesArrayFromClass[i] = listCoursesFromClass(className[i], coursesArraySizeFromClass[i]);

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < coursesArraySizeFromClass[i]; ++j)
			if (checkStudentCourseAttendance(className[i] + "-" + coursesArrayFromClass[i][j], size, iD) == true)
			{
				cout << pos << ". " << coursesArrayFromClass[i][j] << endl;
				++pos;
			}

}

durationType loadDuration(ifstream &fin)
{
	durationType t;
	string tmp;
	getline(fin, tmp, ' ');
	t.startTime.tm_year= stoi(tmp) - 1900;
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

studentCheckInType loadStudentCheckInCourse(ifstream &fin)
{
	studentCheckInType student;
	string tmp;
	
	fin >> student.student.iD;
	fin.ignore();
	getline(fin, student.student.fullName, '\n');
	for (int i = 0; i < 10; ++i)
	{
		student.checkIn[i].time = loadDuration(fin);
		getline(fin, tmp, '\n');
		student.checkIn[i].checkIn = stoi(tmp);
	}

	return student;
}

studentCheckInType* loadStudentCheckInCourseArray(ifstream& fin, int &size)
{
	size = loadN(fin);
	fin.ignore();
	studentCheckInType* student;
	student = new studentCheckInType[size];
	for (int i = 0; i < size; ++i)
		student[i] = loadStudentCheckInCourse(fin);

	return student;
}

void writeStudentCheckInCourseArray(ofstream& fout, studentCheckInType* student, int size)
{
	fout << size << endl;
	for (int i = 0; i < size; ++i)
	{
		fout << student[i].student.iD << endl;
		fout << student[i].student.fullName << endl;
		for (int j = 0; j < 10; ++j)
		{
			fout << student[i].checkIn[j].time.startTime.tm_year + 1900 << " ";
			fout << setw(2) << setfill('0') << student[i].checkIn[j].time.startTime.tm_mon + 1 << " ";
			fout << setw(2) << setfill('0') << student[i].checkIn[j].time.startTime.tm_mday << " ";
			fout << setw(2) << setfill('0') << student[i].checkIn[j].time.startTime.tm_hour << " ";
			fout << setw(2) << setfill('0') << student[i].checkIn[j].time.startTime.tm_min << " ";
			fout << setw(2) << setfill('0') << student[i].checkIn[j].time.endTime.tm_hour << " ";
			fout << setw(2) << setfill('0') << student[i].checkIn[j].time.endTime.tm_min << " ";
			fout << student[i].checkIn[j].checkIn << endl;
		}
		fout << endl;
	}
}

void checkYes(checkInType &checkIn)
{
	checkIn.checkIn = 1;
}

void checkNo(checkInType &checkIn)
{
	checkIn.checkIn = 0;
}

bool checkBetweenDuration(durationType duration, time_t time)
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

void checkInDuration(checkInType &checkIn, time_t time)
{
	if (checkBetweenDuration(checkIn.time, time) == 1)
		checkYes(checkIn);
}

time_t currentTime()
{
	system_clock::time_point t = system_clock::now();
	time_t currentTime;

	currentTime = system_clock::to_time_t(t);

	return currentTime;
}

void checkInArray(checkInType checkIn[], int size, time_t time)
{
	tm tmp;
	time_t t;
	for (int i = 0; i < size; ++i)
	{
		tmp = checkIn[i].time.endTime;
		t = mktime(&tmp);
		if (checkBetweenDuration(checkIn[i].time, time) == 1)
			checkYes(checkIn[i]);
		else if (checkIn[i].checkIn == -1 && difftime(time, t) > 0)
			checkNo(checkIn[i]);
	}
}

int findIDStudentCheckInCourseArray(studentCheckInType* student, int size, int iD)
{
	for (int i = 0; i < size; ++i)
	{
		if (student[i].student.iD == iD)
			return i;
	}
	return -1;
}

void checkInStudentCourseArray(studentCheckInType* student, int size, int iD, time_t time)
{
	int x = findIDStudentCheckInCourseArray(student, size, iD);
	checkInArray(student[x].checkIn, 10, time);
}

void checkInCourseName(string courseName, int iD, time_t time)
{
	studentCheckInType* student;
	int size;
	ifstream fin;
	ofstream fout;
	string dir;
	dir = "pdqvinh19data/2019-2020-HK2-" + courseName + "-Student+Time.txt";

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		student = loadStudentCheckInCourseArray(fin, size);
		checkInStudentCourseArray(student, size, iD, time);

		fin.close();

		fout.open(dir);
		if (!fout.is_open())
			cout << "Cannot write file." << endl;
		else
		{
			writeStudentCheckInCourseArray(fout, student, size);
			fout.close();
		}
	}
}

string* loadClassArray(ifstream& fin, int& size)
{
	size = loadN(fin);
	string* classArray;
	classArray = new string[size];

	fin.ignore();

	for (int i = 0; i < size; ++i)
		getline(fin, classArray[i], '\n');

	return classArray;
}

classAndCourse* initializeClassCourseArray(int& size)
{
	ifstream f1, f2;
	classAndCourse* classCourseArray;

	string* className = nullptr;

	f1.open("pdqvinh19data/Class.txt");
	if (!f1.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		className = loadClassArray(f1, size);
		f1.close();
	}

	classCourseArray = new classAndCourse[size];

	for (int i = 0; i < size; ++i)
		classCourseArray[i].className = className[i];

	for (int i = 0; i < size; ++i)
	{
		string dir = "pdqvinh19data/2019-2020-HK2-Schedule-" + className[i] + ".txt";
		f2.open(dir);
		if (!f2.is_open())
			cout << "Cannot open file." << endl;
		else
		{
			classCourseArray[i].courseName = loadCoursesArray(f2, classCourseArray[i].courseQuantity);
			f2.close();
		}
	}

	return classCourseArray;
}

courseNameLongAndShort* availableCoursesOfStudentID(classAndCourse* classCourseArray, int classCourseSize, int iD, int& size)
{
	size = 0;
	string courseName = "";
	ifstream fin;
	courseNameLongAndShort* availableCourses;

	for (int i = 0; i < classCourseSize; ++i)
	{
		for (int j = 0; j < classCourseArray[i].courseQuantity; ++j)
		{
			courseName = classCourseArray[i].className + "-" + classCourseArray[i].courseName[j];
			if (checkStudentCourseAttendanceCheckIn(courseName, iD) == true)
				++size;
		}
	}

	availableCourses = new courseNameLongAndShort[size];

	int k = 0;

	for (int i = 0; i < classCourseSize; ++i)
	{
		for (int j = 0; j < classCourseArray[i].courseQuantity; ++j)
		{
			courseName = classCourseArray[i].className + "-" + classCourseArray[i].courseName[j];
			if (checkStudentCourseAttendanceCheckIn(courseName, iD) == true)
			{
				availableCourses[k].longName = courseName;
				availableCourses[k].shortName = classCourseArray[i].courseName[j];
				++k;
			}
		}
	}

	return availableCourses;
}

bool checkStudentCourseAttendanceCheckIn(string courseName, int iD)
{
	studentCheckInType* student = nullptr;
	int size;
	ifstream fin;
	string dir = "pdqvinh19data/2019-2020-HK2-" + courseName + "-Student+Time.txt";

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		student = loadStudentCheckInCourseArray(fin, size);
		fin.close();
	}

	for (int i = 0; i < size; ++i)
		if (student[i].student.iD == iD)
			return true;
	return false;
}

void chooseCourseAndCheckIn(int iD)
{
	classAndCourse* classCourseArray;
	int classCourseSize;
	int size;

	classCourseArray = initializeClassCourseArray(classCourseSize);
	courseNameLongAndShort* courseName;
	courseName = availableCoursesOfStudentID(classCourseArray, classCourseSize, iD, size);

	cout << "Please choose the course you would like to check in: " << endl;
	for (int i = 0; i < size; ++i)
		cout << i + 1 << ". " << courseName[i].shortName << endl;

	int choice;
	cin >> choice;

	cout << "Enter 1 to check in : ";
	int one;
	cin >> one;

	if (one == 1)
		checkInCourseName(courseName[choice - 1].longName, iD, currentTime());
}

string displayCheckInResult(checkInType checkIn)
{
	string display;
	if (checkIn.checkIn == 1)
		display = to_string(checkIn.time.startTime.tm_mday) + "/" + to_string(checkIn.time.startTime.tm_mon + 1) + "/" + to_string(checkIn.time.startTime.tm_year + 1900) + " Checked";
	else if (checkIn.checkIn == 0)
		display = to_string(checkIn.time.startTime.tm_mday) + "/" + to_string(checkIn.time.startTime.tm_mon + 1) + "/" + to_string(checkIn.time.startTime.tm_year + 1900) + " Unchecked";
	else
		display = "";
	return display;
}

void displayCheckInResultList(checkInType checkIn[], int size)
{
	for (int i = 0; i < size; ++i)
		if (displayCheckInResult(checkIn[i]) != "")
			cout << displayCheckInResult(checkIn[i]) << endl;
}

studentCheckInType* loadStudentCheckInCourseArrayFromName(string courseName, int& size)
{
	ifstream fin;
	string dir = "pdqvinh19data/2019-2020-HK2-" + courseName + "-Student+Time.txt";
	studentCheckInType* student = nullptr;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		student = loadStudentCheckInCourseArray(fin, size);
		fin.close();
	}

	return student;
}

void chooseCourseAndDisplayCheckInResult(int iD)
{
	classAndCourse* classCourseArray;
	int classCourseSize;
	int size;

	classCourseArray = initializeClassCourseArray(classCourseSize);
	courseNameLongAndShort* courseName;
	courseName = availableCoursesOfStudentID(classCourseArray, classCourseSize, iD, size);

	cout << "Please choose the course you would like to view check-in result: " << endl;
	for (int i = 0; i < size; ++i)
		cout << i + 1 << ". " << courseName[i].shortName << endl;

	int choice;
	cin >> choice;

	studentCheckInType* student;
	int n;
	student = loadStudentCheckInCourseArrayFromName(courseName[choice - 1].longName, n);
	int k = findIDStudentCheckInCourseArray(student, n, iD);

	cout << "Check-in result of course " + courseName[choice - 1].shortName + ": " << endl;
	displayCheckInResultList(student[k].checkIn, 10);
}

void displaySchedule(scheduleType schedule)
{
	cout << schedule.courseNameShort << endl;
	cout << schedule.courseNameFull << endl;
	cout << schedule.className << endl;
	cout << schedule.lecturerFull << endl;
	cout << schedule.lecturerDegree << endl;
	cout << schedule.startTime.tm_mday << "/" << schedule.startTime.tm_mon + 1 << "/" << schedule.startTime.tm_year + 1900 << endl;
	cout << schedule.endTime.tm_mday << "/" << schedule.endTime.tm_mon + 1 << "/" << schedule.endTime.tm_year + 1900 << endl;
	cout << schedule.startTime.tm_wday + 1 << endl;
	cout << schedule.startTime.tm_hour << ":" << schedule.startTime.tm_min << endl;
	cout << schedule.endTime.tm_hour << ":" << schedule.endTime.tm_min << endl;
	cout << schedule.room << endl;
	cout << endl;
}

scheduleType loadSchedule(ifstream& fin)
{
	scheduleType schedule;
	string tmp;
	int n;
	
	fin.ignore();
	getline(fin, schedule.courseNameShort, '\n');
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

scheduleType* loadScheduleArray(ifstream& fin, int& size)
{
	size = loadN(fin);
	scheduleType* scheduleArray;
	scheduleArray = new scheduleType[size];

	for (int i = 0; i < size; ++i)
		scheduleArray[i] = loadSchedule(fin);

	return scheduleArray;
}

scheduleType* loadScheduleArrayFromClass(string className, int& size)
{
	ifstream fin;
	string dir;
	dir = "pdqvinh19data/2019-2020-HK2-Schedule-" + className + "+Time.txt";
	scheduleType* scheduleArray = nullptr;

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		scheduleArray = loadScheduleArray(fin, size);
		fin.close();
	}

	return scheduleArray;
}

int findCourseScheduleArray(scheduleType* scheduleArray, int size, string courseName)
{
	for (int i = 0; i < size; ++i)
		if (scheduleArray[i].courseNameShort == courseName)
			return i;
	return -1;
}

string getClassName(string courseNameLong)
{
	stringstream s(courseNameLong);
	string className;

	getline(s, className, '-');

	return className;
}

void viewSchedule(int iD)
{
	classAndCourse* classCourseArray;
	int classCourseSize;
	int size;

	classCourseArray = initializeClassCourseArray(classCourseSize);
	courseNameLongAndShort* courseName;
	courseName = availableCoursesOfStudentID(classCourseArray, classCourseSize, iD, size);

	scheduleType* scheduleArray;
	int scheduleSize;
	int j;

	cout << "Your schedule: " << endl;
	cout << endl;

	for (int i = 0; i < size; ++i)
	{
		scheduleArray = loadScheduleArrayFromClass(getClassName(courseName[i].longName), scheduleSize);
		j = findCourseScheduleArray(scheduleArray, scheduleSize, courseName[i].shortName);
		displaySchedule(scheduleArray[j]);
	}
}

void displayScoreStudent(studentCourseFullType student)
{
	cout << "Midterm: " << student.point.midterm << endl;
	cout << "Final:   " << student.point.final << endl;
	cout << "Bonus:   " << student.point.bonus << endl;
	cout << "Total:   " << student.point.total << endl;
}

studentCourseFullType loadStudentCourseFull(ifstream& fin)
{
	string tmp;
	studentCourseFullType student;
	
	fin.ignore();
	fin >> student.iD;
	fin.ignore();
	fin >> student.password;
	fin.ignore();
	getline(fin, student.fullName, '\n');
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
		student.checkIn[i].time = loadDuration(fin);
		getline(fin, tmp, '\n');
		student.checkIn[i].checkIn = stoi(tmp);
	}
	fin >> student.droppedStatus;
	fin.ignore();

	return student;
}

studentCourseFullType* loadStudentCourseFullArray(ifstream& fin, int& size)
{
	studentCourseFullType* studentArray;
	size = loadN(fin);
	studentArray = new studentCourseFullType[size];

	for (int i = 0; i < size; ++i)
		studentArray[i] = loadStudentCourseFull(fin);

	return studentArray;
}

studentCourseFullType* loadStudentCourseFullArrayFromName(string courseNameLong, int& size)
{
	ifstream fin;
	studentCourseFullType* studentArray = nullptr;
	string dir = "pdqvinh19data/2019-2020-HK2-" + courseNameLong + "-Student+Full.txt";

	fin.open(dir);
	if (!fin.is_open())
		cout << "Cannot open file." << endl;
	else
	{
		studentArray = loadStudentCourseFullArray(fin, size);
		fin.close();
	}

	return studentArray;
}

int findIDStudentCourseFullArray(studentCourseFullType* studentArray, int size, int iD)
{
	for (int i = 0; i < size; ++i)
		if (studentArray[i].iD == iD)
			return i;
	return -1;
}

void viewScore(int iD)
{
	classAndCourse* classCourseArray;
	int classCourseSize;
	int size;

	classCourseArray = initializeClassCourseArray(classCourseSize);
	courseNameLongAndShort* courseName;
	courseName = availableCoursesOfStudentID(classCourseArray, classCourseSize, iD, size);

	cout << "Please choose the course you would like to view your scores: " << endl;
	for (int i = 0; i < size; ++i)
		cout << i + 1 << ". " << courseName[i].shortName << endl;

	int choice;
	cin >> choice;

	studentCourseFullType* student;
	int n;

	student = loadStudentCourseFullArrayFromName(courseName[choice - 1].longName, n);
	int k = findIDStudentCourseFullArray(student, n, iD);

	cout << "Your scores of course " + courseName[choice - 1].shortName + ": " << endl;
	displayScoreStudent(student[k]);
}

void displayListCoursesSemester()
{
	classAndCourse* classCourseArray;
	int classCourseSize;

	classCourseArray = initializeClassCourseArray(classCourseSize);

	cout << "List of courses in the current semester: " << endl;
	cout << endl;

	for (int i = 0; i < classCourseSize; ++i)
	{
		cout << "Courses of class " << classCourseArray[i].className << ": " << endl;
		for (int j = 0; j < classCourseArray[i].courseQuantity; ++j)
			cout << classCourseArray[i].courseName[j] << endl;
		cout << endl;
	}
}