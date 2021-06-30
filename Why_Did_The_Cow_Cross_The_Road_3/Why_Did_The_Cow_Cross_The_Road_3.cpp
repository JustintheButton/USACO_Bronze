#include <fstream>
#include <vector>
#include <utility>
//#include <iostream>
//#include <cmath>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("cowqueue.in");
	outfile.open("cowqueue.out");
	int n;
	infile >> n;
	vector<pair<int, int>> cows(0);
	for (int i = 0; i < n; i++) {
		int cow;
		int time;
		infile >> cow >> time;
		cows.push_back(make_pair(cow, time));
	}
	sort(cows.begin(), cows.end());
	int totalTime = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			totalTime += cows[i].first + cows[i].second;
		}
		else {
			if (cows[i].first >= totalTime) {
				totalTime = cows[i].first + cows[i].second;		
			}
			else {
				totalTime += cows[i].second;
			}
		}
	}
	outfile << totalTime;

	
	
}
