#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <sys/types.h>
#include <dirent.h>
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

struct StudentInCourse {
    string username;
    string password;
    string fullname;
    string dob;
    string Class;
    string status;
    string midterm, Final, bonus, total;
    string attendance[10];
    StudentInCourse* pNext;
};

// [13]
void create_years_semesters(Semester* pHead);
void update_years_semesters(Semester* pHead);
void delete_years_semesters(Semester* pHead);
void view_years_semesters();
void CRUD_years_semesters();

void makeFileCourse(string years, string semester, string Class, Course* course);
string convertDate(string date);

// [14]
void importCourses();

// [15]
void addCourseManually();

// 16
void editExistingCourse();

// [17]
void removeCourse();

// [18]
void removeStudentFromScore();

// [19]
void addStudentToScore();

// [20]
void viewCourseInSemester();

// [21]
void viewStudentsInCourse();

// [22]
void viewAttendanceList();
