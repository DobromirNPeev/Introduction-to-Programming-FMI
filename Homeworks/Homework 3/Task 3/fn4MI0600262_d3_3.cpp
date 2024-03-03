/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dobromir Peev
* @idnumber 4MI0600262
* @task 3
*
*/

#include <iostream>
#pragma warning( disable : 4996)
using namespace std;

const unsigned MAXSIZE = 1440;
const unsigned UMAXVALUE = 4294967295;

bool comparingArrivalTimes(char* currentArrivalTime, char* nextArrivalTime) {
    for (size_t k = 0; k < 4; k++)
    {
        if (currentArrivalTime[k] < nextArrivalTime[k]) {
            return true;
        }
        else if (currentArrivalTime[k] == nextArrivalTime[k]) {
            if (k == 3) {
                return true;
            }
            continue;
        }
        else {
            break;
        }
    }
    return false;
}
void gettingLatestArrival(char* currentArrivalTime, char* latestArrival, char* trafficTime, int trafficTimeInd) {
    for (size_t k = 0; k < 4; k++)
    {
        if (currentArrivalTime[k] < latestArrival[k]) {
            int count = 0;
            for (k = trafficTimeInd; k < trafficTimeInd + 4; k++)
            {
                trafficTime[k] = latestArrival[count++];
            }
            return;
        }
        else if (currentArrivalTime[k] == latestArrival[k]) {
            continue;
        }
        else {
            int count = 0;
            for (k = trafficTimeInd; k < trafficTimeInd + 4; k++)
            {
                trafficTime[k] = currentArrivalTime[count++];
            }
            return;
        }
    }
}
void gettingEarliestDeparture(char* currentDepartureTime, char* ealiestDepartureTime, char* trafficTime, int trafficTimeInd) {
    for (size_t k = 0; k < 4; k++)
    {
        if (currentDepartureTime[k] > ealiestDepartureTime[k] || k == 3) {
            int count = 0;
            for (k = trafficTimeInd; k < trafficTimeInd + 4; k++)
            {
                trafficTime[k] = ealiestDepartureTime[count++];
            }
            return;
        }
        else if (currentDepartureTime[k] == ealiestDepartureTime[k]) {
            continue;
        }
        else {
            int count = 0;
            for (k = trafficTimeInd; k < trafficTimeInd + 4; k++)
            {
                trafficTime[k] = currentDepartureTime[count++];
            }
            return;
        }
    }
}
bool comparingDepartureTimes(char* currentDepartureTime, char* nextDepartureTime) {
    for (size_t k = 0; k < 4; k++)
    {
        if (currentDepartureTime[k] < nextDepartureTime[k]) {
            return true;
        }
        else if (currentDepartureTime[k] == nextDepartureTime[k]) {
            continue;
        }
        else {
            break;
        }
    }
    return false;
}
void gettingIntervals(int indexPrevValue, int index, char** arrivals, char** departures, char* trafficTime, int trafficInd) {
    while (indexPrevValue < index - 1) {
        gettingLatestArrival(arrivals[indexPrevValue], arrivals[indexPrevValue + 1], trafficTime, trafficInd);
        trafficInd += 4;
        gettingEarliestDeparture(departures[indexPrevValue], departures[indexPrevValue + 1], trafficTime, trafficInd);
        indexPrevValue++;
        trafficInd = 0;
    }
}
bool checkIfDone(char** arrivals, char** departures, int indexArr, int indexDep) {
    if (arrivals[indexArr] == nullptr || departures[indexDep] == nullptr) {
        return true;
    }
    return false;
}
void comparison(char** arrivals, char** departures, int& indexArr, int& indexDep, unsigned& count, int& index) {
    while (comparingArrivalTimes(arrivals[indexArr], departures[indexDep])) {
        count++;
        indexArr++;
        index++;
        if (checkIfDone(arrivals, departures, indexArr, indexDep)) {
            return;
        }
    }
}

void output(char* trafficTime, int trafficInd) {
    while (trafficTime[trafficInd] >= '0' && trafficTime[trafficInd] <= '9')
    {
        if (trafficInd % 4 == 0 && trafficInd != 0) {
            if (trafficInd % 8 == 0) {
                cout << endl;
                cout << trafficTime[trafficInd];
                trafficInd++;
                continue;
            }
            cout << "-";
        }
        cout << trafficTime[trafficInd];
        trafficInd++;
    }
}

int main()
{
    unsigned n, count = 0, min = 0;
    cin >> n;
    char** arrivals = new char* [n + 1];
    char** departures = new char* [n + 1];
    char trafficTime[MAXSIZE];
    char** startArr = arrivals;
    char** startArr1 = departures;
    for (size_t i = 0; i < n; i++) {
        char* currentArrivalTime = new char[4];
        cin >> currentArrivalTime;
        *arrivals = currentArrivalTime;
        arrivals++;
    }
    *arrivals = nullptr;
    arrivals = startArr;
    for (size_t i = 0; i < n; i++) {
        char* currentDepartureTime = new char[4];
        cin >> currentDepartureTime;
        *departures = currentDepartureTime;
        departures++;
    }
    *departures = nullptr;
    departures = startArr1;
    int index = 0, indexArr = 0, indexDep = 0;
    int trafficInd = 0;
    bool isItOver = false;
    while (!checkIfDone(arrivals, departures, indexArr, indexDep)) {
        int indexPrevValue = index;
        comparison(arrivals, departures, indexArr, indexDep, count, index);
        indexDep++;
        if (count > min) {
            min = count;
            count = 0;
            gettingIntervals(indexPrevValue, index, arrivals, departures, trafficTime, trafficInd);
        }
        else if (count == min) {
            trafficInd += 8;
            gettingIntervals(indexPrevValue, index, arrivals, departures, trafficTime, trafficInd);
        }
    }
    trafficInd = 0;
    cout << min << endl;
    output(trafficTime, trafficInd);
}