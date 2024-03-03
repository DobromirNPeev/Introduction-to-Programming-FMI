/**
*
* Solution to homework assignment 3
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
const unsigned MAXSIZE = 1024;
void crypting(char key, char* string) {
    while (*string != '\0') {
        *string=*string ^ key;
        string++;
    }
}

int main()
{
    char key;
    char string[MAXSIZE];
    if (strlen(string) > 1024) {
        cout << "invalid";
        return 0;
    }
    cin >> key >> string;
    crypting(key, string);
    cout << string;
}