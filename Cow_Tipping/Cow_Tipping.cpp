#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
pair<int, int> findMaxValue(vector<vector<int>> cows) {
    int maxx = 0;
    int maxy = 0;
    for (int i = 0; i < cows.size(); i++) {
        for (int j = 0; j < cows.size(); j++) {
            if (cows[i][j] == 1 && i + j > maxx + maxy) {
                maxx = i;
                maxy = j;
            }
        }
    }
    pair<int, int> returnPair;
    returnPair.first = maxx;
    returnPair.second = maxy;
    return returnPair;
}
void flip(vector<vector<int>> &cows, pair<int, int> farthestValue) {
    for (int i = 0; i <= farthestValue.first; i++) {
        for (int j = 0; j <= farthestValue.second; j++) {
            int temporary;
            temporary = cows[i][j];
            if (temporary == 1) {
                cows[i][j] = 0;
            }
            if (temporary == 0) {
                cows[i][j] = 1;
            }
        }
    }
}
bool isDone(vector<vector<int>> cows) {
    for (int i = 0; i < cows.size(); i++) {
        for (int j = 0; j < cows.size(); j++) {
            if (cows[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("cowtip.in");
    outfile.open("cowtip.out");
    int n;
    infile >> n;
    vector<int> temp(n);
    vector<vector<int>> cows(n, temp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char read;
            infile >> read;
            cows[i][j] = int(read - '0');
        }
    }
    pair<int, int> farthestValue;
    bool finishedTipping = false;
    int ans = 0;
    if (isDone(cows) == false) {
        do {
            ans++;
            farthestValue = findMaxValue(cows);
            flip(cows, farthestValue);
            finishedTipping = isDone(cows);
            

        } while (finishedTipping == false);
    }
    outfile << ans;
}
