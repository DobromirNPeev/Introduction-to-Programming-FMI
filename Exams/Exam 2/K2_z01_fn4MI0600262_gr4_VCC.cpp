// Dobromir Peev 4MI0600262

#include <iostream>
using namespace std;
void zeroesAndOnesCount(int& onesCounter, int& zeroesCounter, int remainder) {
    if (remainder == 0) {
        zeroesCounter++;
    }
    else {
        onesCounter++;
    }
}
unsigned reverse(int input) {
    int res = 1;
    while (input != 1) {
        int rem = input % 10;
        res = res * 10 + rem;
        input /= 10;
    }
    return res;
}
unsigned FromDecimalToBinary(int input,int& onesCounter, int& zeroesCounter) {
    if (input == 0)
        return 0;
    unsigned result = 1;
    while (input != 1) {
        int remainder = input % 2;
        zeroesAndOnesCount(onesCounter, zeroesCounter, remainder);
        result = result * 10 + remainder;
        input /= 2;
    }
    return reverse(result);
}

int main()
{
    int input, onesCounter=1, zeroesCounter = 0;
    cin >> input;
    cout << FromDecimalToBinary(input, onesCounter, zeroesCounter) << endl;
    cout<< onesCounter << " " << zeroesCounter;
}
