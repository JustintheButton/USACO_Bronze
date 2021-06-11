#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("angry.in");
	outfile.open("angry.out");
	
	int nums;
	infile >> nums;
	vector<int> haybales(nums);
	vector<int> haybalescopy(nums);
	
	for (int readNumber = 0; readNumber < nums; readNumber++) {
		infile >> haybales[readNumber];
		haybalescopy[readNumber] = haybales[readNumber];
	}
	int traveled = 0;
	int blastradius = 1;
	int explode = 0;
	int maximum = 0;
	int maxNumber;
	for (int testNumber = 0; testNumber < nums; testNumber++) {
		for (int permutationTest = 0; permutationTest < nums; permutationTest++) {
			if (abs(haybales[testNumber] - haybales[permutationTest]) <= blastradius && haybales[permutationTest] != haybales[testNumber]) {
				haybales[permutationTest] = 999999999999;
				explode++;
				traveled = 1;
			}
			if (permutationTest + 1 == nums && traveled == 1) {
				blastradius++;
				traveled = 0;
			}

		}
		if (explode > maximum) {
			maximum = explode;
		}
		explode = 0;
		blastradius = 1;
		for (int readNumber = 0; readNumber < nums; readNumber++) {
			haybales[readNumber] = haybalescopy[readNumber];
		}

		

	}
	outfile << maximum;
	outfile.close(); 
	//dgfdadddgfdsg ardtr

}
