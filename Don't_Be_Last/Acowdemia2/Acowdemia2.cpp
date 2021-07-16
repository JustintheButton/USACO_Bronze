#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main() {
	int n;
	int k;
	cin >> k >> n;
	vector<int> temp(n);
	vector<vector<int> > order(n, temp);
	vector<string>temp2 (n);
	vector<vector<string> > names (k, temp2);
	for (int i = 0; i < k; i++) {
		string text;
		cin >> text;
		istringstream iss(text);
		for (int j = 0; j < n; j++) {
			iss >> names[i][j];
		}
	}
	return 0;
}
