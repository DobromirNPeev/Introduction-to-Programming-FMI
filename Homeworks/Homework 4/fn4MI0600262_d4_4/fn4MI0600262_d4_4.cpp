/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author <Dobromir Peev>
* @idnumber <4MI0600262>
* @task <4>
*
*/
#include <iostream>

using namespace std;

int gcd(int n,int m) {
    if (n < m)
    {
        int temp = n;
        n = m;
        m = temp;
    }

    while (m != 0)
    {
        int mod = n % m;
        n = m;
        m = mod;
    }
    return n;
}
void swap(int& n,int& m) {
    int temp = m;
    m = n;
    n = temp;
}
bool FirstBasinIsEmpty(int& firstBasin,int& secondBasin,int n,int m,int& steps,int k,bool& IsItDone) {
    firstBasin += n - (m - secondBasin);
    secondBasin = m;
    steps += 2;
    if (firstBasin == k) {
        return true;
    }
    return false;
}
void SecondBasinIsFull(int& secondBasin,int& steps) {
        secondBasin = 0;
        steps++;
}
void PouringFromFirstBasinToTheSecond(int& firstBasin,int& secondBasin,int& m,int& steps) {
    if (firstBasin > m) {
        firstBasin = firstBasin - m;
        secondBasin = m;
    }
    else {
        secondBasin = firstBasin;
        firstBasin = 0;
    }
    steps++;
}
int main()
{
    int n, m, k, steps = 0, firstBasin = 0, secondBasin = 0;
    bool IsItDone = false;
    cin >> n >> m >> k;
    int gcdOfNandM = gcd(n,m);
    if (n == k || m == k) {
        cout << "1";
        return 0;
    }
    if ((n < k && m < k) || (k % gcdOfNandM != 0)) {
        cout << "-1";
        return 0;
    }
    if (m > n) {
        swap(n, m);
    }
    while (true) {
        if (firstBasin == 0) {
            if (FirstBasinIsEmpty(firstBasin, secondBasin, n, m, steps, k, IsItDone)) {
                break;
            }
        }
        if (secondBasin == m) {
            SecondBasinIsFull(secondBasin, steps);
            continue;
        }
        PouringFromFirstBasinToTheSecond(firstBasin, secondBasin, m, steps);
    }
	cout << steps;
}