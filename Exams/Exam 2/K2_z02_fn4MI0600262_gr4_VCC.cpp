// Dobromir Peev 4MI0600262
#include <iostream>

const unsigned MAXSIZE = 1024;
const int intDefaultValue=-858993460;
using namespace std;

bool doesItDivideInput(unsigned input, unsigned number,int numbers[]) {
    int index = 0;
    while (numbers[index] != intDefaultValue) {
        if (input % number == 0 || number%numbers[index]==0) {
            return true;
        }
        index++;
    }
    return false;
}
bool isItDivisibleByInput(unsigned input, unsigned number, int numbers[]) {
    int index = 0;
    while (numbers[index] != intDefaultValue) {
        if (number%input == 0 || numbers[index]%number == 0) {
            return true;
        }
        index++;
    }
    return false;
}
void loopingThroughNumbers(int input, int n,int numbers[]) {
    int index = 0;
    for (unsigned i = 2; i <= n; i++)
    {
        if (!isItDivisibleByInput(input, i,numbers) && !doesItDivideInput(input,i,numbers)) {
            numbers[index]=i;
            index++;
        }
    }
}
void printArr(int numbers[]) {
    int index = 0;
    while(numbers[index]!=intDefaultValue)
    {
        cout << numbers[index] <<" ";
        index++;
    }
}
int main()
{
    unsigned n,input;
    int numbers[MAXSIZE];
    cin >> n>>input;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }
        loopingThroughNumbers(input, n, numbers);
    }
    printArr(numbers);
}