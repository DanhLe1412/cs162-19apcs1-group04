#include "function.h"

int main()
{
	//menu();

	string folder = "Files";
	academicYear_courseType* A;
	int n, a, s, c, cs;
	A = initAcademicYear_courses(folder, n);

	chooseCourse(A, n, a, s, c, cs);
	string dir;
	dir = getDir_course(folder, A[a].academicYear, A[a].semester_courses[s].semesterName, A[a].semester_courses[s].class_courses[c].className, A[a].semester_courses[s].class_courses[c].courseName[cs]);

	cout << "Scoreboard of " << A[a].semester_courses[s].class_courses[c].className << " - " << A[a].semester_courses[s].class_courses[c].courseName[cs] << ":" << endl;
	viewScore(dir);

	return 0;
}