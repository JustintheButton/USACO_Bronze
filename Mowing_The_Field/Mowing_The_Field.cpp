#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;
int findx(vector<vector<int>> field, int x, int y, int after) {
	int before = field[x][y];
	return (after - before);
}
int main()
{
	int x;
	int time;
	int totalTime = 0;
	ifstream infile;
	ofstream outfile;
	infile.open("mowing.in");
	outfile.open("mowing.out");
	int numbers;
	infile >> numbers;
	vector<char> directions(numbers);
	vector<int> lengths(numbers);
	for (int read = 0; read < numbers; read++) {
		infile >> directions[read] >> lengths[read];
		totalTime += lengths[read];
	}
	vector<int> replacements(0);
	vector<int> temp(2000);
	vector<vector<int>> field(1000, temp);
	vector<vector<int>> howManyTimes(2000, temp);
	time = 1;
	int thex = 500;
	int they = 1000;
	for (int read = 0; read < numbers; read++) {
		if (directions[read] == 'N') {
			for (int i = 0; i < lengths[read]; i++) {
				if (field[thex][they] != 0) {
					replacements.push_back(findx(field, thex, they, time));
				}
				field[thex][they] = time;
				howManyTimes[thex][they]++;
				time++;
				they++;
			}
		}
		else if (directions[read] == 'S') {
			for (int i = 0; i < lengths[read]; i++) {
				if (field[thex][they] != 0) {
					replacements.push_back(findx(field, thex, they, time));
				}
				field[thex][they] = time;
				howManyTimes[thex][they]++;
				time++;
				they--;
			}
		}
		else if (directions[read] == 'W') {
			for (int i = 0; i < lengths[read]; i++) {
				if (field[thex][they] != 0) {
					replacements.push_back(findx(field, thex, they, time));
				}
				field[thex][they] = time;
				howManyTimes[thex][they]++;
				time++;
				thex--;
			}
		}
		else if (directions[read] == 'E') {
			for (int i = 0; i < lengths[read]; i++) {
				if (field[thex][they] != 0) {
					replacements.push_back(findx(field, thex, they, time));
				}
				field[thex][they] = time;
				howManyTimes[thex][they]++;
				time++;
				thex++;
			}
		}

	}
	bool isThereDoubled = false;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 2000; j++) {
			if (howManyTimes[i][j] > 1) {
				isThereDoubled = true;
			}
		}
	}	
	int least = 999999999;

	if (isThereDoubled == false) {
		least = -1;
	}
	for (int i = 0; i < replacements.size(); i++) {
		if (replacements[i] < least) {
			least = replacements[i];
		}
	}
	outfile << least;
	
	outfile.close();


}
