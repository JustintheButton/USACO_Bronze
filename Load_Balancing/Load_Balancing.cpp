#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;
int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("balancing.in");
	outfile.open("balancing.out");
	int numberOfCows;
	int maximumValues;
	infile >> numberOfCows >> maximumValues;
	vector<int> x(numberOfCows);
	vector<int> y(numberOfCows);

	int minimum = numeric_limits<int>::max();
	for (int readingIn = 0; readingIn < numberOfCows; readingIn++) {
		infile >> x[readingIn] >> y[readingIn];
	}

	int c = 0;
	int d = 0;
	int temp[4] = {0,0,0,0};
	set<int> xyvalues[2];
	xyvalues[0].insert(x.begin(), x.end());
	xyvalues[1].insert(y.begin(), y.end());
	list<int> div[2];
	for (int iset = 0; iset < 2; iset++) {
		for (auto iter = xyvalues[iset].begin(); iter != xyvalues[iset].end(); iter++) {
			int this_value = *iter;
			auto next_iter = std::next(iter, 1);
			if (next_iter == xyvalues[iset].end())
				break;
			div[iset].push_back((this_value + *next_iter) / 2);
		}
	}
	for (int b : div[0]) {
		for (int a : div[1]) {
			for (int xtracker = 0; xtracker < numberOfCows; xtracker++) {
				int xval = x[xtracker];
				int yval = y[xtracker];
				if (xval < b && yval > a) {
					temp[0]++;
				}
				else if (xval > b && yval > a) {
					temp[1]++;
				}
				else if (xval > b&& yval < a) {
					temp[2]++;
				}
				else if (xval < b && yval < a) {
 					temp[3]++;
				}
 			}
			
			int tempmax = 0;
			for (int i = 0; i < 4; i++) {
				if (tempmax < temp[i]) {
					tempmax = temp[i];
				}
			}
			if (minimum > tempmax) {
				minimum = tempmax;
			}
			for (int i = 0; i < 4; i++) {
				temp[i] = 0;
			}
		}
	}
	////create new vector which has only one division between two consecutive possible a so it doesn't 
	////try every single point, and also make sure to do the same thing for b aswell
	////sort
	//for (a = 0; a <= maximumValues; a += 2) {
	//	//a++;
	//	for (b = 0; b <= maximumValues; b+=2) {
	//		//b++;
	//		for (const auto& item : x) {
	//			int xcow = item.first;
	//			int ycow = item.second;
	//			if (xcow < b && ycow > a) {
	//				temp[0]++;
	//			}
	//			else if (xcow > b && ycow > a) {
	//				temp[1]++;
	//			}
	//			else if (xcow > b&& ycow < a) {
	//				temp[2]++;
	//			}
	//			else if (xcow < b && ycow < a) {
	//				temp[3]++;
	//			}
	//		}
	//		int tempmax = 0;
	//		for (int i = 0; i < 4; i++) {
	//			if (tempmax < temp[i]) {
	//				tempmax = temp[i];
	//			}
	//		}
	//		if (minimum > tempmax) {
	//			minimum = tempmax;
	//		}
	//		for (int i = 0; i < 4; i++) {
	//			temp[i] = 0;
	//		}
	//	}
	//	//if (a%100 == 1)
	//	//	std::cout << a << std::endl;
	//}

	outfile << minimum;
	outfile.close();
}

