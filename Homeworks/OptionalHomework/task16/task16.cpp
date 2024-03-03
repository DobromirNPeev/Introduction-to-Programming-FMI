
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int missingNumber = n;
	for (int i = 0; i < n + 1; i++)
	{
		if (i == 0) {
			for (int j = 0; j < n + 2; j++)
			{
				cout << "#";
			}
		}
		else {

			cout << "#";
			for (int k = i; k <= n; k++)
			{
				cout << k;

			}

			for (int l = 1; l <= n - missingNumber; l++)
			{
				cout << l;
			}
			missingNumber--;
			cout << "#";
		}
		cout << endl;
	}
	if (n % 2 == 0) {
		cout << "#";
		for (int i = 1; i <= n; i++)
		{
			if (i == n / 2 || i == n / 2 + 1)
			{
				cout << "X";
			}
			else {
				cout << " ";
			}
		}
		cout << "#";
	}
	else {
		cout << "#";
		for (int i = 1; i <= n; i++)
		{
			if (i == n / 2 + 1)
			{
				cout << "X";
			}
			else {
				cout << " ";
			}
		}
		cout << "#";
	}
	cout << endl;
	missingNumber = n;
	for (int i = 0; i < n + 1; i++)
	{
		if (i == n) {
			for (int j = 0; j < n + 2; j++)
			{
				cout << "#";
			}
		}
		else {

			cout << "#";
			for (int k = n - i; k <= n; k++)
			{
				cout << k;

			}

			for (int l = 1; l < missingNumber; l++)
			{
				cout << l;
			}
			missingNumber--;
			cout << "#";
		}
		cout << endl;
	}
}