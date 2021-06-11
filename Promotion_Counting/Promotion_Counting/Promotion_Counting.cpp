#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("promote.in");
	outfile.open("promote.out");
	int bronzeb;
	int bronzea;
	int silverb;
	int	silvera;
	int goldb;
	int golda;
	int platb;
	int	plata;
	infile >> bronzeb >> bronzea >> silverb >> silvera >> goldb >> golda >> platb >> plata;
	int bronzep = 0;
	int silverp = 0;
	int goldp = 0;
	goldp = plata - platb;
	silverp = (golda + plata) - (goldb + platb);
	bronzep = (silvera + golda + plata) - (silverb + goldb + platb);
	outfile << bronzep << endl << silverp << endl << goldp;
	outfile.close();

}
