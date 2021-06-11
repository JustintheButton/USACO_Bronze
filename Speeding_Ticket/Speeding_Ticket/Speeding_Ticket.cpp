#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	 int n, m, p, q, over;
	 over = 0;
	 ifstream myfile;
	 ofstream other;
	 myfile.open("speeding.in");
	 other.open("speeding.out");
	 myfile >> n >> m;
	 vector<int> temp(2);
	 vector<vector<int> > vectorn(n, temp);
	 vector<vector<int> > vectorm(m, temp);
	 vector<int> speedlimit(100);
	 vector<int> drivingspeed(100);
	 for (int i = 0; i < n; i++) {
		 myfile >> p >> q;
		 vectorn[i][0] = p;
		 vectorn[i][1] = q;
	 }
	 for (int i = 0; i < m; i++) {
		 myfile >> p >> q;
		 vectorm[i][0] = p;
		 vectorm[i][1] = q;
	 }

	 int starting_pos = 0;
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < vectorn[i][0]; j++) {
			 speedlimit[starting_pos+j] = vectorn[i][1];
		 }
		 starting_pos += vectorn[i][0];
	 }
	 starting_pos = 0;
	 for (int i = 0; i < m; i++) {
		 for (int j = 0; j < vectorm[i][0]; j++) {
			 drivingspeed[j+ starting_pos] = vectorm[i][1];
		 }
		 starting_pos += vectorm[i][0];
	 }
	 for (int i = 0; i < 100; i++) {
		 if (speedlimit[i] > drivingspeed[i]) {
			 continue;
		 }
		 else if (speedlimit[i] == drivingspeed[i]) {
			 continue;
		 }
		 else if (speedlimit[i] < drivingspeed[i]) {
			 if ((drivingspeed[i] - speedlimit[i]) > over) {
				 over = drivingspeed[i] - speedlimit[i];
			 }
			 else {
				 continue;
			 }
		 }
	 }
	 other << over;
	 other.close();


}
