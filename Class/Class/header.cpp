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
        fout << t.tm_year << " " << setw(2) << setfill('0') << t.tm_mon << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        t.tm_year -= 1900;
        t.tm_mon -= 1;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl;
        sec = mktime(&t) + (7 * 24 * 60 * 60);
		localtime_s(&t, &sec);
        if (i + 1 == n) {
            fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1;
        }
        else {
            fout << t.tm_year + 1900 << " " << setw(2) << setfill('0') << t.tm_mon + 1 << " " << setw(2) << setfill('0') << t.tm_mday << " " << -1 << endl << endl;
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
    cur->pNext = new Course;
    cur->pNext = tmp;
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
        fin >> n;
        string lecturer;
        check = false;
        for (int i = 0; i < n; i++) {
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
	for (int i = 0; i < 10; i++) {
		attendance[i] = curStudent->attendance[i];
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
        fin >> n;
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
    }
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
    }
}