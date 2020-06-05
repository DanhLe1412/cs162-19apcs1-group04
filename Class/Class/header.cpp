#include "header.h"
// [13]
void create_years_semesters(Semester* pHead)
{
    system("cls");
    cout << ">>> Create Academic years and Semester <<<" << endl;
    string y, s, years, semester;
    int n;
    string str;
    cout << "Years: ";
    cin >> y;
    cout << "Semester: ";
    cin >> s;
    ifstream fin;
    Semester* cur = nullptr;
    fin.open("data/Semester.txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Semester;
                fin >> pHead->years;
                fin >> pHead->semester;
                pHead->pNext = NULL;
                cur = pHead;
            }
            else {
                cur->pNext = new Semester;
                cur = cur->pNext;
                fin >> cur->years;
                fin >> cur->semester;
                cur->pNext = NULL;
            }
            if (cur->years == y && cur->semester == s) {
                cout << "Semester exists! Cannot add new Semester!" << endl;
                fin.close();
                system("pause");
                return;
            }
        }
        fin.close();
    }
    cur->pNext = new Semester;
    cur = cur->pNext;
    cur->years = y;
    cur->semester = s;
    cur->pNext = NULL;
    ofstream fout;
    fout.open("data/Semester.txt", ios::out);
    fout << ++n << endl;
    cur = pHead;
    while (cur) {
        if (cur->pNext) {
            fout << cur->years << endl;
            fout << cur->semester << endl << endl;
        }
        else {
            fout << cur->years << endl;
            fout << cur->semester;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "New semester is added successfully!" << endl;
    system("pause");
}

void delete_years_semesters(Semester* pHead)
{
    system("cls");
    int n;
    cout << ">>> Delete Academic Years and Semester <<<" << endl;
    Semester* cur = nullptr;
    string y, s;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    fin >> n;
    for (int i = 0; i < n; i++) {
        if (!pHead) {
            pHead = new Semester;
            fin >> pHead->years;
            fin >> pHead->semester;
            pHead->pNext = NULL;
            cur = pHead;
        }
        else {
            cur->pNext = new Semester;
            cur = cur->pNext;
            fin >> cur->years;
            fin >> cur->semester;
            cur->pNext = NULL;
        }
        cout << "Years: " << cur->years << endl;
        cout << "Semester: " << cur->semester << endl;
        cout << endl;
    }
    fin.close();
    cout << "Input Academic years: ";
    cin >> y;
    cout << "Input semester: ";
    cin >> s;
    Semester* tmp = nullptr;
    if (pHead && pHead->years == y && pHead->semester == s) {
        tmp = pHead;
        pHead = pHead->pNext;
    }
    else {
        cur = pHead;
        while(cur->pNext) {
            if (cur->pNext->years == y && cur->pNext->semester == s) {
                tmp = cur->pNext;
                cur->pNext = cur->pNext->pNext;
                break;
            }
            cur = cur->pNext;
        }
    }
    if (!tmp) {
        cout << "Semester does not exist!" << endl;
        system("pause");
        return;
    }
    delete tmp;
    cur = pHead;
    ofstream fout;
    fout.open("data/Semester.txt", ios::out);
    fout << --n << endl;
    while (cur) {
        if (cur->pNext) {
            fout << cur->years << endl;
            fout << cur->semester << endl << endl;
        }
        else {
            fout << cur->years << endl;
            fout << cur->semester;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "Delete course successfully!" << endl;
    system("pause");
}

void update_years_semesters(Semester* pHead)
{
    system("cls");
    int n;
    cout << ">>> Update Academic Years and Semester <<<" << endl;
    Semester* cur = nullptr;
    string y, s;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    fin >> n;
    for (int i = 0; i < n; i++) {
        if (!pHead) {
            pHead = new Semester;
            fin >> pHead->years;
            fin >> pHead->semester;
            pHead->pNext = NULL;
            cur = pHead;
        }
        else {
            cur->pNext = new Semester;
            cur = cur->pNext;
            fin >> cur->years;
            fin >> cur->semester;
            cur->pNext = NULL;
        }
        cout << "Years: " << cur->years << endl;
        cout << "Semester: " << cur->semester << endl;
        cout << endl;
    }
    fin.close();
    cout << "Input Academic years: ";
    cin >> y;
    cout << "Input semester: ";
    cin >> s;
    Semester* tmp = nullptr;
    if (pHead && pHead->years == y && pHead->semester == s) {
        tmp = pHead;
        pHead = pHead->pNext;
    }
    else {
        cur = pHead;
        while(cur->pNext) {
            if (cur->pNext->years == y && cur->pNext->semester == s) {
                tmp = cur->pNext;
                break;
            }
            cur = cur->pNext;
        }
    }
    if (!tmp) {
        cout << "Semester does not exist!" << endl;
        system("pause");
        return;
    }
    cout << endl << "Found your semester!" << endl;
    cout << "Input new Academic years: ";
    cin >> y;
    cout << "Input new semester: ";
    cin >> s;
    tmp->years = y;
    tmp->semester = s;
    cur = pHead;
    ofstream fout;
    fout.open("data/Semester.txt", ios::out);
    fout << n << endl;
    while (cur) {
        if (cur->pNext) {
            fout << cur->years << endl;
            fout << cur->semester << endl << endl;
        }
        else {
            fout << cur->years << endl;
            fout << cur->semester;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "Update course successfully!" << endl;
    system("pause");
}

void view_years_semesters()
{
    system("cls");
    cout << ">>> View all Academic Years and Semester <<<" << endl;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    int n;
    string s, y;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> y;
        fin >> s;
        cout << "Years: " << y << endl;
        cout << "Semester: " << s << endl;
    }
    system("pause");
    return;
}

void CRUD_years_semesters()
{
    CASE_13: {
        system("cls");
        Semester* pHead = NULL;
        cout << "[1]: Create." << endl;
        cout << "[2]: Update." << endl;
        cout << "[3]: Delete." << endl;
        cout << "[4]: View." << endl;
        cout << "[0]: Back." << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                create_years_semesters(pHead);
                goto CASE_13;
            }
            case 2:
            {
                update_years_semesters(pHead);
                goto CASE_13;
            }
            case 3:
            {
                delete_years_semesters(pHead);
                goto CASE_13;
            }
            case 4:
            {
                view_years_semesters();
                goto CASE_13;
            }
            case 0:
            {
                return;
            }
            default:
            {
                cout << "Wrong! Choose again!" << endl;
                system("pause");
                goto CASE_13;
            }
        }
    }
}

// [14]
void makeFileCourse(string years, string semester, string Class, Course* course) {
    ifstream fin;
    ofstream fout;
    string student;
    int n = 0;
    fin.open("data/class_" + Class + ".txt");
	if (!fin.is_open()) return;
	while (!fin.eof()) {
		fin >> student;
		fin.ignore(1000, '\n');
		getline(fin, student, '\n');
		fin >> student;
		fin >> student;
		n++;
	}
	fin.close();
	fin.open("data/class_" + Class + ".txt");
	fout << n << endl;
    if (!fin.is_open()) return;
    fout.open("data/" + years + "-" + semester + "-" + Class + "-" + course->CourseId + "-Student.txt");
	tm t;
	time_t sec = time(0);
	localtime_s(&t, &sec);
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fin >> student;
        fout << student << endl;
		fin.ignore(1000, '\n');
		getline(fin, student, '\n');
		fout << student << endl;
        fin >> student;
        fout << student << endl;
        fin >> student;
        fout << student << endl;
		fout << Class << endl;
        fout << -1 << endl << -1 << endl << -1 << endl << -1 << endl;
        sscanf_s(course->StartDate.c_str(), "%4d %2d %2d", &t.tm_year, &t.tm_mon, &t.tm_mday);
        fout << t.tm_year << " " << setw(2) << setfill('0') << t.tm_mon << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        t.tm_year -= 1900;
        t.tm_mon -= 1;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        if (i + 1 == n) {
            fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1;
        }
        else {
            fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << course->StartHour << " " << course->StartMinutes << " " << course->EndHour << " " << course->EndMinutes << " " << -1 << endl << endl;
        }
    }
    fin.close();
    fout.close();
}
string convertDate(string date) {
    stringstream ss(date);
    string token[3];
    int i = 0;
    while(getline(ss, token[i], '/')) {
        i++;
    }
    if (token[0].size() == 1) token[0] = '0' + token[0];
    if (token[1].size() == 1) token[1] = '0' + token[1];
    token[2] = "20" + token[2];
    return token[2] + " " + token[0] + " " + token[1];
}
void importCourses() {
    cout << ">>> Import Course to Semester <<<" << endl;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    int n;
    string y, s, years, semester, c, Class, file;
    bool check = false;
    cout << "Input Academic Years: ";
    cin >> y;
    cout << "Input Semester: ";
    cin >> s;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> years;
        fin >> semester;
        if (s == semester && years == y) {
            check = true;
            break;
        }
    }
    fin.close();
    if (!check) {
        cout << "Semester does not exist!" << endl;
        system("pause");
        return;
    }
    cout << "Input class: ";
    cin >> c;
    fin.open("data/Class.txt");
    if (!fin.is_open()) return;
    check = false;
	while (!fin.eof()) {
		fin >> Class;
		if (Class == c) {
			check = true;
			break;
		}
	}
    fin.close();
    if (!check) {
        cout << "Class does not exist!" << endl;
        system("pause");
        return;
    }
    cout << "Input file: ";
    cin >> file;
    fin.open("data/" + file);
    string line, header;
    if(!fin.is_open()) return;
    string id;
    getline(fin, header, '\n');
    Course* pHead = nullptr, *cur = nullptr;
    while(fin.good()) {
        getline(fin, id, ',');
        if (!pHead) {
            pHead = new Course;
            getline(fin, pHead->CourseId, ',');
            getline(fin, pHead->CourseName, ',');
            getline(fin, pHead->Class, ',');
            getline(fin, pHead->LecturerUsername, ',');
            getline(fin, pHead->LecturerName, ',');
            getline(fin, pHead->LecturerDegree, ',');
            getline(fin, pHead->LecturerGender, ',');
            getline(fin, pHead->StartDate, ',');
            pHead->StartDate = convertDate(pHead->StartDate);
            getline(fin, pHead->EndDate, ',');
            pHead->EndDate = convertDate(pHead->EndDate);
            getline(fin, pHead->DayOfWeek, ',');
            getline(fin, pHead->StartHour, ',');
            getline(fin, pHead->StartMinutes, ',');
            getline(fin, pHead->EndHour, ',');
            getline(fin, pHead->EndMinutes, ',');
            getline(fin, pHead->room, '\n');
            pHead->pNext = NULL;
            cur = pHead;
        }
        else {
            cur->pNext = new Course;
            cur = cur->pNext;
            getline(fin, cur->CourseId, ',');
            getline(fin, cur->CourseName, ',');
            getline(fin, cur->Class, ',');
            getline(fin, cur->LecturerUsername, ',');
            getline(fin, cur->LecturerName, ',');
            getline(fin, cur->LecturerDegree, ',');
            getline(fin, cur->LecturerGender, ',');
            getline(fin, cur->StartDate, ',');
            cur->StartDate = convertDate(cur->StartDate);
            getline(fin, cur->EndDate, ',');
            cur->EndDate = convertDate(cur->EndDate);
            getline(fin, cur->DayOfWeek, ',');
            getline(fin, cur->StartHour, ',');
            getline(fin, cur->StartMinutes, ',');
            getline(fin, cur->EndHour, ',');
            getline(fin, cur->EndMinutes, ',');
            getline(fin, cur->room, '\n');
            cur->pNext = nullptr;
        }
    }
    fin.close();
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-Schedule-" + Class + ".txt");
    cur = pHead;
    fout << id << endl;
    while(cur) {
        fout << cur->CourseId << endl;
        fout << cur->CourseName << endl;
        fout << cur->Class << endl;
        fout << cur->LecturerUsername << endl;
        fout << cur->LecturerName << endl;
        fout << cur->LecturerDegree << endl;
        fout << (cur->LecturerGender == "Male" ? male : female) << endl;
        fout << cur->StartDate << endl;
        fout << cur->EndDate << endl;
        if (cur->DayOfWeek == "MON") fout << MON << endl;
        else if (cur->DayOfWeek == "TUE") fout << TUE << endl;
        else if (cur->DayOfWeek == "WED") fout << WED << endl;
        else if (cur->DayOfWeek == "THU") fout << THU << endl;
        else if (cur->DayOfWeek == "FRI") fout << FRI << endl;
        else fout << SAT << endl;
        fout << cur->StartHour << " " << cur->StartMinutes << endl;
        fout << cur->EndHour << " " << cur->EndMinutes << endl;
        if (cur->pNext) {
            fout << cur->room << endl << endl;
        }
        else {
            fout << cur->room;
        }
        makeFileCourse(y, s, cur->Class, cur);
        cur = cur->pNext;
    }
    fout.close();
    cout << "Import courses successfully!" << endl;
    system("pause");
}

