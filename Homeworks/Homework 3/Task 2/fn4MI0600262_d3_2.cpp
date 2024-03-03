/**
*
* Solution to homework assignment 3
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

const unsigned short SIZE= 15;

void printArr(const unsigned* arr,unsigned short n)
{
    int index = 0;
    for (int i = n-1; i >=0; i--)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
}
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
unsigned reverse(int n) {
    int reverse = 0, rem;
    while (n != 0) {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }
    return reverse;
}
void equalNumbersCase(unsigned& currentNumberLastDigit, unsigned& nextNumberLastDigit, unsigned& currentNum,unsigned* numbers, int j, unsigned& nextNumber) {
    while (currentNumberLastDigit == nextNumberLastDigit) {
        currentNum /= 10;
        nextNumber /= 10;
        if (currentNum == 0 || nextNumber == 0) {
            currentNumberLastDigit = numbers[j] % 10;
            nextNumberLastDigit = numbers[j+1] % 10;
            return;

        }
        currentNumberLastDigit = currentNum % 10;
        nextNumberLastDigit = nextNumber % 10;
    }
}
void innerBubbleSort(int n,unsigned* numbers) {
    for (size_t j = 0; j < n - 1; j++)
    {
        unsigned currentNum = reverse(numbers[j]);
        unsigned currentNumberFirstDigit = currentNum% 10;
        unsigned nextNumber = reverse(numbers[j + 1]);
        unsigned nextNumberFirstDigit = nextNumber % 10;
        equalNumbersCase(currentNumberFirstDigit, nextNumberFirstDigit, currentNum, numbers, j, nextNumber);
        if (currentNumberFirstDigit >= nextNumberFirstDigit) {
            swap(numbers[j], numbers[j + 1]);
        }
    }
}
void bubbleSort(int n,unsigned* numbers) {
    for (size_t i = 0; i < n; i++)
    {
        innerBubbleSort(n, numbers);
    }
}
void init(int n,unsigned* numbers,bool& invalid) {
    for (size_t i = 0; i < n; i++)
    {
        unsigned short number;
        cin >> number;
        if (number < 1 || number>9999) {
            invalid = true;
            return;
        }
        numbers[i] = number;;
    }
}
int main()
{
    unsigned numbers[SIZE];
    bool invalid = false;
    unsigned short n;
    cin >> n;
    if (n < 1 || n>15) {
        cout << "-1";
        return 0;
    }
    init(n, numbers,invalid);
    if (invalid) {
        cout << "-1";
        return 0;
    }
    bubbleSort(n, numbers);
    printArr(numbers, n);
}