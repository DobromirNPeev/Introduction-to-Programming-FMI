/**
*
* Solution to homework assignment 1
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
#include <cmath>
using namespace std;

bool IsItPrime(int input) {
	int rooted = sqrt(input);
	for (int j = 2; j <= rooted; j++)
	{
		if (input % j == 0) {
			return false;
		}
	}
	return true;
}

bool CheckingForEqualNumbers(int currentNum) {
	while (currentNum != 0) {
		int lastDigit = currentNum % 10;
		int currentNumCopy = currentNum / 10;
		while (currentNumCopy != 0)
		{
			int secondToLastDigit = currentNumCopy % 10;
			if (secondToLastDigit == lastDigit) {

				return false;
				break;
			}
			currentNumCopy = currentNumCopy / 10;
		}
		currentNum /= 10;
	}
	return true;
}
bool GetSpecialNumber(int input) {
	bool isItSpecial = CheckingForEqualNumbers(input);
	if (isItSpecial) {
		bool PrimeCheck = IsItPrime(input);
		if (PrimeCheck) {
			return true;
		}
	}
	return false;
}

int main()
{
    unsigned long input;
    cin >> input;
	if (input < 1 || input>1000000000) {
		cout << "Incorrect input";
		return 0;
	}
	unsigned long specialNumberLower = 0;
	unsigned long specialNumberHigher = 0;
	for (int i = input; i >= 1; i--)
	{
		if (GetSpecialNumber(i)) {
			specialNumberLower = i;
			break;
		 }
	}
	int inputCopy = input;
	while (true) {
		if (GetSpecialNumber(inputCopy)) {
			specialNumberHigher = inputCopy;
			break;
		}
		if (inputCopy - input > input - specialNumberLower) {
			break;
		}
		inputCopy++;
	}
	if (specialNumberHigher-input<input-specialNumberLower) {
		cout << specialNumberHigher;
	}
	else if (specialNumberHigher - input > input - specialNumberLower) {
		cout << specialNumberLower;
	}
	else {
		cout << specialNumberLower;
	}
}
