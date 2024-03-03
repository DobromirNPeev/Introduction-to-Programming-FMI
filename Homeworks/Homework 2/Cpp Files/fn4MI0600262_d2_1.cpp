/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 1
*
*/

#include <iostream>
using namespace std;

const unsigned int SIZE = 1024;

void insertingZeroesInfront(char firstNum[], char secondNum[], unsigned short n, unsigned short k) {
	if (n > k) {
		int diff = n - k;
		for (int i = k; i >= 0; i--)
		{
			secondNum[i + diff] = secondNum[i];
		}
		for (int i = 0; i < diff; i++)
		{
			secondNum[i] = '0';
		}
	}
	else if (n < k) {
		int diff = k - n;
		for (int i = n; i >= 0; i--)
		{
			firstNum[i + diff] = firstNum[i];
		}
		for (int i = 0; i < diff; i++)
		{
			firstNum[i] = '0';
		}
	}
}
void movingNumberToTheRight(unsigned short n, char arr[]) {
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
}
void removingZeroesInfront(char arr[], unsigned short n) {
	while (arr[0] == '0') {
		movingNumberToTheRight(n, arr);
	}
}
void addintOneInfront(char arr[], unsigned short n) {
	for (int i = n; i >= 0; i--)
	{
		arr[i + 1] = arr[i];
	}
	if (arr[0] == arr[1]) {
		arr[0] = '1';
	}
	else {
		arr[0] = '1';
	}
}
void removingMinusInfront(char arr[], unsigned short n) {
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n] = '\0';
}
int absValue(int a) {
	if (a >= 0) {
		return a;
	}
	else {
		return -a;
	}
}
void Addition(char firstNumArr[], char secondNumArr[], char added[], unsigned short n) {
	bool addOne = false;
	for (int i = n - 1; i >= 0; i--)
	{
		int additionAsInt = firstNumArr[i] + secondNumArr[i] - 96;
		added[i] = firstNumArr[i] + secondNumArr[i] - '0';
		if (addOne)
		{
			if (added[i] == '9') {
				added[i] = '0';
				continue;
			}
			added[i]++;
			addOne = false;
		}
		if (additionAsInt >= 10) {
			added[i] -= 10;
			addOne = true;
		}
	}
	if (addOne) {
		addintOneInfront(added, n);
		n++;
	}
}
void Subtraction(char firstNumArr[], char secondNumArr[], char subtracted[], unsigned short n) {
	bool removeOne = false;
	for (int i = n - 1; i >= 0; i--)
	{
		if (firstNumArr[i] - secondNumArr[i] < 0) {
			int subtractionAsInt = firstNumArr[i] - secondNumArr[i] + 10;
			subtracted[i] = absValue(subtractionAsInt) + '0';
			if (removeOne)
			{
				if (subtracted[i] == '0') {
					subtracted[i] = '9';
					continue;
				}
				subtracted[i]--;
				removeOne = false;
			}
			removeOne = true;
		}
		else {
			int subtractionAsInt = firstNumArr[i] - secondNumArr[i];
			subtracted[i] = absValue(subtractionAsInt) + '0';
			if (removeOne)
			{
				if (subtracted[i] == '0') {
					subtracted[i] = '9';
					continue;
				}
				subtracted[i]--;
				removeOne = false;
			}
		}
	}
}
void addMinusInfront(char arr[], unsigned short n) {
	for (int i = n; i >= 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = '-';
}
void FirstNumberIsNegativeAndSecondPositive(unsigned short n, unsigned short k, char firstNumArr[], char secondNumArr[], char subtracted[], char added[]) {
	removingMinusInfront(firstNumArr, n);
	if (n - 1 == k) {
		for (size_t i = 0; i < k; i++)
		{
			if (firstNumArr[i] == secondNumArr[i]) {
				if (i == k - 1) {
					Addition(firstNumArr, secondNumArr, subtracted, n - 1);
					addMinusInfront(subtracted, k);
					added[0] = '0';
				}
				continue;
			}
			else if (firstNumArr[i] > secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, subtracted, n - 1);
				Subtraction(firstNumArr, secondNumArr, added, n - 1);
				removingZeroesInfront(added, n - 1);
				removingZeroesInfront(subtracted, n - 1);
				addMinusInfront(subtracted, n - 1);
				addMinusInfront(added, n - 1);
				break;

			}
			else if (firstNumArr[i] < secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, subtracted, k);
				Subtraction(secondNumArr, firstNumArr, added, k);
				removingZeroesInfront(added, k);
				removingZeroesInfront(subtracted, k);
				addMinusInfront(subtracted, k);
				break;
			}
		}
	}
	else if (n - 1 > k) {
		insertingZeroesInfront(firstNumArr, secondNumArr, n, k + 1);
		Subtraction(firstNumArr, secondNumArr, added, n - 1);
		Addition(firstNumArr, secondNumArr, subtracted, n - 1);
		removingZeroesInfront(added, n - 1);
		removingZeroesInfront(subtracted, n - 1);
		addMinusInfront(subtracted, n - 1);
		addMinusInfront(added, n - 1);
	}
	else if (n - 1 < k) {
		insertingZeroesInfront(firstNumArr, secondNumArr, n, k);
		Subtraction(secondNumArr, firstNumArr, added, k);
		Addition(firstNumArr, secondNumArr, subtracted, k);
		removingZeroesInfront(added, k);
		removingZeroesInfront(subtracted, k);
		addMinusInfront(subtracted, k);
	}
}
void FirstNumberIsPositiveAndSecondNegative(unsigned short n, unsigned short k, char firstNumArr[], char secondNumArr[], char subtracted[], char added[]) {
	removingMinusInfront(secondNumArr, k);
	if (n == k - 1) {
		for (size_t i = 0; i < k; i++)
		{
			if (firstNumArr[i] == secondNumArr[i]) {
				if (i == k - 1) {
					Addition(firstNumArr, secondNumArr, subtracted, k);
					addMinusInfront(subtracted, k);
					added[0] = '0';
				}
				continue;
			}
			else if (firstNumArr[i] > secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, subtracted, k - 1);
				Subtraction(firstNumArr, secondNumArr, added, k - 1);
				removingZeroesInfront(added, k - 1);
				removingZeroesInfront(subtracted, k - 1);
				break;

			}
			else if (firstNumArr[i] < secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, subtracted, k - 1);
				Subtraction(secondNumArr, firstNumArr, added, k - 1);
				removingZeroesInfront(added, k - 1);
				removingZeroesInfront(subtracted, k - 1);
				addMinusInfront(added, k - 1);
				break;
			}
		}
	}
	else if (n < k - 1) {
		insertingZeroesInfront(firstNumArr, secondNumArr, n + 1, k);
		Subtraction(secondNumArr, firstNumArr, added, k - 1);
		Addition(firstNumArr, secondNumArr, subtracted, k - 1);
		removingZeroesInfront(added, k - 1);
		removingZeroesInfront(subtracted, k - 1);
		addMinusInfront(added, k - 1);
	}
	else if (n > k - 1) {
		insertingZeroesInfront(firstNumArr, secondNumArr, n, k);
		Subtraction(firstNumArr, secondNumArr, added, n);
		Addition(firstNumArr, secondNumArr, subtracted, n);
		removingZeroesInfront(added, n);
		removingZeroesInfront(subtracted, n);
	}
}
void BothNumbersAreNegative(unsigned short n, unsigned short k, char firstNumArr[], char secondNumArr[], char subtracted[], char added[]) {
	removingMinusInfront(firstNumArr, n);
	removingMinusInfront(secondNumArr, k);
	if (n == k) {
		for (size_t i = 0; i < k; i++)
		{
			if (firstNumArr[i] == secondNumArr[i]) {
				if (i == k - 1) {
					Addition(firstNumArr, secondNumArr, added, n - 1);
					addMinusInfront(added, k);
					subtracted[0] = '0';
				}
				continue;
			}
			else if (firstNumArr[i] > secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, added, n - 1);
				Subtraction(firstNumArr, secondNumArr, subtracted, n - 1);
				removingZeroesInfront(added, n - 1);
				removingZeroesInfront(subtracted, n - 1);
				addMinusInfront(added, n - 1);
				addMinusInfront(subtracted, n - 1);
				break;

			}
			else if (firstNumArr[i] < secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, added, n - 1);
				Subtraction(secondNumArr, firstNumArr, subtracted, n - 1);
				removingZeroesInfront(added, n - 1);
				removingZeroesInfront(subtracted, n - 1);
				addMinusInfront(added, n - 1);
				break;
			}
		}
	}
	else if (n > k) {
		insertingZeroesInfront(firstNumArr, secondNumArr, n, k);
		Addition(firstNumArr, secondNumArr, added, k);
		Subtraction(firstNumArr, secondNumArr, subtracted, k);
		removingZeroesInfront(added, k);
		removingZeroesInfront(subtracted, k);
		addMinusInfront(added, k);
		addMinusInfront(subtracted, k);
	}
	else if (n < k) {
		insertingZeroesInfront(firstNumArr, secondNumArr, n, k);
		Addition(firstNumArr, secondNumArr, added, k);
		Subtraction(secondNumArr, firstNumArr, subtracted, k - 1);
		removingZeroesInfront(added, k);
		removingZeroesInfront(subtracted, k);
		addMinusInfront(added, k);
		addMinusInfront(subtracted, k);
	}
}
void BothNumbersArePositive(unsigned short n, unsigned short k, char firstNumArr[], char secondNumArr[], char subtracted[], char added[]) {
	if (n != k)
		insertingZeroesInfront(firstNumArr, secondNumArr, n, k);
	if (n > k) {
		Addition(firstNumArr, secondNumArr, added, n);
		Subtraction(firstNumArr, secondNumArr, subtracted, n);
		removingZeroesInfront(added, n);
		removingZeroesInfront(subtracted, n);
	}
	else if (n < k)
	{
		Addition(firstNumArr, secondNumArr, added, k);
		Subtraction(secondNumArr, firstNumArr, subtracted, k);
		removingZeroesInfront(added, k);
		removingZeroesInfront(subtracted, k);
		addMinusInfront(subtracted, k);
	}
	else {
		for (size_t i = 0; i < n; i++)
		{
			if (firstNumArr[i] == secondNumArr[i]) {
				if (i == n - 1) {
					Addition(firstNumArr, secondNumArr, added, n);
					subtracted[0] = '0';
				}
				continue;
			}
			if (firstNumArr[i] > secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, added, n);
				Subtraction(firstNumArr, secondNumArr, subtracted, n);
				removingZeroesInfront(added, n);
				removingZeroesInfront(subtracted, n);
				break;
			}
			else if (firstNumArr[i] < secondNumArr[i]) {
				Addition(firstNumArr, secondNumArr, added, k);
				Subtraction(secondNumArr, firstNumArr, subtracted, k);
				removingZeroesInfront(added, k);
				removingZeroesInfront(subtracted, k);
				addMinusInfront(subtracted, k);
				break;
			}
		}
	}
}
void operationsWithLargeNumbers(char firstNumArr[], char secondNumArr[], unsigned short n, unsigned short k, char added[], char subtracted[])
{
	if (firstNumArr[0] == '-' && secondNumArr[0] != '-') {
		FirstNumberIsNegativeAndSecondPositive(n, k, firstNumArr, secondNumArr, subtracted, added);
	}
	else if (firstNumArr[0] != '-' && secondNumArr[0] == '-') {
		FirstNumberIsPositiveAndSecondNegative(n, k, firstNumArr, secondNumArr, subtracted, added);
	}
	else if (firstNumArr[0] == '-' && secondNumArr[0] == '-') {
		BothNumbersAreNegative(n, k, firstNumArr, secondNumArr, subtracted, added);
	}
	else {
		BothNumbersArePositive(n, k, firstNumArr, secondNumArr, subtracted, added);
	}

}
void printArr(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
unsigned myStrlen(const char* str)
{
	unsigned count = 0;
	while ((*str >= '0' && *str <= '9') || *str == '-')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	unsigned short n, k;
	char firstNumArr[SIZE], secondNumArr[SIZE], added[SIZE], subtracted[SIZE];
	cin >> n >> firstNumArr >> k >> secondNumArr;
	if (firstNumArr[0] != '-' && secondNumArr[0] == '-') {
		if (myStrlen(secondNumArr) != k + 1) {
			cout << -1;
			return 0;
		}
	}
	else if (firstNumArr[0] == '-' && secondNumArr[0] != '-') {
		if (myStrlen(firstNumArr) != n + 1) {
			cout << -1;
			return 0;
		}
	}
	else if (firstNumArr[0] == '-' && secondNumArr[0] == '-') {
		if (myStrlen(firstNumArr) != n || myStrlen(secondNumArr) != k) {
			cout << -1;
			return 0;
		}
	}
	else if ((n < 1 || n>1024 || k < 1 || k>1024) || (myStrlen(firstNumArr) != n || myStrlen(secondNumArr) != k)) {
		cout << -1;
		return 0;
	}
	operationsWithLargeNumbers(firstNumArr, secondNumArr, n, k, added, subtracted);
	int finalSizeOfAddition = myStrlen(added);
	int finalSizeOfSubtraction = myStrlen(subtracted);
	printArr(added, finalSizeOfAddition);
	printArr(subtracted, finalSizeOfSubtraction);
}
