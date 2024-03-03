//Dobromir Peev 4MI0600262
#include <iostream>;
#pragma once
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void squareArr(int* arr, size_t len) {
	for (size_t i = 0; i < len - 1; i++)
	{
		if (arr[i] >= arr[i + 1]) {
			return;
		}
	}
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = i + 1; j < len; j++)
		{
			if (arr[i] == arr[j]) {
				return;
			}
		}
	}
	for (size_t i = 0; i < len; i++)
	{
		arr[i] *= arr[i];
	}
	for (size_t i = 0; i < len - 1; i++)
	{
		for (size_t j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

bool isNum(char ch) {
	return ch >= '0' && ch <= '9';
}
int strLength(char* str) {
	int len = 0;
	while (*str != '\0') {
		len++;
		str++;
	}
	return len;
}
bool isNum9(char ch) {
	return ch >= '0' && ch <= '8';
}
// 1 3 5 7 8 10 12
// 2 4 6 9 11
int CheckDate(char* str) {
	int len = strLength(str);
	if (str == NULL || strLength(str) < 0 || len > 10) {
		return -1;
	}
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] != '.' && (i == 2 || i == 5)) {
			return 0;
		}
		else if (!isNum(str[i]) && (i != 2 && i != 5)) {
			return 0;
		}
	}
	int count = 0;
	int months = 0;
	months += str[3] - '0';
	months *= 10;
	months += str[4] - '0';
	int year = 0;
	for (size_t i = 6; i < 10; i++)
	{
		(year *= 10) += str[i] - '0';
	}
	bool isLeap = (year % 4 == 0 || year % 400 == 0);
	while (*str != '\0') {
		if ((*str != '0' && *str != '1') && count == 3) {
			return 0;
		}
		else if ((*str != '1' && *str != '2') && count == 4) {
			return 0;
		}
		else if (!isNum(*str) && (count >= 6 || count <= 9)) {
			return 0;
		}
		else if ((*str != '0' && *str != '1' && *str != '2') && months == 2 && count == 0) {
			return 0;
		}
		else if ((*str != '0' && *str != '1' || *str != '2' && *str != '3') && months == 2 && count == 0) {
			return 0;
		}
		else if ((*str != '0' && *str != '1') && count == 1 && months == 2) {
			return 0;
		}
		else if ((*str != '0' && *str != '1' || *str != '2') && months == 2 && count == 0) {
			return 0;
		}
		else if (months != 2 && isLeap && (!isNum(*str)) && count == 1) {
			return 0;
		}
		else if (months != 2 && !isLeap && (!isNum9(*str)) && count == 1) {
			return 0;
		}
		str++;
		count++;
	}
	return 1;
}
//1234 2 4
int getLength(long N) {
	if (N == 0) {
		return 1;
	}
	int len = 0;
	while (N != 0) {
		len++;
		N /= 10;
	}
	return len;
}
int reverse(long N) {
	int rev = 0;
	while (N != 0) {
		(rev *= 10) += N % 10;
		N /= 10;
	}
	return rev;
}
//1234 -> 1432 2 4 4321
int powerTen(unsigned m) {
	int power = 1;
	for (size_t i = 0; i < m; i++)
	{
		power *= 10;
	}
	return power;
}
int checkNum(long N, unsigned int m, unsigned l) {
	int len = getLength(N);
	if (m<0 || l<0 || m>len || l>len || N > powerTen(9)) {
		return -1;
	}
	int* arr = new int[len];
	long revN = reverse(N);
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = revN % 10;
		revN /= 10;
	}
	swap(arr[m - 1], arr[l - 1]);
	int newNum = 0;
	for (size_t i = 0; i < len; i++)
	{
		(newNum *= 10) += arr[i];
	}
	delete[] arr;
	int rem = newNum / 4;
	//example
	//if (newNum % 4 == 0) {
	//	return 1;
	//}
	//else {
	//	return 0;
	//}
	if (rem * 4 == newNum) {
		return 1;
	}
	else {
		return 0;
	}
}