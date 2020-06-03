#include "function.h"

int main()
{
	while (true)
	{
		menu();
		cout << "Input 0 to exit, other integers to repeat again:" << endl;
		int choice;
		cin >> choice;
		if (choice == 0)
			break;
	}

	return 0;
}