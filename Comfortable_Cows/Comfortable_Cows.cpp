#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<int> temp(1000);
	vector<vector<int>> cows(1000, temp);
	for (int i = 0; i < num; i++) {
		int x;
		int y;
		cin >> x >> y;
		cows[x][y]++;
	}
	int comfort = 0;
	for (int i = 0; i < num; i++) {

	}
}