// [15]
void addCourseManually(){
    cout << ">>> Manually add a new course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr, *tmp = new Course;
    cout << "Input Course ID: ";
    cin >> tmp->CourseId;
    cout << "Input Course Name: ";
    cin.ignore(1000, '\n');
    getline(cin, tmp->CourseName, '\n');
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> tmp->Class;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == tmp->Class) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    CHECK_LECTURER: {
        cout << "Input Lecturer Username: ";
        cin >> tmp->LecturerUsername;
        fin.open("data/Lecturer.txt");
        fin >> n;
        string lecturer;
        check = false;
        for (int i = 0; i < n; i++) {
            fin >> lecturer;
            if (lecturer != tmp->LecturerUsername) {
                // Skip lecturer's info
                fin >> lecturer;
                fin.ignore(1000, '\n');
                getline(fin, lecturer, '\n');
                fin >> lecturer;
                fin >> lecturer;
            }
            else {
                check = true;
                fin >> lecturer;
                fin.ignore(1000, '\n');
                getline(fin, tmp->LecturerName, '\n');
                fin >> tmp->LecturerDegree;
                fin >> tmp->LecturerGender;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Lecturer does not exist!" << endl;
            system("pause");
            goto CHECK_LECTURER;
        }
    }
    cout << "Input Start Date: ";
    cin.ignore(1000, '\n');
    getline(cin, tmp->StartDate);
    cout << "Input End Date: ";
    getline(cin, tmp->EndDate);
    cout << "Input Day of Week (2-7): ";
    cin >> tmp->DayOfWeek;
    cout << "Input Start Time: ";
    cin >> tmp->StartHour >> tmp->StartMinutes;
    cout << "Input End Time: ";
    cin >> tmp->EndHour >> tmp->EndMinutes;
    cout << "Input room: ";
    cin >> tmp->room;
    tmp->pNext = nullptr;
    fin.open("data/" + y + "-" + s + "-Schedule-" + tmp->Class + ".txt");
	n = 0;
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
	if (pHead) {
		cur->pNext = new Course;
		cur->pNext = tmp;
	}
	else {
		pHead = new Course;
		pHead = tmp;
		pHead->pNext = nullptr;
	}
    fin.close();
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-Schedule-" + tmp->Class + ".txt");
    cur = pHead;
    fout << ++n << endl;
    while(cur) {
        fout << cur->CourseId << endl;
        fout << cur->CourseName << endl;
        fout << cur->Class << endl;
        fout << cur->LecturerUsername << endl;
        fout << cur->LecturerName << endl;
        fout << cur->LecturerDegree << endl;
        fout << cur->LecturerGender << endl;
        fout << cur->StartDate << endl;
        fout << cur->EndDate << endl;
        fout << cur->DayOfWeek << endl;
        fout << cur->StartHour << " " << cur->StartMinutes << endl;
        fout << cur->EndHour << " " << cur->EndMinutes << endl;
        if (cur->pNext) {
            fout << cur->room << endl << endl;
        }
        else {
            fout << cur->room;
        }
        makeFileCourse(y, s, cur->Class, cur);
        cur = cur->pNext;
    }
    fout.close();
    cout << "Add new course successfully!" << endl;
    system("pause");
}

