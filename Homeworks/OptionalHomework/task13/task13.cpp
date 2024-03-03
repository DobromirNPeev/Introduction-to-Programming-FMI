
#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		if (i == 0 || i == input - 1) {
			for (int j = 0; j < input; j++)
			{
				cout << "* ";
			}
			for (int k = 1; k < input - 1; k++)
			{
				cout << "  ";
			}
			for (int l = 0; l < input; l++)
			{
				cout << "* ";
			}
		}
		else {

			for (int j = 0; j < input; j++)
			{
				if (j == 0 || j == input - 1) {
					cout << "* ";
				}
				else {
					cout << "  ";
				}
			}
			if (i == 1 || i == input - 2) {
				for (int k = 1; k < input - 1; k++)
				{
					cout << "* ";
				}
			}
			else {
				for (int k = 1; k < input - 1; k++)
				{
					cout << "  ";
				}
			}
			for (int j = 0; j < input; j++)
			{
				if (j == 0 || j == input - 1) {
					cout << "* ";
				}
				else {
					cout << "  ";
				}
			}
		}
		cout << endl;
	}
}