/**
*
* Solution to homework assignment 2
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

const unsigned SIZE = 1000;

using namespace std;
void printArr(const int arr[])
{
	int index = 0;
	while (arr[index] != 0)
	{
		cout << arr[index];
		index++;
	}
	cout << endl;
}

void CheckingWhileNumberToTheRightIsDifferent(int currentNum, int arr[], int& index, int& count) {
	while (currentNum == arr[index + 1]) {
		count++;
		index++;
	}
}
void currentIterModification(int arr[], int index, int modArr[], int modIndex) {
	while (arr[index] > 0)
	{
		int count = 1;
		int currentNum = arr[index];
		CheckingWhileNumberToTheRightIsDifferent(currentNum, arr, index, count);
		modArr[modIndex] = count;
		modArr[modIndex + 1] = currentNum;
		modIndex += 2;
		index++;
	}
}
void modifyingOriginalArray(const int modArr[], int index, int arr[], unsigned& counter) {
	counter = 0;
	while (modArr[index] > 0) {
		arr[index] = modArr[index];
		index++;
		counter++;
	}
}
int main()
{
	unsigned n, counter = 1;
	int arr[SIZE], modArr[SIZE];
	arr[0] = 1;
	cin >> n;
	if (n < 1 || n>20) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int index = 0;
		int modIndex = 0;
		currentIterModification(arr, index, modArr, modIndex);
		modifyingOriginalArray(modArr, index, arr, counter);
	}
	arr[counter] = 0;
	printArr(arr);
}