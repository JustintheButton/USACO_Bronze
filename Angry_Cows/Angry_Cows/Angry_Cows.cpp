#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void calculateExplosion(vector<int>& unexploded, vector<int>& exploded, int& blastradius) {
	int permutationTest;
	int blastRadiusBefore = exploded.size();
	for (int checkExplosion = 0; checkExplosion < exploded.size(); checkExplosion++) {
		for (permutationTest = 0; permutationTest < unexploded.size(); permutationTest++) {
			if (abs(exploded[checkExplosion] - unexploded[permutationTest]) <= blastradius) {
				exploded.push_back(unexploded[permutationTest]);
				unexploded[permutationTest] = numeric_limits<int>::max();
			}
		}
	}
	if (blastRadiusBefore < exploded.size()) {
		blastradius++;
	}
}
int main()
{
	int maxNumber = 0;
	int maximum = 0;
	ifstream infile;
	ofstream outfile;
	infile.open("5.in");
	outfile.open("angry.out");
	int blastradius = 1;
	
	int nums;
	infile >> nums;
	vector<int> haybales(nums);
	vector<int> resetHaybales(nums);
	vector<int> exploded(0);
	
	for (int readNumber = 0; readNumber < nums; readNumber++) {
		infile >> haybales[readNumber];
		resetHaybales[readNumber] = haybales[readNumber];
	}
	for (int test = 0; test < nums; test++) {
		exploded.push_back(haybales[test]);		
		haybales[test] = numeric_limits<int>::max();
		for (int i = 0; i < nums; i++) {
			calculateExplosion(haybales, exploded, blastradius);
		}
		int progress = exploded.size();
		
		if (progress >= maximum) {
			maximum = exploded.size();
			maxNumber = resetHaybales[test];
		}
		for (int readNumber = 0; readNumber < nums; readNumber++) {
			haybales[readNumber] = resetHaybales[readNumber];
		}
		exploded.clear();
		blastradius = 1;
		progress = 0;

	}

	outfile << maximum;
	outfile.close(); 
	

}
