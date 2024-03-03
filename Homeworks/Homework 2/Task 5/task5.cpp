/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 5
*
*/
#include <iostream>
#include <cmath>

using namespace std;
const unsigned INTMAXVALUE = 2147483647;

bool IsItPrime(unsigned n) {
	int rooted = sqrt(n);
	if (n == 0 || n == 1)
		return false;
	for (int j = 2; j <= rooted; j++)
	{
		if (n % j == 0) {
			return false;
		}
	}
	return true;
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
int gettingFirstDigitPlace( int length) {
	int digitPlace = 1;
	for (int j = 0; j < length-1; j++)
	{
		digitPlace *= 10;
	}
	return digitPlace;
}
int firstOp(unsigned n,int firstDigit) {
	return n % firstDigit;
}
int secondOp(unsigned n) {
	return n / 100;
}
int checkingForMinValue(int count,int min) {
	if (count < min) {
		min = count;
		count = 0;
	}
	return min;
}
int applyingOnlyFirstOp(int& nMask,int count,bool& impossibleToBecomePrime,int min,int n) {
	while (nMask != 0) {
		int firstDigitRemove = gettingFirstDigitPlace(Length(nMask));
		if (IsItPrime(secondOp(nMask)) || IsItPrime(firstOp(nMask, firstDigitRemove)))
		{
			count++;
			break;
		}
		nMask = secondOp(nMask);
		if (nMask == 0) {
			min = -1;
			impossibleToBecomePrime = true;
			break;
		}
		count++;
	}
	nMask = n;
	return checkingForMinValue(count, min);
}
int  applyingOnlySecondOp(int& nMask, int count, bool& impossibleToBecomePrime, int min,int n) {
	while (nMask != 0) {
		if (impossibleToBecomePrime) {
			return -1;
		}
		int firstDigitRemove = gettingFirstDigitPlace(Length(nMask));
		if (IsItPrime(secondOp(nMask)) || IsItPrime(firstOp(nMask, firstDigitRemove)))
		{
			count++;
			break;
		}
		nMask = firstOp(nMask, firstDigitRemove);
		if (nMask == 0) {
			min = -1;
			impossibleToBecomePrime = true;
			break;
		}
		count++;
	}
	nMask = n;
	return checkingForMinValue(count, min);
}
int applyingBothOperations(int& nMask, int count, bool& impossibleToBecomePrime, int min, int n) {
	while (nMask != 0) {

		int firstDigitRemove = gettingFirstDigitPlace(Length(nMask));
		if (IsItPrime(secondOp(nMask)) || IsItPrime(firstOp(nMask, firstDigitRemove)))
		{
			count++;
			break;
		}
		nMask = secondOp(nMask);
		nMask = firstOp(nMask, firstDigitRemove);
		if (nMask == 0) {
			min = -1;
			impossibleToBecomePrime = true;
			break;
		}
		count++;
	}
	return checkingForMinValue(count, min);
}
int CheckingAllCasesOfApplyingOps(int& nMask, int count, bool& impossibleToBecomePrime, int min, int n) {
	min = applyingOnlyFirstOp(nMask, count, impossibleToBecomePrime, min, n);
	min = applyingOnlySecondOp(nMask, count, impossibleToBecomePrime, min, n);
	min = applyingBothOperations(nMask, count, impossibleToBecomePrime, min, n);
	return min;
}
int main()
{
	unsigned n, count = 0;
	int min = INTMAXVALUE;
	cin >> n;
	if (n < 1 || n>1000000000) {
		cout << -2;
		return 0;
	}
	int nMask = n;
	bool isPrime = false,impossibleToBecomePrime=false;
		isPrime = IsItPrime(n);
		if (isPrime) {
			cout<< 0;
		}
		else {
			 cout<< CheckingAllCasesOfApplyingOps(nMask, count, impossibleToBecomePrime, min, n);
		}
}