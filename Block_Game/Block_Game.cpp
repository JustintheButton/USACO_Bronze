#include <fstream>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
void howMany(string a, string b, map<char, int> &letters) {
    map<char, int> stringA;
    map<char, int> stringB;
    for (int i = 0; i < a.length(); i++) {
        stringA[a[i]]++;
    }
    for (int i = 0; i < b.length(); i++) {
        stringB[b[i]]++;
    }
    for (char i = 'a'; i < 'a' + 26; i++) {
        if (stringA[i] <= stringB[i]) {
            letters[i] += stringB[i];
        }
        else {
            letters[i] += stringA[i];
        }
    }
    
}
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("blocks.in");
    outfile.open("blocks.out");
    int n;
    infile >> n;
    vector<string> temp(2);
    vector<vector<string>> words(n, temp);
    for (int i = 0; i < n; i++) {
        infile >> words[i][0] >> words[i][1];
    }
    map<char, int> letters;
    for (int i = 0; i < n; i++) {
        howMany(words[i][0], words[i][1], letters);
    }

    for (char i = 'a'; i < 'a' + 26 ; i++) {
        outfile << letters[i] << endl;
    }

    outfile.close();

}


