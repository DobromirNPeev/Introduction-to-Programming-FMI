/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 3
*
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n < 2 || n>9) {
		cout << "Incorrect input";
		return 0;
	}
	int emptyRows = 25 - (n * 2 - 1);
	int centering = (80 - (n * 3)) / 2;
	for (int i = 1; i <= emptyRows / 2; i++)
	{
		cout << endl;
	}
	for (int numbersPerRowUpperHalf = 1; numbersPerRowUpperHalf <= n; numbersPerRowUpperHalf++)
	{
		for (int pushingToTheCenter = 0; pushingToTheCenter < centering; pushingToTheCenter++)
		{
			cout << " ";
		}
		for (int numberPerColumnLeftHalf = 1; numberPerColumnLeftHalf <= numbersPerRowUpperHalf; numberPerColumnLeftHalf++)
		{
			cout << numberPerColumnLeftHalf;
			if (numberPerColumnLeftHalf == n) {
				for (int rowWithDashes = 0; rowWithDashes < n; rowWithDashes++)
				{
					cout << "-";
				}
			}
		}
		for (int intervalsUntilRightHalf = n + n; intervalsUntilRightHalf > numbersPerRowUpperHalf; intervalsUntilRightHalf--)
		{
			if (numbersPerRowUpperHalf == n) {
				continue;
			}
			cout << " ";
		}
		for (int rightHalfIntervals = n; rightHalfIntervals > numbersPerRowUpperHalf; rightHalfIntervals--)
		{
			cout << " ";
		}
		for (int  numberPerColumnRightHalf = numbersPerRowUpperHalf; numberPerColumnRightHalf >= 1; numberPerColumnRightHalf--)
		{
			cout << numberPerColumnRightHalf;
		}
		cout << endl;
	}
	for (int numbersPerRowLowerHalf = n - 1; numbersPerRowLowerHalf >= 1; numbersPerRowLowerHalf--)
	{
		for (int pushingToTheCenter = 0; pushingToTheCenter < centering; pushingToTheCenter++)
		{
			cout << " ";
		}
		for (int numberPerColumnLeftHalf = 1; numberPerColumnLeftHalf <= numbersPerRowLowerHalf; numberPerColumnLeftHalf++)
		{
			cout << numberPerColumnLeftHalf;
		}
		for (int leftHalfIntervals = n; leftHalfIntervals > numbersPerRowLowerHalf; leftHalfIntervals--)
		{
			cout << " ";
		}
		for (int  rightHalfIntervals = n + n; rightHalfIntervals > numbersPerRowLowerHalf; rightHalfIntervals--)
		{
			cout << " ";
		}
		for (int numberPerColumnRightHalf = numbersPerRowLowerHalf; numberPerColumnRightHalf >= 1; numberPerColumnRightHalf--)
		{
			cout << numberPerColumnRightHalf;
		}
		cout << endl;
	}
	for (int i = emptyRows / 2; i <= emptyRows - 1; i++)
	{
		cout << endl;
	}
}