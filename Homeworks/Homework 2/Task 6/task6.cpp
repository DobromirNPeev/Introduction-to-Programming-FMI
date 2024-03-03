/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 6
*
*/
#include <iostream>

const unsigned SIZE = 1024;
const unsigned INTMAXVALUE = 2147483648;
using namespace std;

int Length(int input) {
	if (input == 0) {
		return 1;
	}
	int length = 0;
	while (input != 0) {
		length++;
		input /= 10;
	}
	return length;
}
void reverseArray(int input,int arr[]) {
	int length = Length(input);
	for (int i = 0; i < length / 2; i++)
	{
		swap(arr[i], arr[length - 1 - i]);
	}
}
bool isItPalindrom(const int arr[],int input) {
	int length = Length(input);
	int leftPart[SIZE];
	int rightPart[SIZE];
	for (int i = 0; i < length/2; i++)
	{
		leftPart[i] = arr[i];
	}
	int index = 0;
	if (length % 2 == 0) {
		for (int i = length / 2; i < length; i++)
		{
			rightPart[index] = arr[i];
			index++;
		}
	}
	else {
		for (int i = length / 2+1; i < length; i++)
		{
			rightPart[index] = arr[i];
			index++;
		}
	}
	reverseArray(length/2, rightPart);
	for (int i = 0; i < length/2; i++)
	{
		if (leftPart[i] != rightPart[i]) {
			return false;
		}
	}
	return true;
}
void copyingArr(int firstArr[], int secondArr[], int input) {
	int length = Length(input);
	for (int i = 0; i < length; i++)
	{
		secondArr[i] = firstArr[i];
	}

}
bool swapingNumbersPlace(int i,int length,int arr[],int input) {
	for (int j = i + 1; j <= length; j++)
	{
		swap(arr[i], arr[j]);
		if (isItPalindrom(arr, input)) {
			return true;
		}
	}
	return false;
}
bool isItHalfPalindrom(int input, int arr[]) {
	int length = Length(input);
	int cpyArr[SIZE];
	copyingArr(arr, cpyArr, input);
	for (int i = 0; i < length; i++)
	{
		if (swapingNumbersPlace(i, length, arr, input)) {
			return true;
		}
		copyingArr(cpyArr, arr, input);
	}
	return false;
}
bool exceptions(const int arr[], int input) {
	int length = Length(input);
	int zeroCounter = 0;
	bool onlyZeroes = true;;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] == 0) {
			zeroCounter++;
		}
		else {
			return false;
		}
	}
	if (zeroCounter % 2 == 0 && zeroCounter!=0) {
		return true;
	}
	return false;
}
void intToCharArray(int input,int arr[]) {
	int length = Length(input);
	for (int i = 0; i < length; i++)
	{
		arr[i] = input % 10;
		input /= 10;
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int PalindromAndHalfPalindromCounter(int start,int end,int count,int arr[]) {
	for (int i = start; i <= end; i++)
	{
		if (i <= 100) {
			continue;
		}
		intToCharArray(i, arr);
		reverseArray(i, arr);
		if (exceptions(arr, i)) {
			continue;
		}
		if (isItPalindrom(arr, i)) {
			count++;
		}
		else if (isItHalfPalindrom(i, arr)) {
			count++;
		}
	}
	return count;
}

int main()
{
	int start, end, count = 0;
	int arr[SIZE];
	cin >> start >> end;
	if (start < 1 || start>INTMAXVALUE || end < 1 || end>INTMAXVALUE || start > end) {
		cout << -1;
		return 0;
	}
	cout << PalindromAndHalfPalindromCounter(start, end, count, arr);
}