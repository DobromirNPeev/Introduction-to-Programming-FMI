/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 2
*
*/
#include <iostream>
using namespace std;

int Length(int input) {
	int length = 0;
	while (input != 0) {
		length++;
		input /= 10;
	}
	return length;
}

void Thousands(int number) {
	if (number == 1) {
		cout << "M";
	}
	else {
		cout << "MM";
	}
}
void Hundreds(int number) {
	if (number <= 3) {
		for (int i = 1; i <= number; i++)
		{
			cout << "C";
		}
	}
	else if (number == 4) {
		cout << "CD";
	}
	else if (number == 9) {
		cout << "CM";
	}
	else if (number >=5) {
		cout << "D";
		for (int i = 5; i < number; i++)
		{
			cout << "C";
		}
	}
}
void Tens(int number) {
	if (number <= 3) {
		for (int i = 1; i <= number; i++)
		{
			cout << "X";
		}
	}
	else if (number == 4) {
		cout << "XL";
	}
	else if (number == 9) {
		cout << "XC";
	}
	else if (number >= 5) {
		cout << "L";
		for (int i = 5; i < number; i++)
		{
			cout << "X";
		}
	}
}
void Ones(int number) {
	if (number <= 3) {
		for (int i = 1; i <= number; i++)
		{
			cout << "I";
		}
	}
	else if (number == 4) {
		cout << "IV";
	}
	else if (number == 9) {
		cout << "IX";
	}
	else if (number >= 5) {
		cout << "V";
		for (int i = 5; i < number; i++)
		{
			cout << "I";
		}
	}
}
int PowerOfTen(int input) {
	int powered = 1;
	for (int i = 0; i < input-1; i++)
	{
		powered *= 10;
	}
	return powered;
}

int main()
{
    int input;
    cin >> input;
	if (input < 1 || input>2000) {
		cout << "Incorrect input";
		return 0;
	}
	int length = Length(input);
	int inputCopy = input;
	for (int i = length; i >= 1; i--)
	{
		int powered = PowerOfTen(i);
		int currentNumber = inputCopy / powered;
		if (i == 4) {
			Thousands(currentNumber);
		}
		else if (i == 3) {
			Hundreds(currentNumber);
		}
		else if (i == 2) {
			Tens(currentNumber);
		}
		else {
			Ones(currentNumber);
		}
		inputCopy %= powered;
	}
}