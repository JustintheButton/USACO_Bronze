#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b) {
	int compare = a.compare(b);
	if (compare < 0) {
		return true;
	}
	else {
		return false;
	}

}
int main() {
	int n;
	int k;
	cin >> k >> n;
	vector<int> temp(n);
	vector<vector<int> > order(n, temp);
	vector<string>people(n);
	vector<vector<string> > names(k, people);
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			string str;
			cin >> str;
			names[i][j] = str;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				if (l == j) {
					continue;
				}
				if (j < l) {
					bool sameWork = compare(names[i][j], names[i][l]);
					vector<string>::iterator itj = find(people.begin(), people.end(), names[i][j]);
					int jdis = std::distance(people.begin(), itj);
					vector<string>::iterator itl = find(people.begin(), people.end(), names[i][l]);
					int ldis = std::distance(people.begin(), itl);
					if (abs(j - l) > 1) {
						for (int z = 0; z < abs(j - l); z++) {
							if (compare(names[i][j + z], names[i][j + z + 1]) == false) {
								sameWork = false;
								break;

							}
						}
					}
					if (sameWork == false && l > j) {
						if (order[jdis][ldis] == 2 || order[ldis][jdis] == 2) {
							continue;
						}
						order[jdis][ldis] = 1;
						order[ldis][jdis] = 2;
					}
				}

			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				cout << 'B';
			}
			else {
				if (order[i][j] == 0) {
					cout << '?';
				}
				else {
					cout << order[i][j] - 1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
