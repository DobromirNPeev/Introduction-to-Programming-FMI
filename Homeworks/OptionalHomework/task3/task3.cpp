#include <iostream>
using namespace std;
int main()
{
    int input;
    cin >> input;
    int copyOfInput = input, count = 0;
    while (copyOfInput != 0) {
        count++;
        copyOfInput /= 10;
    }
    copyOfInput = input;
    int newN = 0;
    if (count % 2 == 0)
    {
        int multiplying = 1;
        for (int i = 0; i < count / 2 - 1; i++)
        {
            newN += (copyOfInput % 10) * multiplying;
            copyOfInput /= 10;
            multiplying *= 10;
        }
        copyOfInput /= 100;
        for (int i = 0; i < count / 2 - 1; i++)
        {
            newN += (copyOfInput % 10) * multiplying;
            copyOfInput /= 10;
            multiplying *= 10;
        }
        cout << ++newN;
    }
    else {
        int multiplying = 1;
        for (int i = 0; i < count / 2; i++)
        {
            newN += (copyOfInput % 10) * multiplying;
            copyOfInput /= 10;
            multiplying *= 10;
        }
        copyOfInput /= 10;
        for (int i = 0; i < count / 2; i++)
        {
            newN += (copyOfInput % 10) * multiplying;
            copyOfInput /= 10;
            multiplying *= 10;
        }
        cout << ++newN;
    }
}