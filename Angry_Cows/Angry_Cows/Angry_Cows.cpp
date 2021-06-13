#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

size_t calculateExplosion(
	const vector<int>& unexploded_in, 
	int start_pos) 
{
	vector<int> exploded;
	std::vector<int> unexploded = unexploded_in;
	unexploded[start_pos] = numeric_limits<int>::max();
	int blastradius = 1;
	int exploded_size_old = exploded.size();
	vector<int> identified(1, unexploded_in[start_pos]);

	do {
		exploded_size_old = exploded.size();
		std::vector<int> identified_this_round;
		for (int an_identified_value : identified) {
			for (int& an_unexploded : unexploded) {
				if (abs(an_identified_value - an_unexploded) <= blastradius) {
					identified_this_round.push_back(an_unexploded);
					an_unexploded = numeric_limits<int>::max();
				}
			}
		}
		exploded.insert(exploded.end(), identified.begin(), identified.end());
		identified = identified_this_round;
		blastradius++;
	} while (exploded_size_old != exploded.size());

	return exploded.size();
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
	
	for (int readNumber = 0; readNumber < nums; readNumber++) {
		infile >> haybales[readNumber];
	}
	for (int test = 0; test < nums; test++) {
		int progress = calculateExplosion(haybales, test);
		if (progress >= maximum) {
			maximum = progress;
			maxNumber = haybales[test];
		}
	}

	outfile << maximum;
	outfile.close(); 
	

}
