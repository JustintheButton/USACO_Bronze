#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
bool doCrossPaths(vector<char> letters, char a, char b) {
    vector<char> mini;
    for (int i = 0; i < 52; i++) {
        if (letters[i] == a || letters[i] == b) {
            mini.push_back(letters[i]);
        }
    }
    if (mini[0] != mini[1] && mini[1] != mini[2]) {
        return true;
    }
    return false;
}
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("circlecross.in");
    outfile.open("circlecross.out");
    vector<char> letters(52);
    for (int i = 0; i < 52; i++) {       
        infile >> letters[i];
    }
    int crosspaths = 0;
    for (int i = 'A'; i < 'A' + 26; i++) {
        for (int j = 'A'; j < 'A' + 26; j++) {
            if (i == j) {
                continue;
            }
            if (doCrossPaths(letters, i, j) == true) {
                crosspaths++;
            }

        }
    }
    outfile << crosspaths/2;

}

