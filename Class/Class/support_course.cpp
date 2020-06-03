#include "header.h"
void CRUD_Lecturer(){
    cout << "OKEY" << endl;
}
void inputLecturer_KeyBoard(Lecturer*& data){
    // Input information of Lecturer
    // Full Name
    // username
    // password
    // Degree
    // Gender
    if(data->lec_username != "default"){
    cout << "Lecturer Fullname: ";
    getline(cin,data->lec_Fullname);
    cout << "Lecturer username: ";
    getline(cin,data->lec_username);
    cout << "Lecturer password: ";
    getline(cin,data->lec_password);
    cout << "Lecturer Degree: ";
    getline(cin,data->lec_degree);
    cout << "Lecturer Gender(Male,Female): ";
    string gender;
    cin >> gender;
    if(gender.compare("Male")) data->gender = 1; else data->gender = 0;
    } 
    else
    {
        
    }
    
}
void create_lecturer(Lecturer *&pLecturer)
{
    Lecturer* i = pLecturer;
    Lecturer* data = nullptr;

}