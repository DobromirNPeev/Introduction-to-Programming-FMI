#include <iostream>
using namespace std;

int main()
{
	int n;
	int lastJ = 1, firstJ = 0, intermediate = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1) {
			intermediate = firstJ + n;
			for (int j = firstJ + 1; j <= intermediate; j++)
			{
				cout << j << " ";
				lastJ = j;
			}
			cout << endl;
		}
		else {
			firstJ = i * n;
			for (int k = firstJ; k > lastJ; k--)
			{
				cout << k << " ";

			}
			cout << endl;
		}
	}
}