#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("cowsignal.in");
    outfile.open("cowsignal.out");
    int m;
    int n;
    int k;
    infile >> m >> n >> k;
    vector<char> temp(n);
    vector<vector<char>> letters(m, temp);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            infile >> letters[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int o = 0; o < k; o++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < k; l++) {
                    outfile << letters[i][j];
                }
            }
            outfile << endl;
        }
        
    }
    
}

