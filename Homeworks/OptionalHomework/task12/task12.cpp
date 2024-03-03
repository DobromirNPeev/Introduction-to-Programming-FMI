
#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		if (i == 0 || i == input - 1) {
			cout << "+ ";
		}
		else {
			cout << "- ";
		}
	}
	cout << endl;
	for (int i = 1; i < input - 1; i++)
	{
		for (int i = 0; i < input; i++)
		{
			if (i == 0 || i == input - 1) {
				cout << "| ";
			}
			else {
				cout << "- ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < input; i++)
	{
		if (i == 0 || i == input - 1) {
			cout << "+ ";
		}
		else {
			cout << "- ";
		}
	}
}