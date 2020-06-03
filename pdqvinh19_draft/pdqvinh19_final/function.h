#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;
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
	tm dOB;
	string className;
	int attendingStatus;
	pointType point;
	checkInType checkIn[10];
	int droppedStatus;
};

struct class_courseType
{
	string className;
	int n_crs;
	string* courseName;
};

struct semester_courseType
{
	string semesterName;
	int n_cls;
	class_courseType* class_courses;
};

struct academicYear_courseType
{
	string academicYear;
	int n_smt;
	semester_courseType* semester_courses;
};

struct scheduleType
{
	string courseName, courseNameFull, className, lecturer, lecturerFull, lecturerDegree, room;
	bool status;
	tm startTime, endTime;
};

// General Functions
void menu();
bool checkFile(string dir);
string getDir(string folder, string file);
string getDir_course(string folder, string academicYear, string semester, string className, string courseName);
string getDir_schedule(string folder, string academicYear, string semester, string className);
string getDir_class(string folder, string className);
string getDir_score(string folder, string className, string courseName);
int positionOfStudent_array(int& no, studentType* students, int size);
int positionOfCourse_array(string courseName, scheduleType* schedules, int size);
academicYear_courseType* initAcademicYear_courses(string folder, int& size);
academicYear_courseType* initAcademicYear_courses_student(int iD, string folder, int& size);
void filterClasses(string folder, class_courseType*& classes, int& size);
void filterCourses_element(string folder, class_courseType& cls_crs);
void filterCourses_student_element(int iD, string folder, class_courseType& cls_crs);
void filterCourses(string folder, class_courseType*& classes, int& size);
void filterCourses_student(int iD, string folder, class_courseType*& classes, int& size);
void chooseCourse(academicYear_courseType* A, int size, int& a, int& s, int& c, int& cs);

// Read Functions
durationType readDuration(ifstream& fin);
studentType* readStudent(string dir, int& size);
studentType* readStudent_array(ifstream& fin, int& size);
studentType readStudent_element(ifstream& fin);
studentType* readCourse(string dir, int& size);
studentType* readCourse_array(ifstream& fin, int& size);
studentType* attendanceCourse_array(studentType* students, int size, int& newSize);
studentType readCourse_element(ifstream& fin);
scheduleType* readSchedule(string dir, int& size);
string* readSchedule_course(string dir, int& size);
scheduleType* readSchedule_array(ifstream& fin, int& size);
scheduleType readSchedule_element(ifstream& fin);
academicYear_courseType* readSemester(string dir, int& size);
academicYear_courseType* readSemester_array(ifstream& fin, int& size);
academicYear_courseType readSemester_element(ifstream& fin, int pos);
class_courseType* readClass(string dir, int& size);
studentType* readScore(string dir, int& size);

// Write Functions
void writeStudent(studentType* students, int size, string dir);
bool checkUpdate_string(string oldOne, string newOne);
bool checkUpdate_int(int oldOne, int newOne);
bool checkUpdate_float(float oldOne, float newOne);
bool checkUpdate_tm(tm oldOne, tm newOne);
bool checkUpdate_checkin(checkInType oldOne, checkInType newOne);
void updateStudent_element(studentType& oldStudent, studentType newStudent);
void updateStudent_array(studentType*& students, int size, studentType newStudent);
void updateStudent(studentType newStudent, studentType*& students, int& size, string dir);
void writeCourse(studentType* students, int size, string dir);
void writeCourse_csv(studentType* students, int size, string dir);
void updateCourse(studentType newStudent, studentType*& students, int& size, string dir);
void writeScore(studentType* students, int size, string dir);

// View Functions
void viewCourse(string dir);
void viewCourse_attendance(string dir);
void viewScore(string dir);
void viewSchedule(string courseName, string dir);
void viewCheckIn(int iD, string dir);

// Check-in Functions
void checkIn(int iD, string dir);
time_t getCurrentTime();
bool checkDuration(durationType duration, time_t time);
void checkIn_element(studentType& student, time_t time);

// Case 24
void searchViewScore();
// Case 25
void exportScore();
// Case 