
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
			if (j == n) {
				for (int k = 0; k < n; k++)
				{
					cout << "-";
				}
			}
		}
		for (int j = n + n; j > i; j--)
		{
			if (i == n) {
				continue;
			}
			cout << " ";
		}
		for (int j = n; j > i; j--)
		{
			cout << " ";
		}
		for (int j = i; j >= 1; j--)
		{
			cout << j;
		}
		cout << endl;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		for (int j = n; j > i; j--)
		{
			cout << " ";
		}
		for (int j = n + n; j > i; j--)
		{
			cout << " ";
		}
		for (int j = i; j >= 1; j--)
		{
			cout << j;
		}
		cout << endl;
	}

}