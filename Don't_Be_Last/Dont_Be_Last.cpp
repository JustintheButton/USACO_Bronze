#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("notlast.in");
    outfile.open("notlast.out");
    int n;
    infile >> n;
    vector<string> cows{ "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
    vector<int> milk{ 0,0,0,0,0,0,0 };
    for (int i = 0; i < n; i++) {
        string str;
        int value;
        int milkProduced;
        infile >> str >> milkProduced;
        vector<string>::iterator itr = find(cows.begin(), cows.end(), str);
        if (itr != cows.cend()) {
            value = distance(cows.begin(), itr);
        }
        milk[value] += milkProduced;
    }
    int min = numeric_limits<int>::max();
    for (int i = 0; i < 7; i++) {
        if (min > milk[i]) {
            min = milk[i];
        }
    }
    for (int i = 0; i < 7; i++) {
        if (min == milk[i]) {
            milk[i] = numeric_limits<int>::max();
        }
    }
    int solution = numeric_limits<int>::max();
    for (int i = 0; i < 7; i++) {
        if (solution > milk[i]) {
            solution = milk[i];
        }
    }
    string sol = "";
    int numberOfSolutions = 0;
    for (int i = 0; i < 7; i++) {
        if (solution == milk[i]) {
            sol = cows[i];
            numberOfSolutions++;
        }
    }
    if (numberOfSolutions > 1) {
        sol = "Tie";
    }
    outfile << sol;

    outfile.close();

}

