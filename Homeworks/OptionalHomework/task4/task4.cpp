
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		bool divisibleOnlyByItself = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) {
				divisibleOnlyByItself = false;
			}
		}
		if (divisibleOnlyByItself) {
			cout << i << " ";
		}
	}
}