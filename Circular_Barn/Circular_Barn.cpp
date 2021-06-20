#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int calculatingMovingDistance(vector<int> cowsWantedInEachRoom) {
    int sum = 0;
    for (int i = 0; i < cowsWantedInEachRoom.size(); i++) {
        sum += i * cowsWantedInEachRoom[i];
    }
    return sum;
}
int main()
{
    ifstream infile;
    ofstream outfile;
    int minimum = 99999999;
    int current = 0;
    infile.open("cbarn.in");
    outfile.open("cbarn.out");
    int numberOfRooms;
    infile >> numberOfRooms;
    vector<int> cowsWantedInEachRoom(numberOfRooms);
    
    for (int readingIn = 0; readingIn < numberOfRooms; readingIn++) {
        infile >> cowsWantedInEachRoom[readingIn];
    }
    for (int i = 0; i < numberOfRooms; i++) {
        current = calculatingMovingDistance(cowsWantedInEachRoom);
        int placeholder = cowsWantedInEachRoom[0];
        cowsWantedInEachRoom.erase(cowsWantedInEachRoom.begin());
        cowsWantedInEachRoom.push_back(placeholder);
        if (current < minimum) {
            minimum = current;
        }
    }
    outfile << minimum;


}