// [16]
void editExistingCourse()
{
    cout << ">>> Editing an existing course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr, *tmp = new Course;
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
	else {
		cout << "Class does not have Schedule" << endl;
		system("pause");
		return;
	}
    CHOOSE_COURSE: {
        system("cls");
        cout << ">>> Editing an existing course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cur = pHead;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
            cur = cur->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    int choice;
    cout << "Choose course to edit or 0 to go back: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! choose again!" << endl;
        system("pause");
        goto CHOOSE_COURSE;
    }
    cur = pHead;
    for (int i = 1; i < choice; i++) {
        cur = cur->pNext;
    }
    cout << "Course ID: " << cur->CourseId << endl;
    cout << "Course name: " << cur->CourseName << endl;
    cout << "Class: " << cur->Class << endl;
    cout << "Lecturer username: " << cur->LecturerUsername << endl;
    cout << "Lecturer fullname: " << cur->LecturerName << endl;
    cout << "Lecturer degree: " << cur->LecturerDegree << endl;
    cout << "Lecturer gender: " << (stoi(cur->LecturerGender) == male ? "male" : "female") << endl;
    cout << "Start date: " << cur->StartDate << endl;
    cout << "End date: " << cur->EndDate << endl;
    cout << "Day of week: " << cur->DayOfWeek << endl;
    cout << "Start time: " << cur->StartHour << ":" << cur->StartMinutes << endl;
    cout << "End time: " << cur->EndHour << ":" << cur->EndMinutes << endl;
    cout << "Room: " << cur->room << endl;
    cout << "Edit this course? ";
    cin >> choice;
    if (choice == 0) {
        goto CHOOSE_COURSE;
    }
    cout << "Input new Course ID: ";
    cin >> tmp->CourseId;
    cout << "Input new Course Name: ";
    cin.ignore(1000, '\n');
    getline(cin, tmp->CourseName, '\n');
    CHECK_LECTURER: {
        cout << "Input new Lecturer Username: ";
        cin >> tmp->LecturerUsername;
        fin.open("data/Lecturer.txt");
		int nLecturer;
        fin >> nLecturer;
        string lecturer;
        check = false;
        for (int i = 0; i < nLecturer; i++) {
            if (tmp->LecturerUsername.size() == 0) {
                check = true;
                break;
            }
            fin >> lecturer;
            if (lecturer != tmp->LecturerUsername) {
                // Skip lecturer's info
                fin >> lecturer;
                fin.ignore(1000, '\n');
                getline(fin, lecturer, '\n');
                fin >> lecturer;
                fin >> lecturer;
            }
            else {
                check = true;
                fin >> lecturer;
                fin.ignore(1000, '\n');
                getline(fin, tmp->LecturerName, '\n');
                fin >> tmp->LecturerDegree;
                fin >> tmp->LecturerGender;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Lecturer does not exist!" << endl;
            system("pause");
            goto CHECK_LECTURER;
        }
    }
    cout << "Input new Start Date: ";
    cin.ignore(1000, '\n');
    getline(cin, tmp->StartDate);
    cout << "Input new End Date: ";
    getline(cin, tmp->EndDate);
    cout << "Input new Day of Week (2-7): ";
    cin >> tmp->DayOfWeek;
    cout << "Input new room: ";
    cin >> tmp->room;
    tmp->pNext = nullptr;
    cur->CourseId = tmp->CourseId.size() > 0 ? tmp->CourseId : cur->CourseId;
    cur->CourseName = tmp->CourseName.size() > 0 ? tmp->CourseName : cur->CourseName;
    if (tmp->LecturerUsername.size() > 0) {
        cur->LecturerUsername = tmp->LecturerUsername;
        cur->LecturerName = tmp->LecturerName;
        cur->LecturerDegree = tmp->LecturerDegree;
        cur->LecturerGender = tmp->LecturerGender;
    }
    cur->StartDate = tmp->StartDate.size() > 0 ? tmp->StartDate : cur->StartDate;
    cur->EndDate = tmp ->EndDate.size() > 0 ? tmp->EndDate : cur->EndDate;
    cur->DayOfWeek = tmp->DayOfWeek.size() > 0 ? tmp->DayOfWeek : cur->DayOfWeek;
    cur->room = tmp->room.size() > 0 ? tmp->room : cur->room;
    delete tmp;
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    cur = pHead;
    fout << n << endl;
    while(cur) {
        fout << cur->CourseId << endl;
        fout << cur->CourseName << endl;
        fout << cur->Class << endl;
        fout << cur->LecturerUsername << endl;
        fout << cur->LecturerName << endl;
        fout << cur->LecturerDegree << endl;
        fout << cur->LecturerGender << endl;
        fout << cur->StartDate << endl;
        fout << cur->EndDate << endl;
        fout << cur->DayOfWeek << endl;
        fout << cur->StartHour << " " << cur->StartMinutes << endl;
        fout << cur->EndHour << " " << cur->EndMinutes << endl;
        if (cur->pNext) {
            fout << cur->room << endl << endl;
        }
        else {
            fout << cur->room;
        }
        makeFileCourse(y, s, cur->Class, cur);
        cur = cur->pNext;
    }
    fout.close();
    cout << "Edit course successfully!" << endl;
    system("pause");
}

// [17]
void removeCourse()
{
    cout << ">>> Remove an existing course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr, *tmp = new Course;
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
    CHOOSE_COURSE: {
        system("cls");
        cout << ">>> Remove an existing course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cur = pHead;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
            cur = cur->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    int choice;
    cout << "Choose course to remove or 0 to go back: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! choose again!" << endl;
        system("pause");
        goto CHOOSE_COURSE;
    }
    cur = pHead;
    if (choice == 1) {
        tmp = pHead;
        pHead = pHead->pNext;
    }
    else {
        for(int i = 2; i < choice; i++) {
            cur = cur->pNext;
        }
        tmp = cur->pNext;
        cur->pNext = cur->pNext->pNext;
    }
    delete tmp;
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    cur = pHead;
    fout << --n << endl;
    while(cur) {
        fout << cur->CourseId << endl;
        fout << cur->CourseName << endl;
        fout << cur->Class << endl;
        fout << cur->LecturerUsername << endl;
        fout << cur->LecturerName << endl;
        fout << cur->LecturerDegree << endl;
        fout << cur->LecturerGender << endl;
        fout << cur->StartDate << endl;
        fout << cur->EndDate << endl;
        fout << cur->DayOfWeek << endl;
        fout << cur->StartHour << " " << cur->StartMinutes << endl;
        fout << cur->EndHour << " " << cur->EndMinutes << endl;
        if (cur->pNext) {
            fout << cur->room << endl << endl;
        }
        else {
            fout << cur->room;
        }
        makeFileCourse(y, s, cur->Class, cur);
        cur = cur->pNext;
    }
    fout.close();
    cout << "Remove course successfully!" << endl;
    system("pause");
}

void removeStudentFromScore()
{
    cout << ">>> Remove a Student from Course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr;
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
	else {
		cout << "Class does not have Schedule" << endl;
		system("pause");
		return;
	}
    CHOOSE_COURSE: {
        system("cls");
        cout << ">>> Remove a Student from Course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cur = pHead;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
            cur = cur->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    int choice;
    cout << "Choose Course or [0] to go back to menu: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! choose again!" << endl;
        system("pause");
        goto CHOOSE_COURSE;
    }
    cur = pHead;
    for(int i = 1; i < choice; i++) {
        cur = cur->pNext;
    }
    fin.open("data/" + y + "-" + s + "-" + c + "-" + cur->CourseId + "-Student.txt");
    fin >> n;
    StudentInCourse* pStudent = nullptr, *curStudent = nullptr;
    for (int i = 0; i < n; i++) {
        if (!pStudent) {
            pStudent = new StudentInCourse;
            fin >> pStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, pStudent->fullname, '\n');
			fin >> pStudent->status;
            fin >> pStudent->dob;
            fin >> pStudent->Class;
            fin >> pStudent->midterm >> pStudent->Final >> pStudent->bonus >> pStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, pStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            pStudent->pNext = nullptr;
            curStudent = pStudent;
        }
        else {
            curStudent->pNext = new StudentInCourse;
            curStudent = curStudent->pNext;
            fin >> curStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, curStudent->fullname, '\n');
			fin >> curStudent->status;
			fin >> curStudent->dob;
            fin >> curStudent->Class;
            fin >> curStudent->midterm >> curStudent->Final >> curStudent->bonus >> curStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, curStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            curStudent->pNext = nullptr;
        }
    }
    fin.close();
    CHOOSE_STUDENT: {
        system("cls");
        cout << ">>> Remove a Student from Course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cout << "Course: " + cur->CourseId << ": " + cur->CourseName << endl;
        curStudent = pStudent;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << curStudent->username << endl;
            curStudent = curStudent->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    cout << "Choose Student or [0] to go back to menu: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! Choose again!" << endl;
        system("pause");
        goto CHOOSE_STUDENT;
    }
    curStudent = pStudent;
    StudentInCourse* tmpStudent;
    if (choice == 1) {
        tmpStudent = pStudent;
        pStudent = pStudent->pNext;
    }
    else {
        for (int i = 2; i < choice; i++) {
            curStudent = curStudent->pNext;
        }
        tmpStudent = curStudent->pNext;
        curStudent->pNext = curStudent->pNext->pNext;
    }
    cout << "Student ID: " << tmpStudent->username << endl;
    cout << "Full name: " << tmpStudent->fullname << endl;
    cout << "Date of birth: " << tmpStudent->dob << endl;
    cout << "Class: " << tmpStudent->Class << endl;
    cout << "Status: " << tmpStudent->status << endl;
    delete tmpStudent;
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-" + c + "-" + cur->CourseId + "-Student.txt");
    curStudent = pStudent;
    fout << --n << endl;
    for (int i = 0; i < n; i++) {
        fout << curStudent->username << endl;
        fout << curStudent->fullname << endl;
		fout << curStudent->status << endl;
        fout << curStudent->dob << endl;
        fout << curStudent->Class << endl;
        fout << curStudent->midterm << endl;
        fout << curStudent->Final << endl;
        fout << curStudent->bonus << endl;
        fout << curStudent->total << endl;
        for(int j = 0; j < 9; j++) {
            fout << curStudent->attendance[j] << endl;
        }
        if (curStudent->pNext) {
            fout << curStudent->attendance[9] << endl << endl;
        }
        else {
            fout << curStudent->attendance[9];
        }
        curStudent = curStudent->pNext;
    }
    cout << "Remove Student successfully!" << endl;
    system("pause");
}

