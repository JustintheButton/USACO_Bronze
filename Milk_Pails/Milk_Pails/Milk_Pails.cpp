#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("pails.in");
	outfile.open("pails.out");
	int maximum = 0;
	int x;
	int y;
	int m;
	infile >> x >> y >> m;
	for (int i = 0; i <= floor(m / x); i++) {
		for (int j = 0; j <= floor(m / y); j++) {
			if (i * x + j * y <= m && i * x + j * y > maximum) {
				maximum = i * x + j * y;
			}
		}
	}
	outfile << maximum;
}

