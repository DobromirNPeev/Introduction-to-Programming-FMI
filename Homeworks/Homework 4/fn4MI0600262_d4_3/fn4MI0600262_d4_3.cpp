#include <iostream>

const int MAXSIZE = 50;
using namespace std;

bool IsItANumber(char mask) {
	return mask >= '0' && mask <= '9';
}
void swap(char*& a, char*& b)
{
	char* temp = a;
	a = b;
	b = temp;
}
bool comparePositives(char* current,char* next) {
	while (*current != '\0' || *next != '\0') {
		if (*current > *next) {
			return true;
		}
		else if (*current < *next) {
			return false;
		}
		else {
			current++;
			next++;
		}
	}
	return false;
}

bool compareNegatives(char* current, char* next) {
	while (*current != '\0' || *next != '\0') {
		if (*current < *next) {
			return true;
		}
		else if (*current > *next) {
			return false;
		}
		else {
			current++;
			next++;
		}
	}
	return false;
}
void movingNumberToTheRight(unsigned short n, char arr[]) {
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
}
void removingZeroesInfront(char* arr, unsigned short n) {
	while (arr[0] == '0') {
		//movingNumberToTheRight(n, arr);
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}
void addOneZeroInfront(char* current,int length) {
	for (int i = length; i >= 0; i--)
	{
		current[i + 1] = current[i];
	}
	current[0] = '0';
}
int GettingLengthBeforeFloatingPoint(char* input) {
	int index = 0;
	while (input[index] != '.' && input[index] != '\0') {
		index++;
	}
	if(input[index] == '\0') {
		return index;
	}
	return index-1;
}
bool IsItDouble(char* current,int index,int pointCounter) {
	while (current[index] != '\0') {
		if (current[index] == ',' || current[index] == '.') {
			pointCounter++;
			if (pointCounter > 1) {
				return false;
			}
		}
		if (!IsItANumber(current[index]) && current[index] != ',' && current[index] != '.' && current[0] != '-') {
			return false;
		}
		index++;
	}
	return true;
}
void AddingCurrentNumber(int length,char* current,char doubles[MAXSIZE][MAXSIZE], int place) {
	for (size_t i = 0; i <= length; i++)
	{
		doubles[place][i] = current[i];
	}
	doubles[place][length] = '\0';
}
void BubbleSort(int place,char doubles[MAXSIZE][MAXSIZE]) {
	for (size_t i = 0; i < place - 1; i++)
	{
		for (size_t j = 0; j < place - 1-i; j++)
		{
			if (doubles[j][0] == '-' && doubles[j + 1][0] == '-') {
				if (GettingLengthBeforeFloatingPoint(doubles[j]) < GettingLengthBeforeFloatingPoint(doubles[j + 1])) {
					swap(doubles[j], doubles[j + 1]);
				}
				else if (GettingLengthBeforeFloatingPoint(doubles[j]) > GettingLengthBeforeFloatingPoint(doubles[j + 1])) {
					continue;
				}
				else if (compareNegatives(doubles[j], doubles[j + 1])) {
					swap(doubles[j], doubles[j + 1]);
				}
			}
			else if (doubles[j][0] != '-' && doubles[j + 1][0] == '-') {
				swap(doubles[j], doubles[j + 1]);
			}
			else if (doubles[j][0] == '-' && doubles[j + 1][0] != '-') {
				continue;
			}
			else if (GettingLengthBeforeFloatingPoint(doubles[j]) > GettingLengthBeforeFloatingPoint(doubles[j + 1])) {
				swap(doubles[j], doubles[j + 1]);
			}
			else if (GettingLengthBeforeFloatingPoint(doubles[j]) < GettingLengthBeforeFloatingPoint(doubles[j + 1])) {
				continue;
			}
			else if (comparePositives(doubles[j], doubles[j + 1])) {
				swap(doubles[j], doubles[j + 1]);
			}
		}
	}
}
void printMatrix(int place,char doubles[MAXSIZE][MAXSIZE]) {
	for (size_t i = 0; i < place; i++)
	{
		int length = strlen(doubles[i]);
		for (size_t j = 0; j < length; j++)
		{
			cout << doubles[i][j];
		}
		cout << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	char doubles[MAXSIZE][MAXSIZE];
	int place = 0,pointCounter=0;
	for (size_t i = 0; i < n; i++)
	{
		char current[MAXSIZE];
		cin.getline(current, MAXSIZE);
		int index = 0;
		bool isItValid = IsItDouble(current, index, pointCounter);
		if (isItValid) {
			removingZeroesInfront(current, strlen(current));
			if (current[0] == '.') {
				addOneZeroInfront(current, strlen(current));
			}
			int length = strlen(current);
			AddingCurrentNumber(length, current, doubles, place);
			place++;
		}
	}
	if (place == 0) {
		cout << "no valid numbers";
		return 0;
	}
	BubbleSort(place, doubles);
	printMatrix(place, doubles);
}