void addStudentToScore()
{
    cout << ">>> Add a Student to Course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr;
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
	else {
		cout << "Class does not have Schedule" << endl;
		system("pause");
		return;
	}
    CHOOSE_COURSE: {
        system("cls");
        cout << ">>> Add a Student to Course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cur = pHead;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
            cur = cur->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    int choice;
    cout << "Choose Course or [0] to go back to menu: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! choose again!" << endl;
        system("pause");
        goto CHOOSE_COURSE;
    }
    cur = pHead;
    for(int i = 1; i < choice; i++) {
        cur = cur->pNext;
    }
    fin.open("data/" + y + "-" + s + "-" + c + "-" + cur->CourseId + "-Student.txt");
    fin >> n;
    StudentInCourse* pStudent = nullptr, *curStudent = nullptr;
    for (int i = 0; i < n; i++) {
        if (!pStudent) {
            pStudent = new StudentInCourse;
            fin >> pStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, pStudent->fullname, '\n');
			fin >> pStudent->status;
            fin >> pStudent->dob;
            fin >> pStudent->Class;
            fin >> pStudent->midterm >> pStudent->Final >> pStudent->bonus >> pStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, pStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            pStudent->pNext = nullptr;
            curStudent = pStudent;
        }
        else {
            curStudent->pNext = new StudentInCourse;
            curStudent = curStudent->pNext;
            fin >> curStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, curStudent->fullname, '\n');
			fin >> curStudent->status;
            fin >> curStudent->dob;
            fin >> curStudent->Class;
            fin >> curStudent->midterm >> curStudent->Final >> curStudent->bonus >> curStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, curStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            curStudent->pNext = nullptr;
        }
    }
    fin.close();
    string ID, studentID;
    system("cls");
    cout << ">>> Add a Student to Course. <<<" << endl;
    cout << "Academic Years: " + y << endl;
    cout << "Semester: " + s << endl;
    cout << "Class: " + c << endl;
    cout << "Course: " + cur->CourseId << ": " + cur->CourseName << endl;
    cout << "Input Student ID: ";
    cin >> ID;
	string attendance[10];
	tm t;
	time_t sec = time(0);
	localtime_s(&t, &sec);
	sscanf_s(cur->StartDate.c_str(), "%4d %2d %2d", &t.tm_year, &t.tm_mon, &t.tm_mday);
	t.tm_year -= 1900;
	t.tm_mon -= 1;
	string mon, day;
	for (int i = 0; i < 10; i++) {
		mon = to_string(t.tm_mon + 1);
		mon = mon.length() == 1 ? "0" + mon : mon;
		day = to_string(t.tm_mday);
		day = day.length() == 1 ? "0" + day : day;
		attendance[i] = to_string(t.tm_year + 1900) + " " + mon + " " + day + " " + cur->StartHour + " " + cur->StartMinutes + " " + cur->EndHour + " " + cur->EndMinutes + " -1";
		sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
	}
    int nStudent = 0;
    fin.open("data/Student.txt");
	if (!fin.is_open()) return;
	string skip;
	while (!fin.eof()) {
		fin >> skip;
		fin >> skip;
		fin.ignore(1000, '\n');
		getline(fin, skip, '\n');
		getline(fin, skip, '\n');
		fin >> skip;
		fin >> skip;
		nStudent++;
	}
	fin.close();
	fin.open("data/Student.txt");
    for (int i = 0; i < nStudent; i++) {
        fin >> studentID;
        if (studentID == ID) {
            curStudent->pNext = new StudentInCourse;
            curStudent = curStudent->pNext;
            curStudent->username = studentID;
            fin >> skip;
            fin.ignore(1000, '\n');
            getline(fin, curStudent->fullname, '\n');
            getline(fin, curStudent->dob, '\n');
			for (int j = 0; j < curStudent->dob.length(); j++) {
				if (curStudent->dob[j] == ' ') curStudent->dob[j] = '-';
			}
            fin >> curStudent->Class;
            fin >> curStudent->status;
            curStudent->midterm = curStudent->Final = curStudent->bonus = curStudent->total = "-1";
            for (int j = 0; j < 10; j++) {
                curStudent->attendance[j] = attendance[j];
            }
            curStudent->pNext = nullptr;
            break;
        }
        else {
            // Skip info
            fin >> studentID;
            fin.ignore(1000, '\n');
            getline(fin, studentID, '\n');
            getline(fin, studentID, '\n');
            fin >> studentID;
            fin >> studentID;
        }
    }
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-" + c + "-" + cur->CourseId + "-Student.txt");
    curStudent = pStudent;
    fout << ++n << endl;
    for (int i = 0; i < n; i++) {
        fout << curStudent->username << endl;
        fout << curStudent->fullname << endl;
		fout << curStudent->status << endl;
        fout << curStudent->dob << endl;
        fout << curStudent->Class << endl;
        fout << curStudent->midterm << endl;
        fout << curStudent->Final << endl;
        fout << curStudent->bonus << endl;
        fout << curStudent->total << endl;
        for(int j = 0; j < 9; j++) {
            fout << curStudent->attendance[j] << endl;
        }
        if (curStudent->pNext) {
            fout << curStudent->attendance[9] << endl << endl;
        }
        else {
            fout << curStudent->attendance[9];
        }
        curStudent = curStudent->pNext;
    }
    cout << "Add Student successfully!" << endl;
    system("pause");
}

