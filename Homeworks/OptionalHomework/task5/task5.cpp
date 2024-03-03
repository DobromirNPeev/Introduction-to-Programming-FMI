#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int copyOfNumber = number;
    bool isThePowerOf2 = false;
    if (copyOfNumber == 1) {
        isThePowerOf2 = true;
        cout << isThePowerOf2;
        return 0;
    }
    while (copyOfNumber != 0) {
        if (copyOfNumber % 2 == 0) {
            isThePowerOf2 = true;
        }
        else {
            isThePowerOf2 = false;
            break;
        }
        copyOfNumber /= 2;
        if (copyOfNumber == 1) {
            break;
        }
    }
    cout << isThePowerOf2;
}