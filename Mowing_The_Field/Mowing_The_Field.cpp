#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	int x;
	int time;
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
	}
	vector<int> temp(100);
	vector<vector<int>> field(100, temp);



	outfile.close();


}
