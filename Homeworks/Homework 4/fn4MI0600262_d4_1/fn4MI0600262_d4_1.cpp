#include <iostream>

const unsigned short MAXSIZE = 255;
using namespace std;

bool CheckForParenthesis(const char* input,int& index,int& leftParenthesisCounter,int& rightParenthesisCounter) {
    if (input[index] == '(') {
        leftParenthesisCounter++;
        index++;
        return true;
    }
    else if (input[index] == ')' && leftParenthesisCounter != 0) {
        rightParenthesisCounter++;
        index++;
        return true;
    }
    return false;
}
int main()
{
    char input[MAXSIZE];
    int leftParenthesisCounter = 0,rightParenthesisCounter=0;
    cin.getline(input,MAXSIZE);
    int index = 0;
    if (input[254] == '\0') {
        cout << "wrong input";
        return 0;
    }
    while (input[index] != '\0') {
        if (!CheckForParenthesis(input,index,leftParenthesisCounter,rightParenthesisCounter)) {
            index++;
        }
    }
    if (leftParenthesisCounter == rightParenthesisCounter && (leftParenthesisCounter!=0 && rightParenthesisCounter!=0)) {
        cout << "correct";
    }
    else {
        cout << "incorrect";
    }
}