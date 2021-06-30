#include <fstream>
#include <map>
#include <iostream>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("crossroad.in");
    outfile.open("crossroad.out");
    int n;
    infile >> n;
    int sightings = 0;
    map<int, int> cows;
    for (int i = 0; i < n; i++) {
        int cow;
        int val;
        infile >> cow >> val;
        if (cows.find(cow) == cows.end() || cows[cow] == val) {
            cows[cow] = val;
        }
        else {
            cows[cow] = val;
            sightings++;
        }
    }
    outfile << sightings;
    
}