// [20]
void viewCourseInSemester()
{
    cout << ">>> View Course in Semester <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    system("cls");
    Course* pHead = nullptr, *cur = nullptr;
    cout << ">>> View Course in Semester <<<" << endl;
    cout << "Academic Years: " << y << endl;
    cout << "Semester: " << s << endl;
    cout << "Class: " << c << endl;
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
	else {
		cout << "Class does not have Schedule" << endl;
		system("pause");
		return;
	}
    cur = pHead;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
        cur = cur->pNext;
    }
    system("pause");
}

// [21]
void viewStudentsInCourse()
{
    cout << ">>> View list of Students of a Course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr;
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
	else {
		cout << "Class does not have Schedule" << endl;
		system("pause");
		return;
	}
    CHOOSE_COURSE: {
        system("cls");
        cout << ">>> View list of Students of a Course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cur = pHead;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
            cur = cur->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    int choice;
    cout << "Choose Course or [0] to go back to menu: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! choose again!" << endl;
        system("pause");
        goto CHOOSE_COURSE;
    }
    cur = pHead;
    for(int i = 1; i < choice; i++) {
        cur = cur->pNext;
    }
    system("cls");
    cout << ">>> View list of Students of a Course. <<<" << endl;
    cout << "Academic Years: " + y << endl;
    cout << "Semester: " + s << endl;
    cout << "Class: " + c << endl;
    cout << "Course: " + cur->CourseId << endl;
    fin.open("data/" + y + "-" + s + "-" + c + "-" + cur->CourseId + "-Student.txt");
    fin >> n;
    StudentInCourse* pStudent = nullptr, *curStudent = nullptr;
    for (int i = 0; i < n; i++) {
        if (!pStudent) {
            pStudent = new StudentInCourse;
            fin >> pStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, pStudent->fullname, '\n');
			fin >> pStudent->status;
            fin >> pStudent->dob;
            fin >> pStudent->Class;
            fin >> pStudent->midterm >> pStudent->Final >> pStudent->bonus >> pStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, pStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            pStudent->pNext = nullptr;
            curStudent = pStudent;
        }
        else {
            curStudent->pNext = new StudentInCourse;
            curStudent = curStudent->pNext;
            fin >> curStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, curStudent->fullname, '\n');
			fin >> curStudent->status;
            fin >> curStudent->dob;
            fin >> curStudent->Class;
            fin >> curStudent->midterm >> curStudent->Final >> curStudent->bonus >> curStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, curStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            curStudent->pNext = nullptr;
        }
    }
    fin.close();
    curStudent = pStudent;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << curStudent->username << endl;
        cout << "Full name: " << curStudent->fullname << endl;
        cout << "Date of birth: " << curStudent->dob << endl;
        cout << "Class: " << curStudent->Class << endl;
        cout << "Status: " << curStudent->status << endl << endl;
		curStudent = curStudent->pNext;
    }
	system("pause");
}

void viewAttendanceList()
{
    cout << ">>> View Attendance list of a Course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string c, Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur = nullptr;
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> c;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
		while (!fin.eof()) {
			fin >> Class;
			if (Class == c) {
				check = true;
				break;
			}
		}
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    fin.open("data/" + y + "-" + s + "-Schedule-" + c + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
    CHOOSE_COURSE: {
        system("cls");
        cout << ">>> View Attendance list of a Course. <<<" << endl;
        cout << "Academic Years: " + y << endl;
        cout << "Semester: " + s << endl;
        cout << "Class: " + c << endl;
        cur = pHead;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << cur->CourseId << " - " << cur->CourseName << endl;
            cur = cur->pNext;
        }
        cout << "[0]: Back" << endl;
    }
    int choice;
    cout << "Choose Course or [0] to go back to menu: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (1 > choice || choice > n) {
        cout << "Wrong choice! choose again!" << endl;
        system("pause");
        goto CHOOSE_COURSE;
    }
    cur = pHead;
    for(int i = 1; i < choice; i++) {
        cur = cur->pNext;
    }
    system("cls");
    cout << ">>> View Attendance list of a Course. <<<" << endl;
    cout << "Academic Years: " + y << endl;
    cout << "Semester: " + s << endl;
    cout << "Class: " + c << endl;
    cout << "Course: " + cur->CourseId << endl;
    fin.open("data/" + y + "-" + s + "-" + c + "-" + cur->CourseId + "-Student.txt");
    fin >> n;
    StudentInCourse* pStudent = nullptr, *curStudent = nullptr;
    for (int i = 0; i < n; i++) {
        if (!pStudent) {
            pStudent = new StudentInCourse;
            fin >> pStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, pStudent->fullname, '\n');
			      fin >> pStudent->status;
            fin >> pStudent->dob;
            fin >> pStudent->Class;
            fin >> pStudent->midterm >> pStudent->Final >> pStudent->bonus >> pStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, pStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            pStudent->pNext = nullptr;
            curStudent = pStudent;
        }
        else {
            curStudent->pNext = new StudentInCourse;
            curStudent = curStudent->pNext;
            fin >> curStudent->username;
            fin.ignore(1000, '\n');
            getline(fin, curStudent->fullname, '\n');
			      fin >> curStudent->status;
            fin >> curStudent->dob;
            fin >> curStudent->Class;
            fin >> curStudent->midterm >> curStudent->Final >> curStudent->bonus >> curStudent->total;
            fin.ignore(1000, '\n');
            for(int j = 0; j < 10; j++)
            {
                getline(fin, curStudent->attendance[j], '\n');
            }
            fin.ignore(1000, '\n');
            curStudent->pNext = nullptr;
        }
    }
    fin.close();
    curStudent = pStudent;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << curStudent->username << endl;
        cout << "Full name: " << curStudent->fullname << endl;
        cout << "Date of birth: " << curStudent->dob << endl;
        cout << "Class: " << curStudent->Class << endl;
        cout << "Status: " << curStudent->status << endl;
        for (int j = 0; j < 10; j++) {
            cout << curStudent->attendance[j] << endl;
        }
        cout << endl;
		curStudent = curStudent->pNext;
    }
	system("pause");
}

