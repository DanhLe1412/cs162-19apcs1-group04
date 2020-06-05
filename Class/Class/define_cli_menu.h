#ifndef _CLI
#define _CLI
#include<iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <sstream> 
using namespace std;


void SignIn_Menu();
void home_cli(string username, string pass, int type);
bool checkUser(string username, string pass, int type);
void student_cli();
void staff_cli();
void lecturer_cli();
void Print_home_page(int& i, int type);
void changePassword(string username, string& pass, int type);
void checkUser_to_print_inf(string username, string pass, int type);
#endif