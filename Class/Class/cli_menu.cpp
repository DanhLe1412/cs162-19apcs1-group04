#include "define_cli_menu.h"
#include "class.h"

void Print_home_page(int i){
	cout << "This is Home page of Program" << endl;
	cout << "Which thing you want ??" << endl; 
	cout << "[1]: View Profile" << endl;
	cout << "[2]: Change Password" << endl;
	cout << "[3]: Log out" << endl;
	cin >> i;	
}

void home_cli(){
	int i = 1;
	while(i){
		switch (i)
		{
		case 0:
			return;
		
		default:
			break;
		}
	}
}
void SignIn_Menu()
{
	while (1)
	{ 	string username, passw;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "**                                   **" << endl;
		cout << "**        MANAGE STUGENT SYSTEM      **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl;
		cout << "***************************************" << endl;
		cout << "studentID: ";
		cin >> username;
		cout << "passwd: ";
		char s[100] = { 0 };
    int i;
    for (i = 0; i < 100;i++) {
        s[i] = _getch();
        if (s[i] == 13) {
            break;
        }
        else {
            _putch('*');
        }
    };
	//cin >> passw;
	getchar();	
	for(int i = 0; s[i] != '\0'; i++){
		passw = passw+s[i];
	}
	break;
	}
}

bool checkUser(string username, string pass){
	return true;
}