// For [24] to [38]

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
    n = stoi(tmp);
    student.dOB.tm_mday = n;
    getline(fin, tmp, ' ');
    n = stoi(tmp) - 1;
    student.dOB.tm_mon = n;
    getline(fin, tmp, '\n');
    n = stoi(tmp) - 1900;
    student.dOB.tm_year = n;
    student.dOB = { 0, 0, 0, student.dOB.tm_mday, student.dOB.tm_mon, student.dOB.tm_year };
    getline(fin, student.className, '\n');
    fin >> student.gender;

    student.point = { -1, -1, -1, -1 };
    for (int i = 0; i < 10; ++i)
    {
        student.checkIn[i].time.startTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
        student.checkIn[i].time.endTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
        student.checkIn[i].checkIn = -1;
    }

    return student;
}

studentType* readStudent_array(ifstream& fin, int& size)
{
    size = countStudent(fin);
    studentType* array;
    array = new studentType[size];

    for (int i = 0; i < size; ++i)
        array[i] = readStudent_element(fin);

    return array;
}

studentType* readStudents(string dir, int& size)
{
    ifstream fin;
    studentType* array = nullptr;

    fin.open(dir);
    if (!fin.is_open())
        cout << "Cannot open file." << endl;
    else
    {
        array = readStudent_array(fin, size);

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
        for (int i = 0; i < size; ++i)
        {
            fout << students[i].iD << endl;
            fout << students[i].password << endl;
            fout << students[i].fullname << endl;
            fout << setw(2) << setfill('0') << students[i].dOB.tm_mday << " ";
            fout << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << " ";
            fout << students[i].dOB.tm_year + 1900 << endl;
            fout << setw(2) << setfill(' ');
            fout << students[i].className << endl;
            fout << students[i].gender << endl;
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
    int n;

    fin.ignore();
    fin >> student.iD;
    fin.ignore();
    getline(fin, student.fullname, '\n');
    fin >> student.gender;
    fin.ignore();
    getline(fin, tmp, '-');
    n = stoi(tmp);
    student.dOB.tm_mday = n;
    getline(fin, tmp, '-');
    n = stoi(tmp) - 1;
    student.dOB.tm_mon = n;
    getline(fin, tmp, '\n');
    n = stoi(tmp) - 1900;
    student.dOB.tm_year = n;
    student.dOB = { 0, 0, 0, student.dOB.tm_mday, student.dOB.tm_mon, student.dOB.tm_year };
    getline(fin, student.className, '\n');
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
            fout << students[i].fullname << endl;
            fout << students[i].gender << endl;
            fout << setw(2) << setfill('0') << students[i].dOB.tm_mday << "-";
            fout << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << "-";
            fout << setw(2) << setfill(' ');
            fout << students[i].dOB.tm_year + 1900 << endl;
            fout << students[i].className << endl;
            fout << students[i].point.midterm << endl;
            fout << students[i].point.final << endl;
            fout << students[i].point.bonus << endl;
            fout << students[i].point.total << endl;
            for (int j = 0; j < 10; ++j)
            {
                fout << students[i].checkIn[j].time.startTime.tm_year + 1900 << " ";
                fout << setw(2) << setfill('0') << students[i].checkIn[j].time.startTime.tm_mon + 1 << " ";
                fout << setw(2) << setfill('0') << students[i].checkIn[j].time.startTime.tm_mday << " ";
                fout << setw(2) << setfill(' ');
                fout << setw(1);
                fout << students[i].checkIn[j].time.startTime.tm_hour << " ";
                fout << students[i].checkIn[j].time.startTime.tm_min << " ";
                fout << students[i].checkIn[j].time.endTime.tm_hour << " ";
                fout << students[i].checkIn[j].time.endTime.tm_min << " ";
                fout << students[i].checkIn[j].checkIn << endl;
            }
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
    string dir = folder + "/class_" + className + ".txt";
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
        size = countClass(fin);
        classes = new class_courseType[size];
        for (int i = 0; i < size; ++i)
        {
            getline(fin, classes[i].className, '\n');
            classes[i].n_crs = 0;
            classes[i].courseName = nullptr;
        }

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

            students[i].gender = -1;
            students[i].dOB.tm_year = -1 - 1900;
            students[i].dOB.tm_mon = -1 - 1;
            students[i].dOB.tm_mday = -1;
            for (int j = 0; j < 10; ++j)
            {
                students[i].checkIn[j].time.startTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
                students[i].checkIn[j].time.endTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
                students[i].checkIn[j].checkIn = -1;
            }
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
    if (checkUpdate_string(oldStudent.password, newStudent.password) == true)
        oldStudent.password = newStudent.password;
    if (checkUpdate_string(oldStudent.fullname, newStudent.fullname) == true)
        oldStudent.fullname = newStudent.fullname;
    if (checkUpdate_int(oldStudent.gender, newStudent.gender) == true)
        oldStudent.gender = newStudent.gender;
    if (checkUpdate_tm(oldStudent.dOB, newStudent.dOB) == true)
        oldStudent.dOB = newStudent.dOB;
    if (checkUpdate_string(oldStudent.className, newStudent.className) == true)
        oldStudent.className = newStudent.className;
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
}

void updateStudent_withoutScore_element(studentType& oldStudent, studentType newStudent)
{
    if (checkUpdate_int(oldStudent.iD, newStudent.iD) == true)
        oldStudent.iD = newStudent.iD;
    if (checkUpdate_string(oldStudent.password, newStudent.password) == true)
        oldStudent.password = newStudent.password;
    if (checkUpdate_string(oldStudent.fullname, newStudent.fullname) == true)
        oldStudent.fullname = newStudent.fullname;
    if (checkUpdate_int(oldStudent.gender, newStudent.gender) == true)
        oldStudent.gender = newStudent.gender;
    if (checkUpdate_tm(oldStudent.dOB, newStudent.dOB) == true)
        oldStudent.dOB = newStudent.dOB;
    if (checkUpdate_string(oldStudent.className, newStudent.className) == true)
        oldStudent.className = newStudent.className;
    for (int i = 0; i < 10; ++i)
        if (checkUpdate_checkin(oldStudent.checkIn[i], newStudent.checkIn[i]) == true)
            oldStudent.checkIn[i] = newStudent.checkIn[i];
}

void updateStudent_array(studentType*& students, int size, studentType newStudent)
{
    for (int i = 0; i < size; ++i)
        if (students[i].iD == newStudent.iD)
            updateStudent_element(students[i], newStudent);
}

void updateStudent_withoutScore_array(studentType*& students, int size, studentType newStudent)
{
    for (int i = 0; i < size; ++i)
        if (students[i].iD == newStudent.iD)
            updateStudent_withoutScore_element(students[i], newStudent);
}

void updateStudent(studentType newStudent, studentType*& students, int& size, string dir)
{
    students = readStudents(dir, size);
    updateStudent_array(students, size, newStudent);
    writeStudent(students, size, dir);
}

void updateCourse(studentType newStudent, studentType*& students, int& size, string dir)
{
    students = readCourse(dir, size);
    updateStudent_withoutScore_array(students, size, newStudent);
    writeCourse(students, size, dir);
}

void updateScore(studentType newStudent, studentType*& students, int& size, string dir)
{
    students = readCourse(dir, size);
    updateStudent_array(students, size, newStudent);
    writeCourse(students, size, dir);
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

void chooseCourse(semester_courseType* A, int size, int& c1, int& c2, int& c3)
{
    cout << "Please choose semester: " << endl;
    for (int i = 0; i < size; ++i)
        cout << "[" << i + 1 << "]: " << A[i].academicYear << " - " << A[i].semesterName << endl;
    cin >> c1;
    --c1;

    cout << "Please choose class: " << endl;
    for (int i = 0; i < A[c1].n_cls; ++i)
        cout << "[" << i + 1 << "]: " << A[c1].class_courses[i].className << endl;
    cin >> c2;
    --c2;

    cout << "Please choose course: " << endl;
    for (int i = 0; i < A[c1].class_courses[c2].n_crs; ++i)
        cout << "[" << i + 1 << "]: " << A[c1].class_courses[c2].courseName[i] << endl;
    cin >> c3;
    --c3;
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
        cout << setw(2) << setfill('0') << students[pos].checkIn[i].time.startTime.tm_mday << "-";
        cout << setw(2) << setfill('0') << students[pos].checkIn[i].time.startTime.tm_mon + 1 << "-";
        cout << setw(2) << setfill(' ');
        cout << students[pos].checkIn[i].time.startTime.tm_year + 1900 << "  ";
        if (students[pos].checkIn[i].checkIn == 1)
            cout << "Presence" << endl;
        else if (students[pos].checkIn[i].checkIn == 0)
            cout << "Absence" << endl;
        else
            cout << "Not Yet Checked" << endl;
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

void exportScore()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    studentType* students;
    int size;
    students = readCourse(dir, size);
    dir = getDir_score(folder, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);
    writeScore(students, size, dir);
    cout << "Mission complete." << endl;
}

void searchViewAttendance()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    viewCourse(dir);
}

string getDir_course_csv(string folder, string academicYear, string semester, string className, string courseName)
{
    string dir = folder + "/" + academicYear + "-" + semester + "-" + className + "-" + courseName + "-Attendances.csv";
    return dir;
}

void exportAttendances()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    studentType* students;
    int size;
    students = readCourse(dir, size);
    dir = getDir_course_csv(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);
    writeCourse_csv(students, size, dir);
    cout << "Mission complete." << endl;
}

void editAttendance()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    studentType* students;
    int size;
    students = readCourse(dir, size);
    viewCourse(dir);

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
    dir = getDir_class(folder, A[c1].class_courses[c2].className);
    updateStudent_class(tmp, newStudents, newSize, dir);

    semester_courseType* B;
    int m;
    B = initSemester_courses_student(tmp.iD, folder, m);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < B[i].n_cls; ++j)
            for (int k = 0; k < B[i].class_courses[j].n_crs; ++k)
            {
                dir = getDir_course(folder, B[i].academicYear, B[i].semesterName, B[i].class_courses[j].className, B[i].class_courses[j].courseName[k]);
                updateCourse(tmp, newStudents, newSize, dir);
            }

    cout << "Edit complete." << endl;
}

