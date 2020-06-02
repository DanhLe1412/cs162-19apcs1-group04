#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctime>
#include <iomanip>
using namespace std;

enum gender {
    male, female
};

enum dow {
    MON = 2,
    TUE = 3,
    WED = 4,
    THU = 5,
    FRI = 6,
    SAT = 7
};

struct Semester {
    string years;
    string semester;
    Semester* pNext;
};

struct Course {
    string CourseId;
    string CourseName;
    string Class;
    string LecturerUsername;
    string LecturerName;
    string LecturerDegree;
    string LecturerGender;
    string StartDate;
    string EndDate;
    string DayOfWeek;
    string StartHour;
    string StartMinutes;
    string EndHour;
    string EndMinutes;
    string room;
    Course* pNext;
};

// [13]
void create_years_semesters(Semester* pHead);
void update_years_semesters(Semester* pHead);
void delete_years_semesters(Semester* pHead);
void view_years_semesters();
void CRUD_years_semesters();

// [14]
void makeFileCourse(string years, string semester, string Class, Course* course);
string convertDate(string date);
void importCourses();

// [15]
void addCourseManually();

// 16
void editExistingCourse();

// [23]