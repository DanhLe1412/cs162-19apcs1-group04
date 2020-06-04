#include "header.h"
void CRUD_Lecturer(){
    cout << "OKEY" << endl;
}
void inputLecturer_KeyBoard(Lecturer*& data){
   
    if(data->lec_username != "default"){
    //  This is input information of user when create a user 
    //
    // Input information of Lecturer
    // Full Name
    // username
    // password
    // Degree
    // Gender
    // ------- INPUT DATA AS ABOVE FORMAT ------------
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
        cout << "Input information to update Lecturer " << endl;
        cout << "username: " << data->lec_username;
        // This is input information of user when update lecturer
        // Full Name
        // Degree
        // Gender
        cout << "Lecturer Fullname: ";
        getline(cin, data->lec_Fullname);
        cout << "Lecturer Degree: ";
        getline(cin, data->lec_degree);
        cout << "Lecturer Gender(Male,Female): ";
        string gender;
        cin >> gender;
        if (gender.compare("Male"))
            data->gender = 1;
        else
            data->gender = 0;
    }
}
void create_lecturer(Lecturer *&pLecturer)
{
    Lecturer *i = pLecturer;
    int count=0;
    while (i->lec_pNext)
    {
        i = i->lec_pNext;
        count++;
    }
    i->lec_pNext = new Lecturer;
    i = i->lec_pNext;
    inputLecturer_KeyBoard(i);
    count++;
    i->lec_pNext = nullptr;
    // complete create new lecturer;
    
}
void saveLecturer_file(Lecturer *lec, int size){
    ofstream fout;
    fout.open("data/Lecturer.txt");
    if(!fout.is_open()) cout << "Error !!!" << endl;
    else {
        fout << size << endl;
        for(int i = 0; i< size; i++){
            fout << lec->lec_username << endl;
            fout << lec->lec_password << endl;
            fout << lec->lec_Fullname << endl;
            fout << lec->lec_degree << endl;
            fout << lec->gender << endl;
            lec= lec->lec_pNext;
        }
    }
}