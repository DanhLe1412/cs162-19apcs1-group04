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

struct studentType
{
	int iD;
	string fullName;
	float finalPoint;
	bool status;
};

struct durationType
{
	tm startTime, endTime;
};

struct checkInType
{
	durationType time;
	int checkIn;
};

struct studentCheckInType
{
	studentType student;
	checkInType checkIn[10];
};

struct classAndCourse
{
	string className;
	int courseQuantity;
	string* courseName;
};

struct courseNameLongAndShort
{
	string longName;
	string shortName;
};

struct scheduleType
{
	string courseNameShort, courseNameFull, className, lecturer, lecturerFull, lecturerDegree, room;
	bool status;
	tm startTime, endTime;
};

struct pointFullType
{
	float midterm, final, bonus, total;
};

struct studentCourseFullType
{
	int iD;
	int password;
	string fullName;
	tm dOB;
	string className;
	bool attendingStatus;
	pointFullType point;
	checkInType checkIn[10];
	bool droppedStatus;
};

struct semesterType
{
	string academicYear, semester;
};

void menu();
int loadN(ifstream &fin);
studentType loadStudent(ifstream &fin);
studentType* loadStudentArray(ifstream& fin, int &n);
void listStudentCourse(studentType* a, int n);
studentType loadStudentAttendance(ifstream& fin);
studentType* loadStudentAttendanceArray(ifstream& fin, int& n);
int countStudentAttendance(studentType* a, int n);
void listStudentAttendanceCourse(studentType* a, int n);
int countCSV(ifstream& fin);
studentType* loadScoreBoardCSV(ifstream& fin, int size);
void saveScoreBoard(ofstream& fout, studentType* student, int size);
void importScoreBoard(studentType*& scoreBoard);
studentType loadStudentScore(ifstream& fin);
studentType* loadScoreBoard(ifstream& fin, int& n);
void printScoreBoard(studentType* scoreBoard, int size);
int findPositionStudent(studentType* scoreBoard, int size, int x);
void editGrade();
string* listCoursesFromClass(string className, int& size);
string loadCourse(ifstream& fin);
string* loadCoursesArray(ifstream& fin, int& size);
studentType* loadStudentFromCourse(string courseName, int& size);
studentType loadStudentNew(ifstream& fin);
studentType* loadStudentArrayNew(ifstream& fin, int& n);
durationType loadDuration(ifstream& fin);
bool checkStudentID(studentType* student, int size, int iD);
bool checkStudentCourseAttendance(string courseName, int& size, int iD);
void displayCoursesOfStudentID(int iD);
durationType loadDuration(ifstream& fin);
studentCheckInType loadStudentCheckInCourse(ifstream& fin);
studentCheckInType* loadStudentCheckInCourseArray(ifstream& fin, int& size);
void writeStudentCheckInCourseArray(ofstream& fout, studentCheckInType* student, int size);
void checkYes(checkInType &checkIn);
void checkNo(checkInType &checkIn);
bool checkBetweenDuration(durationType duration, time_t time);
void checkInDuration(checkInType &checkIn, time_t time);
time_t currentTime();
void checkInArray(checkInType checkIn[], int size, time_t time);
int findIDStudentCheckInCourseArray(studentCheckInType* student, int size, int iD);
void checkInStudentCourseArray(studentCheckInType* student, int size, int iD, time_t time);
void checkInCourseName(string courseName, int iD, time_t time);
string* loadClassArray(ifstream& fin, int& size);
classAndCourse* initializeClassCourseArray(int& size);
courseNameLongAndShort* availableCoursesOfStudentID(classAndCourse* classCourseArray, int classCourseSize, int iD, int& size);
bool checkStudentCourseAttendanceCheckIn(string courseName, int iD);
void chooseCourseAndCheckIn(int iD);
string displayCheckInResult(checkInType checkIn);
void displayCheckInResultList(checkInType checkIn[], int size);
studentCheckInType* loadStudentCheckInCourseArrayFromName(string courseName, int& size);
void chooseCourseAndDisplayCheckInResult(int iD);
void displaySchedule(scheduleType schedule);
scheduleType loadSchedule(ifstream& fin);
scheduleType* loadScheduleArray(ifstream& fin, int& size);
scheduleType* loadScheduleArrayFromClass(string className, int& size);
int findCourseScheduleArray(scheduleType* scheduleArray, int size, string courseName);
string getClassName(string courseNameLong);
void viewSchedule(int iD);
void displayScoreStudent(studentCourseFullType student);
studentCourseFullType loadStudentCourseFull(ifstream& fin);
studentCourseFullType* loadStudentCourseFullArray(ifstream& fin, int& size);
studentCourseFullType* loadStudentCourseFullArrayFromName(string courseNameLong, int& size);
int findIDStudentCourseFullArray(studentCourseFullType* studentArray, int size, int iD);
void viewScore(int iD);
void displayListCoursesSemester();
semesterType loadSemester(ifstream& fin);
semesterType* loadSemesterArray(ifstream& fin, int& size);
semesterType* loadSemesterArrayFromDir(string dir, int& size);
void displaySemesterListFromDir(string dir, semesterType*& semesterArray, int& size);
string* loadClassNamesArrayFromDir(string dir, int& size);
bool checkFileAvailable(string dir);
string* arrayOfClassesWithAvailableSchedule(string preDir, string postDir, string* classNamesArray, int classNamesArraySize, int& classesWithAvailableScheduleArraySize);
scheduleType* loadSchedulesArrayFromDir(string dir, int& size);
string* arrayOfCoursesInClassWithAvailableStudentsList(string preDir, string postDir, scheduleType* schedulesArray, int schedulesArraySize, int& coursesArraySize);
classAndCourse* arrayOfAvailableCoursesInClasses(string preDir, int& size);
studentCourseFullType* loadStudentsCourseFullArrayFromDirNew(string folderDir, semesterType semester, string className, string courseName, string postDir, int& size);
bool checkStudentAttendanceCourseFull(studentCourseFullType student);
studentCourseFullType* arrayOfAttendances(studentCourseFullType* studentsArray, int studentsArraySize, int& size);
void displayAttendances(studentCourseFullType* studentsArray, int size);
void searchAndViewAttendances(string folderDir, string& className, string& courseName, studentCourseFullType*& attendancesArray, int& size);
void writeAttendancesListToCSV(string className, string courseName, string folderDir, studentCourseFullType* studentsArray, int size);
studentCourseFullType readStudent_element(ifstream& fin);
studentCourseFullType* readStudent_array(ifstream& fin, int& size);

studentCourseFullType* readStudent(string dir, int& size);

int positionInStudent_array(int iD, studentCourseFullType* studentsArray, int size);
void writeStudent(studentCourseFullType* students, int size, string dir);
studentCourseFullType readCourse_element(ifstream& fin);
studentCourseFullType* readCourse_array(ifstream& fin, int& size);

studentCourseFullType* readCourse(string dir, int& size);

void writeCourse(studentCourseFullType* students, int size, string dir);
int positionOfStudent_array(int& no, studentCourseFullType* studentsArray, int size);
studentCourseFullType* attendanceCourse_array(studentCourseFullType* students, int size, int& newSize);
void viewCourse(studentCourseFullType* students, int size);
string* availableCourses_array(classAndCourse* classes, int classesSize, int iD, int& size);
classAndCourse* arrayOfAvailableCoursesInClassesNew(string preDir, int& size);
void editAttendance();