/**
*
* Solution to homework assignment 1
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

int Length(int input) {
    int length = 0;
    while (input != 0) {
        length++;
        input /= 10;
    }
    return length;
}
int placeSearcher(int digitPlace,int length) {
    for (int j = 0; j < length; j++)
    {
        digitPlace *= 10;
    }
    return digitPlace;
}
int main()
{
    int input;
    cin >> input;
    if (input < 1 || input>1000000) {
        cout<<"Incorrect input";
        return 0;
    }
    int inputLength = Length(input);
    int inputCopy = input;
    int newNumber = 0;
    int newNumberCopy = newNumber;
    for (int i = 1; i <= inputLength; i++)
    {
        int currentDigit = inputCopy % 10;
        inputCopy /= 10;
        currentDigit *= currentDigit;
        int digitPlace = 1;
        int length = Length(newNumberCopy);
        if (i != 1) {
            digitPlace=placeSearcher(digitPlace, length);
        }
        currentDigit *= digitPlace;
        newNumber += currentDigit;
        newNumberCopy = newNumber;
    }
    int length = Length(newNumberCopy);
    int reversed = 0;
    int digitPlace = 1;
    for (int i = length-1; i >=0 ; i--)
    {
        int digitPlaceOfOriginalNumber = 1;
        digitPlaceOfOriginalNumber = placeSearcher(digitPlaceOfOriginalNumber, i);      
        int currentNumber = newNumberCopy / digitPlaceOfOriginalNumber;
        currentNumber *= digitPlace;
        newNumberCopy = newNumberCopy % digitPlaceOfOriginalNumber;
        reversed += currentNumber;
        digitPlace *= 10;
    }
    cout << ++reversed;
}