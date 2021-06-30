#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int determineWinner(int rock, int paper, int scissors, int p1, int p2) {
    if (p1 == rock) {
        if (p2 == scissors) {
            return 1;
        }
        if (p2 == rock) {
            return 0;
        }
        if (p2 == paper) {
            return 2;
        }
    }
    if (p1 == scissors) {
        if (p2 == scissors) {
            return 0;
        }
        if (p2 == rock) {
            return 2;
        }
        if (p2 == paper) {
            return 1;
        }
    }
    if (p1 == paper) {
        if (p2 == scissors) {
            return 2;
        }
        if (p2 == rock) {
            return 1;
        }
        if (p2 == paper) {
            return 0;
        }
    }
}
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("hps.in");
    outfile.open("hps.out");
    int n;
    infile >> n;
    vector<int> temp(2);
    vector<vector<int>> games(n, temp);
    for (int i = 0; i < n; i++) {
        infile >> games[i][0] >> games[i][1];
    }
    int maximum = 0;
    for (int rockValue = 1; rockValue < 4; rockValue++) {
        for (int scissorValue = 1; scissorValue < 4; scissorValue++) {
            for (int paperValue = 1; paperValue < 4; paperValue++) {
                if (rockValue != paperValue && paperValue != scissorValue && scissorValue != rockValue) {
                    int current = 0;
                    for (int i = 0; i < n; i++) {
                        if (determineWinner(rockValue, paperValue, scissorValue, games[i][0], games[i][1]) == 1) {
                            current++;
                        }
                    }
                    if (current > maximum) {
                        maximum = current;
                    }
                }
            }
        }
    }
    outfile << maximum;
    outfile.close();
}


