#include <iostream>
using namespace std;

int main()
{
	int n, max = -1, secondToMax = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input > secondToMax) {
			secondToMax = input;
			if (secondToMax > max) {
				int temp = max;
				max = secondToMax;
				secondToMax = temp;
			}
		}
	}
	cout << max << " " << secondToMax;

}