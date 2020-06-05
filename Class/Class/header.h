#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <sys/types.h>
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
    string fullname;
    string dob;
    string Class;
    string status;
    string midterm, Final, bonus, total;
    string attendance[10];
    StudentInCourse* pNext;
};
struct Lecturer{
    string lec_username = "default";
    string lec_password;
    string lec_Fullname;
    string lec_degree;
    bool gender; //0 : Female, 1: Male
    Lecturer* lec_pNext;
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

// [16]
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

//[23]
void CRUD_Lecturer();

// For [24] to [38]

#include <chrono>

using namespace std::chrono;

struct durationType
{
    tm startTime, endTime;
};

struct checkInType
{
    durationType time;
    int checkIn;
};

struct pointType
{
    float midterm, final, bonus, total;
};

struct studentType
{
    int iD;
    int password;
    string fullname;
    int gender;
    tm dOB;
    string className;
    pointType point;
    checkInType checkIn[10];
};

struct class_courseType
{
    string className;
    int n_crs;
    string* courseName;
};

struct semester_courseType
{
    string academicYear;
    string semesterName;
    int n_cls;
    class_courseType* class_courses;
};

struct scheduleType
{
    string courseName, courseNameFull, className, lecturer, lecturerFull, lecturerDegree, room;
    bool status;
    tm startTime, endTime;
};

// [24]
void searchViewScore();

// [25]
void exportScore();

// [26] [30]
void searchViewAttendance();

// [27]
void exportAttendances();

// [31]
void editAttendance();

// [32]
void importScore();

// [33]
void searchEditGrade();

// [34]
void searchViewScore();

// [35]
void searchCheckIn(int iD);

// [36]
void searchViewCheckIn(int iD);

// [37]
void searchViewSchedule(int iD);

// [38]
void searchViewScore_student(int iD);


// General Functions
bool checkFile(string dir);
string getDir(string folder, string file);
string getDir_course(string folder, string academicYear, string semester, string className, string courseName);
string getDir_course_csv(string folder, string academicYear, string semester, string className, string courseName);
string getDir_schedule(string folder, string academicYear, string semester, string className);
string getDir_class(string folder, string className);
string getDir_score(string folder, string className, string courseName);
int positionOfStudent_array(int& no, studentType* students, int size);
int positionOfCourse_array(string courseName, scheduleType* schedules, int size);
void chooseCourse(semester_courseType* A, int size, int& c1, int& c2, int& c3);
semester_courseType* initSemester_courses(string folder, int& size);
semester_courseType* initSemester_courses_student(int iD, string folder, int& size);
string* initCourses(string folder, string academicYear, string semester, string className, int& size);
void filterSemesters(string folder, semester_courseType*& semesters, int& size);
void filterCourses(int iD, string*& courses, int& size, string folder, string academicYear, string semester, string className);

// Reading Functions
durationType readDuration(ifstream& fin);
int countStudent(ifstream& fin);
int countStudent_class(ifstream& fin);
studentType* readStudents(string dir, int& size);
studentType* readStudent_array(ifstream& fin, int& size);
studentType readStudent_element(ifstream& fin);
studentType* readStudent_class(string dir, int& size);
studentType* readStudent_class_array(ifstream& fin, int& size);
studentType readStudent_class_element(ifstream& fin);
studentType* readCourse(string dir, int& size);
studentType* readCourse_array(ifstream& fin, int& size);
studentType readCourse_element(ifstream& fin);
scheduleType* readSchedule(string dir, int& size);
string* readSchedule_course(string dir, int& size);
scheduleType* readSchedule_array(ifstream& fin, int& size);
scheduleType readSchedule_element(ifstream& fin);
int countClass(ifstream& fin);
class_courseType* readClass(string dir, int& size);
semester_courseType readSemester_element(ifstream& fin);
semester_courseType* readSemester(string dir, int& size);
studentType* readScore(string dir, int& size);

// Writing Functions
void writeStudent(studentType* students, int size, string dir);
void writeStudent_class(studentType* students, int size, string dir);
bool checkUpdate_string(string oldOne, string newOne);
bool checkUpdate_int(int oldOne, int newOne);
bool checkUpdate_float(float oldOne, float newOne);
bool checkUpdate_tm(tm oldOne, tm newOne);
bool checkUpdate_checkin(checkInType oldOne, checkInType newOne);
void updateStudent_element(studentType& oldStudent, studentType newStudent);
void updateStudent_array(studentType*& students, int size, studentType newStudent);
void updateStudent(studentType newStudent, studentType*& students, int& size, string dir);
void updateStudent_class(studentType newStudent, studentType*& students, int& size, string dir);
void writeCourse(studentType* students, int size, string dir);
void writeCourse_csv(studentType* students, int size, string dir);
void updateCourse(studentType newStudent, studentType*& students, int& size, string dir);
void writeScore(studentType* students, int size, string dir);

// Viewing Functions
void viewCourse(string dir);
void viewScore(string dir);
void viewSchedule(string courseName, string dir);
void viewCheckIn(int iD, string dir);

// Check-ining Functions
void checkIn(int iD, string dir);
time_t getCurrentTime();
bool checkDuration(durationType duration, time_t time);
void checkIn_element(studentType& student, time_t time);