void importScore()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);
    string dir;

    chooseCourse(A, n, c1, c2, c3);

    folder = "import";

    cout << "Enter file directory:" << endl;
    cout << "[1]: Use default directory" << endl;
    cout << "[2]: Enter new directory" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        dir = getDir_score(folder, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);
        if (checkFile(dir) == false)
            cout << "File with correspoding name not found." << endl;
        break;
    }

    case 2:
    {
        cout << "Enter your directory below, use \"/\" instead of \"\\\":" << endl;
        cin.ignore();
        getline(cin, dir, '\n');
        if (checkFile(dir) == false)
            cout << "File with correspoding name not found." << endl;
        break;
    }

    default:
        break;
    }

    if (checkFile(dir) == true)
    {

        studentType* students;
        int size;
        students = readScore(dir, size);

        studentType tmp;
        studentType* newStudents;
        int newSize;
        folder = "data";

        for (int k = 0; k < size; ++k)
        {
            tmp = students[k];
            studentType* newStudents;
            int newSize;
            dir = getDir(folder, "Student.txt");
            updateStudent(tmp, newStudents, newSize, dir);
            dir = getDir_class(folder, A[c1].class_courses[c2].className);
            updateStudent_class(tmp, newStudents, newSize, dir);
            dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);
            updateScore(tmp, newStudents, newSize, dir);

            semester_courseType* B;
            int m;
            B = initSemester_courses_student(tmp.iD, folder, m);

            for (int i = 0; i < m; ++i)
                for (int j = 0; j < B[i].n_cls; ++j)
                    for (int k = 0; k < B[i].class_courses[j].n_crs; ++k)
                    {
                        dir = getDir_course(folder, B[i].academicYear, B[i].semesterName, B[i].class_courses[j].className, B[i].class_courses[j].courseName[k]);
                        updateCourse(tmp, newStudents, newSize, dir);
                    }
        }

        cout << "Import complete." << endl;
    }
}

void searchEditGrade()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

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
    dir = getDir_class(folder, A[c1].class_courses[c2].className);
    updateStudent_class(tmp, newStudents, newSize, dir);
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);
    updateScore(tmp, newStudents, newSize, dir);

    semester_courseType* B;
    int m;
    B = initSemester_courses_student(tmp.iD, folder, m);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < B[i].n_cls; ++j)
            for (int k = 0; k < B[i].class_courses[j].n_crs; ++k)
            {
                dir = getDir_course(folder, B[i].academicYear, B[i].semesterName, B[i].class_courses[j].className, B[i].class_courses[j].courseName[k]);
                updateCourse(tmp, newStudents, newSize, dir);
            }

    cout << "Edit complete." << endl;
}

void searchViewScore()
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses(folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);
    cout << "Scoreboard of " << A[c1].class_courses[c2].courseName[c3] << ":" << endl;
    viewScore(dir);
}

void searchCheckIn(int iD)
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses_student(iD, folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    cout << "Enter 1 to check-in: ";
    int one;
    cin >> one;
    if (one == 1)
        checkIn(iD, dir);
}

void searchViewCheckIn(int iD)
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses_student(iD, folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    viewCheckIn(iD, dir);
}

void searchViewSchedule(int iD)
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses_student(iD, folder, n);

    chooseCourse(A, n, c1, c2, c3);

    string dir = getDir_schedule(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className);
    cout << "Schedule: " << endl;
    viewSchedule(A[c1].class_courses[c2].courseName[c3], dir);
}

void searchViewScore_student(int iD)
{
    string folder = "data";
    semester_courseType* A;
    int n, c1, c2, c3;
    A = initSemester_courses_student(iD, folder, n);

    chooseCourse(A, n, c1, c2, c3);
    string dir;
    dir = getDir_course(folder, A[c1].academicYear, A[c1].semesterName, A[c1].class_courses[c2].className, A[c1].class_courses[c2].courseName[c3]);

    cout << "Scoreboard of " << A[c1].class_courses[c2].className << " - " << A[c1].class_courses[c2].courseName[c3] << ":" << endl;
    viewScore_student(iD, dir);
}

string* initCourses(string folder, string academicYear, string semester, string className, int& size)
{
    string* courses;
    courses = readSchedule_course(getDir_schedule(folder, academicYear, semester, className), size);
    int newSize = 0;

    for (int i = 0; i < size; ++i)
    {
        if (checkFile(getDir_course(folder, academicYear, semester, className, courses[i])) == true)
        {
            ++newSize;
        }
    }

    string* newCourses;
    if (newSize == 0)
        newCourses = nullptr;
    else
        newCourses = new string[newSize];

    if (newSize != 0)
    {
        int pos = 0;
        for (int i = 0; i < size; ++i)
        {
            if (checkFile(getDir_course(folder, academicYear, semester, className, courses[i])) == true)
            {
                newCourses[pos] = courses[i];
                ++pos;
            }
        }
    }

    delete[] courses;
    size = newSize;
    courses = newCourses;

    return courses;
}

void filterCourses(int iD, string*& courses, int& size, string folder, string academicYear, string semester, string className)
{
    string* newCourses;
    int newSize = 0;

    studentType* students;
    int n;

    for (int i = 0; i < size; ++i)
    {
        students = readCourse(getDir_course(folder, academicYear, semester, className, courses[i]), n);
        if (positionOfStudent_array(iD, students, n) != -1)
        {
            ++newSize;
        }
    }

    if (newSize == 0)
        newCourses = nullptr;
    else
        newCourses = new string[newSize];

    if (newSize != 0)
    {
        int pos = 0;
        for (int i = 0; i < size; ++i)
        {
            students = readCourse(getDir_course(folder, academicYear, semester, className, courses[i]), n);
            if (positionOfStudent_array(iD, students, n) != -1)
            {
                newCourses[pos] = courses[i];
                ++pos;
            }
        }
    }

    delete[] courses;
    size = newSize;
    courses = newCourses;
}

