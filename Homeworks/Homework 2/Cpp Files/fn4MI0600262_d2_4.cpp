/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 4
*
*/
#include <iostream>

using namespace std;
const unsigned SIZE = 1024;
const int intDefaultValue = -858993460;


int findGCD(int a, int b)
{
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		int remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

bool GCDinArray(const unsigned arr[], unsigned short n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (findGCD(arr[j], arr[j + 1]) == 1) {
				return 1;
			}
		}
	}
	return 0;
}
bool isNValid(unsigned short n) {
	if (n < 2 || n>1024) {
		return true;
	}
	return false;
}
int main()
{
	unsigned short n;
	unsigned arr[SIZE];
	cin >> n;
	if (n < 2 || n>1024) {
		cout << -1;
		return 0;
	}
	for (size_t i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		if (number < 1 || number>1000000000) {
			cout << -1;
			return 0;
		}
		arr[i] = number;
	}
	cout << GCDinArray(arr, n);

}