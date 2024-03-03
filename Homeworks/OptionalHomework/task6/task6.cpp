#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    for (int i = -100; i <= 100; i++)
    {
        int fx = (a * i * i * i * i) + (b * i * i * i) + (c * i * i) + (d * i) + e;
        if (fx >= 0) {
            cout << i << " ";
        }
    }
}