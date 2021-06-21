#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("diamond.in");
    outfile.open("diamond.out");
    int n;
    int k;
    int max = 0;
    infile >> n >> k;
    vector<int> diamonds(n);
    for (int i = 0; i < n; i++) {
        infile >> diamonds[i];
    }
    sort(diamonds.begin(), diamonds.end());
    if (diamonds[n-1] - diamonds[0] <= k) {
        max = diamonds.size();
    }
    for (int begin = 0; begin < n; begin++) {
        int end = 0;
        do {
            if (end + 1 < n) {
                end++;
            }
            else {
                break;
            }
        } while (diamonds[end] - diamonds[begin] <= k);
        
        if ((end - begin + 1) > max) {
            max = end - begin;
        }
    }
    outfile << max;
    outfile.close();
}

