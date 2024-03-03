/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author <Dobromir Peev>
* @idnumber <4MI0600262>
* @task <2>
*
*/
#include <iostream>

const unsigned MAXSIZE = 255;

using namespace std;
void swap(char& a, char& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void copyingArr(char* firstArr, char* secondArr, int length) {
    for (int i = 0; i <= length; i++)
    {
        secondArr[i] = firstArr[i];
    }

}
void GettingSubString(int index,int WLength,char* currentSubString,int subStrIndex,const char* S) {
    for (size_t i = index; i < index + WLength; i++)
    {
        currentSubString[subStrIndex++] = S[i];
    }
    currentSubString[subStrIndex] = '\0';
}
void SwappingPlaces(int subStrIndex,int WLength,char* currentSubString,const char* W,int index,char* indexSafe,int& indexSafeIndex,char* cpyArr,bool& found) {
    for (int j = subStrIndex + 1; j < WLength; j++)
    {
        swap(currentSubString[subStrIndex], currentSubString[j]);
        if (!strcmp(currentSubString, W)) {
            indexSafe[indexSafeIndex++] = index + '0';
            found = true;
            return;
        }
        copyingArr(cpyArr, currentSubString, WLength);
    }
}
void CheckingForAnagrams(char* currentSubString,int WLength,const char* W,int index,char* indexSafe,int& indexSafeIndex,int subStrIndex) {
    char cpyArr[MAXSIZE];
    bool found = false;
    copyingArr(currentSubString, cpyArr, WLength);
    if (!strcmp(currentSubString, W)) {
        indexSafe[indexSafeIndex++] = index + '0';
        return;
    }
    else {
        while (currentSubString[subStrIndex] != '\0')
        {
            SwappingPlaces(subStrIndex, WLength, currentSubString, W, index,indexSafe, indexSafeIndex, cpyArr,found);
            if (found) {
                return;
            }
            subStrIndex++;
        }
    }
}
void printArr(char* indexSafe,int indexSafeIndex) {
    indexSafe[indexSafeIndex] = '\0';
    for (size_t i = 0; i < indexSafeIndex; i++)
    {
        if (i == indexSafeIndex - 1) {
            cout << indexSafe[i];
        }
        else {
            cout << indexSafe[i] << ",";
        }
    }
}
int main()
{
    char S[MAXSIZE];
    cin.getline(S, MAXSIZE);
    char W[MAXSIZE];
    cin.getline(W, MAXSIZE);
    int WLength = strlen(W);
    int index = 0,subStrIndex=0,indexSafeIndex=0;
    char indexSafe[MAXSIZE];
    while (S[index] != '\0') {
        int subStrIndex = 0;
        char currentSubString[MAXSIZE];
        GettingSubString(index, WLength, currentSubString, subStrIndex, S);
        CheckingForAnagrams(currentSubString, WLength, W, index, indexSafe, indexSafeIndex, subStrIndex);
        index++;
    }
    if (indexSafeIndex == 0) {
        cout << "\"no anagrams\"";
    }
    else {
        printArr(indexSafe, indexSafeIndex);
    }
}
