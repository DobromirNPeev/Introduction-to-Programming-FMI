
#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;
	int inputCopy = input;
	for (int i = 1; i <= input; i++)
	{
		for (int j = 0; j < inputCopy;j++)
		{
			cout << " ";
		}
		for (int k = 1; k <= i; k++)
		{
			cout << k;
		}
		for (int o = i - 1; o >= 1; o--)
		{
			cout << o;
		}
		for (int l = 0; l < inputCopy; l++)
		{
			cout << " ";
		}
		inputCopy--;
		cout << endl;
	}
	for (int i = input - 1; i >= 1; i--)
	{
		for (int j = 0; j < input; j++)
		{
			cout << " ";
		}
		cout << i << endl;
	}
}

