#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	while (true)
	{
		int input;
		cin >> input;
		sum += input;
		if (input == 0) {
			cout << sum;
			break;
		}
	}
}