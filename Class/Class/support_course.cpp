#include "header.h"
void CRUD_Lecturer() {
    cout << "OKEY" << endl;
    system("CLS");
    Lecturer* pLec = new Lecturer;
    int size = 0;
    cout << "[1]: Create new lecturer" << endl;
    cout << "[2]: Update lecturer:" << endl;
    cout << "[3]: Delete lecturer" << endl;
    cout << "[4]: View all lecturer" << endl;
    cout << "[0]: Back to main page" << endl;
    int i;
    cin >> i;
    switch (i)
    {
    case 1:
    {
        getLecrurer_file(pLec, size);
        create_lecturer(pLec, size);
        deleteAllNode(pLec);
        break;
    }
    case 2: {
        getLecrurer_file(pLec, size);
        updateLecturer(pLec, size);
        deleteAllNode(pLec);
        Sleep(3000);
        break;
    }
    case 3: {
        getLecrurer_file(pLec, size);
        delete_one_lecturer(pLec, size);
        deleteAllNode(pLec);
        break;
    }
    case 4: {
        getLecrurer_file(pLec, size);
        viewAll_lecturer(pLec);
        deleteAllNode(pLec);
        Sleep(3000);
        break;
    }
    default:
        break;
    }
}
void inputLecturer_KeyBoard(Lecturer*& data)
{

    if (data->lec_username.compare("default") == 0)
    {
        //  This is input information of user when create a user
        //
        // Input information of Lecturer
        // username
        // password
        // Full Name
        // Degree
        // Gender
        // ------- INPUT DATA AS ABOVE FORMAT ------------
        cout << "Lecturer username: ";
        cin >> data->lec_username;
        cout << "Lecturer password: ";
        cin >> data->lec_password;
        cout << "Lecturer Fullname: ";
        cin.ignore(100, '\n');
        getline(cin, data->lec_Fullname);
        cout << "Lecturer Degree: ";
        cin >> data->lec_degree;
        cout << "Lecturer Gender(Male,Female): ";
        string gender;
        cin >> gender;
        if (gender.compare("Male") == 0)
            data->gender = 0;
        else
            data->gender = 1;
    }
    else
    {
        cout << "------------------------" << endl;
        cout << "Input information to update Lecturer " << endl;
        cout << "username: " << data->lec_username;
        // This is input information of user when update lecturer
        // Full Name
        // Degree
        // Gender
        cout << endl;
        cout << "Lecturer Fullname: ";
        cin.ignore(100, '\n');
        getline(cin, data->lec_Fullname);
        cout << "Lecturer Degree: ";
        cin >> data->lec_degree;
        cout << "Lecturer Gender(Male,Female): ";
        string gender;
        cin >> gender;
        if (gender.compare("Male") == 0)
            data->gender = 0;
        else
            data->gender = 1;
    }
}
void create_lecturer(Lecturer*& pLecturer, int& size)
{
    Lecturer* i = pLecturer;
    cout << "------------------" << endl;
    while (i->lec_pNext != nullptr)
    {
        i = i->lec_pNext;
    }

    inputLecturer_KeyBoard(i);
    i = pLecturer;
    size++;
    // complete create new lecturer;
    saveLecturer_file(i, size);
    cout << "successfull create lecturer" << endl;
    Sleep(5000);
}
void viewAll_lecturer(Lecturer* lec) {
    while (lec->lec_pNext != nullptr) {
        cout << "------------------" << endl;
        cout << lec->lec_username << endl;
        cout << lec->lec_Fullname << endl;
        cout << lec->lec_degree << endl;
        if (lec->gender == 0) cout << "Male" << endl;
        else cout << "Female" << endl;
        lec = lec->lec_pNext;
        cout << endl;
    }
}
void saveLecturer_file(Lecturer* lec, int size) {
    ofstream fout;
    fout.open("data/Lecturer.txt");
    if (!fout.is_open()) cout << "Error !!!" << endl;
    else {
        fout << size << endl;
        for (; lec != nullptr; ) {
            fout << lec->lec_username << endl;
            fout << lec->lec_password << endl;
            fout << lec->lec_Fullname << endl;
            fout << lec->lec_degree << endl;
            fout << lec->gender << endl;
            lec = lec->lec_pNext;
        }
    }
    fout.close();
}
void getLecrurer_file(Lecturer*& lec, int& size)
{
    ifstream fin;
    fin.open("data/Lecturer.txt");
    if (!fin.is_open()) {
        cout << "Error !!" << endl;
    }
    else {
        // size
        // username
        // password
        // Full Name
        // Degree
        // Gender
        fin >> size;
        Lecturer* pi = lec;

        for (int i = 0; i < size; i++) {
            fin >> pi->lec_username;
            fin >> pi->lec_password;
            fin.ignore(100, '\n');
            getline(fin, pi->lec_Fullname);
            fin >> pi->lec_degree;
            fin >> pi->gender;
            pi->lec_pNext = new Lecturer;
            pi = pi->lec_pNext;
        }
        pi = nullptr;
        fin.close();
    }
}
void deleteAllNode(Lecturer*& lec)
{
    Lecturer* tmp = lec;
    while (lec != NULL)
    {
        lec = lec->lec_pNext;
        delete tmp;
        tmp = lec;
    }
}
void updateLecturer(Lecturer* lecturer, int size) {
    viewAll_lecturer(lecturer);
    cout << "Get username of lecturer to update:";
    string update_lec;
    cin >> update_lec;
    Lecturer* i = lecturer;
    while (i->lec_pNext)
    {
        if (update_lec.compare(i->lec_username) == 0) {
            inputLecturer_KeyBoard(i);
        }
        i = i->lec_pNext;
    }
    Lecturer* lec = lecturer;
    ofstream fout;
    fout.open("data/Lecturer.txt");
    if (!fout.is_open()) cout << "Error !!!" << endl;
    else {
        fout << size << endl;
        for (; lec->lec_pNext != nullptr; ) {
            fout << lec->lec_username << endl;
            fout << lec->lec_password << endl;
            fout << lec->lec_Fullname << endl;
            fout << lec->lec_degree << endl;
            fout << lec->gender << endl;
            lec = lec->lec_pNext;
        }
    }
    fout.close();
}
void delete_one_lecturer(Lecturer* lec, int& size) {
    viewAll_lecturer(lec);
    cout << "Get username of lecturer to delete:";
    string delete_lec;
    cin >> delete_lec;
    Lecturer* i = lec;
    while (i) {
        if (delete_lec.compare(i->lec_pNext->lec_username) == 0) {
            i->lec_pNext = i->lec_pNext->lec_pNext;
            break;
        }
        else i = i->lec_pNext;
    }
    size--;
    ofstream fout;
    fout.open("data/Lecturer.txt");
    if (!fout.is_open()) cout << "Error !!!" << endl;
    else {
        fout << size << endl;
        for (; lec->lec_pNext != nullptr; ) {
            fout << lec->lec_username << endl;
            fout << lec->lec_password << endl;
            fout << lec->lec_Fullname << endl;
            fout << lec->lec_degree << endl;
            fout << lec->gender << endl;
            lec = lec->lec_pNext;
        }
    }
    fout.close();
}