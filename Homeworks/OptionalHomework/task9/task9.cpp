#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int nAsRows = n;
	for (int j = 1; j <= n; j++)
	{
		for (int i = nAsRows; i > 1; i--)
		{
			cout << " ";
		}
		for (int k = j; k >= 1; k--)
		{
			cout << k;
		}
		cout << endl;
		nAsRows--;
	}
	nAsRows = n;
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < j;i++)
		{
			cout << " ";
		}
		for (int k = nAsRows - 1; k > 0; k--)
		{
			cout << k;
		}
		cout << endl;
		nAsRows--;
	}
}