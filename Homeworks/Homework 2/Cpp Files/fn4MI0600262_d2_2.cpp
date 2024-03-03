/**
*
* Solution to homework assignment 2
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
bool CompareDoubles(double A, double B)
{
	double diff = A - B;
	return (diff < 0.000000000001) && (-diff < 0.000000000001);
}

int main()
{
	const double RofEyes = 2.0;
	const double ROfNose = 1.0;
	const double LeftEyex0 = -4.0;
	const double RightEyex0 = 4.0;
	const double y0 = 4.0;
	const double squareSide = 10.0;
	const double rectangleSideA = 5.0;
	const double rectangleSideB = -5.0;
	double x, y;
	cin >> x >> y;
	double distanceToTheCenter = (x * x) + (y * y);
	double leftEyeFormula = ((x - LeftEyex0) * (x - LeftEyex0)) + ((y - y0) * (y - y0));
	double rightEyeFormula = ((x - RightEyex0) * (x - RightEyex0)) + ((y - y0) * (y - y0));
	bool isItAMiss = x > squareSide && y > squareSide;
	bool isItInAnyOfTheEyes = leftEyeFormula < RofEyes* RofEyes || rightEyeFormula < RofEyes* RofEyes;
	bool isItInTheNose = distanceToTheCenter < ROfNose;
	bool isItInTheMouth = (x > -rectangleSideA && x < rectangleSideA) && (y < rectangleSideB + 1.0 && y>rectangleSideB - 1.0);
	bool isItOnTheBorder = CompareDoubles(distanceToTheCenter, squareSide) || CompareDoubles(leftEyeFormula, RofEyes * RofEyes) || CompareDoubles(rightEyeFormula, RofEyes * RofEyes) || CompareDoubles(distanceToTheCenter, ROfNose) || ((CompareDoubles(x, rectangleSideA) || (CompareDoubles(x, -rectangleSideA)) && (CompareDoubles(y, rectangleSideB + 1.0) || CompareDoubles(y, rectangleSideB - 1.0))));
	bool isItOnTheBackground = distanceToTheCenter > squareSide * squareSide;
	if (isItAMiss) {
		cout << "Miss";
	}
	else {
		if (isItInAnyOfTheEyes) {
			cout << "Eye";
		}
		else if (isItInTheNose) {
			cout << "Nose";
		}
		else if (isItInTheMouth) {
			cout << "Mouth";
		}
		else if (isItOnTheBorder) {
			cout << "Border";
		}
		else if (isItOnTheBackground) {
			cout << "Background";
		}
		else {
			cout << "Face";
		}
	}
}