semester_courseType* initSemester_courses(string folder, int& size)
{
    ifstream fin;
    semester_courseType* A;

    A = readSemester(getDir(folder, "Semester.txt"), size);

    filterSemesters(folder, A, size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < A[i].n_cls; ++j)
        {
            A[i].class_courses[j].courseName = initCourses(folder, A[i].academicYear, A[i].semesterName, A[i].class_courses[j].className, A[i].class_courses[j].n_crs);
        }
    }

    return A;
}

semester_courseType* initSemester_courses_student(int iD, string folder, int& size)
{
    ifstream fin;
    semester_courseType* A;

    A = initSemester_courses(folder, size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < A[i].n_cls; ++j)
        {
            filterCourses(iD, A[i].class_courses[j].courseName, A[i].class_courses[j].n_crs, folder, A[i].academicYear, A[i].semesterName, A[i].class_courses[j].className);
        }
    }

    return A;
}

void filterSemesters(string folder, semester_courseType*& semesters, int& size)
{
    int newSize = 0;
    class_courseType* classes;
    int cls_size;
    classes = readClass(getDir(folder, "Class.txt"), cls_size);
    int tmp;

    bool** marker;
    marker = new bool* [size];
    for (int i = 0; i < size; ++i)
        marker[i] = new bool[cls_size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < cls_size; ++j)
            marker[i][j] = 0;

    bool* marker2;
    marker2 = new bool[size];
    for (int i = 0; i < size; ++i)
        marker2[i] = 0;

    for (int i = 0; i < size; ++i)
    {
        tmp = i;
        for (int j = 0; j < cls_size; ++j)
            if (checkFile(getDir_schedule(folder, semesters[i].academicYear, semesters[i].semesterName, classes[j].className)) == true)
            {
                if (tmp == i)
                {
                    ++newSize;
                    marker2[i] = 1;
                    ++tmp;
                }
                marker[i][j] = 1;
            }
    }

    semester_courseType* newSemesters;

    if (newSize == 0)
        newSemesters = nullptr;
    else
        newSemesters = new semester_courseType[newSize];

    if (newSize != 0)
    {

        int pos = 0;

        for (int i = 0; i < size; ++i)
        {
            if (marker2[i] == 1)
            {
                newSemesters[pos].academicYear = semesters[i].academicYear;
                newSemesters[pos].semesterName = semesters[i].semesterName;
                ++pos;
            }
        }

        for (int i = 0; i < newSize; ++i)
        {
            newSemesters[i].n_cls = 0;
        }

        pos = 0;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < cls_size; ++j)
            {
                if (marker[i][j] == 1)
                {
                    ++newSemesters[pos].n_cls;
                }
            }
            if (marker2[i] == 1)
                ++pos;
        }

        pos = 0;
        int pos2 = 0;
        for (int i = 0; i < size; ++i)
        {
            if (marker2[i] == 1)
                if (newSemesters[pos].n_cls != 0)
                    newSemesters[pos].class_courses = new class_courseType[newSemesters[pos].n_cls];
            for (int j = 0; j < cls_size; ++j)
            {
                if (marker[i][j] == 1)
                {
                    newSemesters[pos].class_courses[pos2].className = classes[j].className;
                    ++pos2;
                }
            }
            if (marker2[i] == 1)
                ++pos;
        }

    }

    delete[] semesters;
    size = newSize;
    semesters = newSemesters;
}

int countStudent(ifstream& fin)
{
    string tmp;
    int count = 0;
    while (getline(fin, tmp, '\n'))
        ++count;
    count /= 6;

    fin.clear();
    fin.seekg(0, fin.beg);

    return count;
}

studentType readStudent_class_element(ifstream& fin)
{
    studentType student;
    string tmp;
    int n;

    fin >> student.iD;
    fin.ignore();
    getline(fin, student.fullname, '\n');
    fin >> student.gender;
    fin.ignore();
    getline(fin, tmp, '-');
    n = stoi(tmp);
    student.dOB.tm_mday = n;
    getline(fin, tmp, '-');
    n = stoi(tmp) - 1;
    student.dOB.tm_mon = n;
    getline(fin, tmp, '\n');
    n = stoi(tmp) - 1900;
    student.dOB.tm_year = n;
    student.dOB = { 0, 0, 0, student.dOB.tm_mday, student.dOB.tm_mon, student.dOB.tm_year };

    student.point = { -1, -1, -1, -1 };
    for (int i = 0; i < 10; ++i)
    {
        student.checkIn[i].time.startTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
        student.checkIn[i].time.endTime = { -1, -1, -1, -1, -1 - 1, -1 - 1900 };
        student.checkIn[i].checkIn = -1;
    }

    return student;
}

studentType* readStudent_class_array(ifstream& fin, int& size)
{
    size = countStudent_class(fin);
    studentType* array;
    array = new studentType[size];

    for (int i = 0; i < size; ++i)
        array[i] = readStudent_class_element(fin);

    return array;
}

studentType* readStudent_class(string dir, int& size)
{
    ifstream fin;
    studentType* array = nullptr;

    fin.open(dir);
    if (!fin.is_open())
        cout << "Cannot open file." << endl;
    else
    {
        array = readStudent_class_array(fin, size);

        fin.close();
    }

    return array;
}

int countStudent_class(ifstream& fin)
{
    string tmp;
    int count = 0;
    while (getline(fin, tmp, '\n'))
        ++count;
    count /= 4;

    fin.clear();
    fin.seekg(0, fin.beg);

    return count;
}

int countClass(ifstream& fin)
{
    string tmp;
    int count = 0;
    while (getline(fin, tmp, '\n'))
        ++count;

    fin.clear();
    fin.seekg(0, fin.beg);

    return count;
}

semester_courseType readSemester_element(ifstream& fin)
{
    semester_courseType semester;
    fin.ignore();
    getline(fin, semester.academicYear, '\n');
    getline(fin, semester.semesterName, '\n');
    semester.n_cls = 0;
    semester.class_courses = nullptr;

    return semester;
}

semester_courseType* readSemester(string dir, int& size)
{
    semester_courseType* semesters = nullptr;
    ifstream fin;
    fin.open(dir);
    if (!fin.is_open())
        cout << "Cannot open file." << endl;
    else
    {
        fin >> size;
        semesters = new semester_courseType[size];
        for (int i = 0; i < size; ++i)
            semesters[i] = readSemester_element(fin);

        fin.close();
    }

    return semesters;
}


void writeStudent_class(studentType* students, int size, string dir)
{
    ofstream fout;

    fout.open(dir);
    if (!fout.is_open())
        cout << "Cannot write file." << endl;
    else
    {
        for (int i = 0; i < size; ++i)
        {
            fout << students[i].iD << endl;
            fout << students[i].fullname << endl;
            fout << students[i].gender << endl;
            fout << setw(2) << setfill('0') << students[i].dOB.tm_mday << "-";
            fout << setw(2) << setfill('0') << students[i].dOB.tm_mon + 1 << "-";
            fout << setw(2) << setfill(' ');
            fout << students[i].dOB.tm_year + 1900 << endl;
        }

        fout.close();
    }
}

void updateStudent_class(studentType newStudent, studentType*& students, int& size, string dir)
{
    students = readStudent_class(dir, size);
    updateStudent_array(students, size, newStudent);
    writeStudent_class(students, size, dir);
}