#ifndef _CLI
#define _CLI
#include<iostream>
#include <conio.h>
using namespace std;

void SignIn_Menu();
void home_cli();
bool checkUser(string username, string pass, int type);
void student_cli();
void staff_cli();
void lecturer_cli();
void Print_home_page(int& i, int type);

#endif