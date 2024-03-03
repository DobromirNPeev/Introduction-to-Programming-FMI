/**
*
* Solution to homework assignment 3
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

const unsigned short SIZE = 10000000;
const unsigned short STEP = 8;
using namespace std;

void insertingZeroesInfront(char input[], unsigned short n, unsigned short k,int binInd) {
		int diff = n - k;
		if (diff == 0) {
			return;
		}
		for (int i = k+binInd; i >= binInd; i--)
		{
			input[i + diff] = input[i];
		}
		for (int i = binInd; i < binInd+diff; i++)
		{
			input[i] = '0';
		}
}
unsigned int toBinaryFromDecimal(unsigned int n)
{
	int result = 0;
	int mult = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			result += mult;
		mult *= 10;
		n /= 2;
	}
	return result;
}
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
void intToCharArray(int input, char arr[],int length,int binInd) {
	for (int i = length-1; i >= binInd; i--)
	{
		arr[i] = input % 10+'0';
		input /= 10;
	}
}
unsigned int fromBinaryToDecimal(unsigned int n)
{
	unsigned int result = 0;
	unsigned int mult = 1; //2^0
	while (n != 0)
	{
		result += ((n % 10) * mult);
		mult *= 2;
		n /= 10;
	}
	return result;
}
bool AllZeroesCheckerByThree(int binVerIndex,const char* binaryVersion) {
	for (size_t i = binVerIndex; i < binVerIndex + 3; i++)
	{
		if (binaryVersion[i] != '0' && (binaryVersion[i] == '0' || binaryVersion[i] == '1')) {
			return false;
			break;
		}
	}
	return true;
}
bool zeroesCheckerCharCase(char* arr, int index, int& twoZeroesInARow) {

	if (arr[index] == 0) {
		twoZeroesInARow++;
	}
	else {
		twoZeroesInARow = 0;
	}
	if (twoZeroesInARow != 2) {
		return true;
	}
	return false;
}
bool isItAllZeroes(int binVerIndex, char* binaryVersion) {
	bool isItZero = true;
	int zeroCounter = 0;
	while (zeroCounter != 2 && (binaryVersion[binVerIndex] == '0' || binaryVersion[binVerIndex] == '1'))
	{
		isItZero = AllZeroesCheckerByThree(binVerIndex, binaryVersion);
		binVerIndex += 3;
		if (isItZero) {
			zeroCounter++;
		}
		else {
			isItZero = true;
			zeroCounter = 0;
		}
	}
	if (zeroCounter==2) {
		return true;
	}
	return false;
}
void convertingToBinary(char* binaryVersion,int binaryVerIndex) {
	int twoZeroesInARow = 0;
	while (twoZeroesInARow != 1) {
		int number;
		cin >> number;
		number = toBinaryFromDecimal(number);
		int length = Length(number);
		intToCharArray(number, binaryVersion, length + binaryVerIndex, binaryVerIndex);
		insertingZeroesInfront(binaryVersion, 8, length, binaryVerIndex);
		if (isItAllZeroes(binaryVerIndex, binaryVersion)) {
			break;
		}
		binaryVerIndex += STEP;
	}
}
bool zeroesCheckerIntCase(int* arr, int index, int& twoZeroesInARow) {

	if (arr[index] == 0) {
		twoZeroesInARow++;
	}
	else {
		twoZeroesInARow = 0;
	}
	if (twoZeroesInARow != 2) {
		return true;
	}
	return false;
}
int fromCharacterNumberToIntNumber(int index,char* binaryVersion,bool& terminatingZeroFound,int currentNum,int mult) {
	for (size_t i = index; i < index + 3; i++)
	{
		if (binaryVersion[i] == '\0') {
			terminatingZeroFound = true;
			break;
		}
		int currentEl = binaryVersion[i] - '0';
		currentEl *= mult;
		currentNum += currentEl;
		mult /= 10;
	}
	return currentNum;

}
void SeparatingByThree(char* binaryVersion,int* numbers) {
	int index = 0;
	int twoZeroesInARow = 0, numbersInd = 0;
	bool terminatingZeroFound = false;
	while (zeroesCheckerIntCase(numbers,numbersInd,twoZeroesInARow) && !terminatingZeroFound)
	{
		int currentNum = 0, mult = 100;
		currentNum=fromCharacterNumberToIntNumber(index, binaryVersion, terminatingZeroFound, currentNum, mult);
		if (terminatingZeroFound) {
			break;
		}
		index += 3;
		numbers[numbersInd++] = currentNum;
	}
}
void convertingFromBinaryToDecimal(int* numbers,int& numbersInd) {
	int twoZeroesInARow = 0;
	while (zeroesCheckerIntCase(numbers,numbersInd,twoZeroesInARow)) {
			numbers[numbersInd++] = fromBinaryToDecimal(numbers[numbersInd]);
	}
}
bool Validation(int* numbers,int numbersInd,int width) {
	int numbersInt = 0,sum=0;
	for (size_t i = 0; i < numbersInd; i++)
	{
		sum += numbers[i];
	}
	if (sum % width == 0) {
		return true;
	}
	return false;
}
void outOfDiffCharacters(int currentNumber,int& rowCounter,int width,int& numbersInd,char character) {
	for (size_t i = 0; i < currentNumber; i++)
	{
		cout << character;
		rowCounter++;
		if (rowCounter % width == 0) {
			cout << endl;
		}
	}
	numbersInd++;
}
void output(int* numbers,int width) {
	int rowCounter = 0,twoZeroesInARow=0,numbersInd=0;
	while (zeroesCheckerIntCase(numbers, numbersInd, twoZeroesInARow))
	{
		int currentNumber = numbers[numbersInd];
		char ch = '.';
		if (numbersInd % 2 == 0) {
			ch = '.';
			outOfDiffCharacters(currentNumber, rowCounter, width, numbersInd, ch);
		}
		else {
			ch = '#';
			outOfDiffCharacters(currentNumber, rowCounter, width, numbersInd, ch);
		}
	}
}
int main()
{
	int width;
	char binaryVersion[SIZE];
	int numbers[SIZE];
	unsigned binaryVerIndex = 0;
	cin >> width;
	int twoZeroesInARow = 0,numbersInd=0;
	convertingToBinary(binaryVersion, binaryVerIndex);
	SeparatingByThree(binaryVersion, numbers);
	convertingFromBinaryToDecimal(numbers,numbersInd);
	if (Validation(numbers, numbersInd, width)) {
		output(numbers, width);
	}
	else {
		cout << "Invalid input";
		return 0;
	}
}
