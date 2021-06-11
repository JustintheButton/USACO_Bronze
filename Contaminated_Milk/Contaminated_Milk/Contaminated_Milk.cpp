#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
using namespace std;

int main()
{
    /*
    
    
    
    
    
    
    
    TRIGGEREDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
    
    
    
    
    
    
    
    
    
    
    
    
    
    */
    ifstream infile;
    ofstream outfile;
    int dose = 0;
    infile.open("badmilk.in"); //delete .txt later for submission
    outfile.open("badmilk.out");
    vector<int> temp(3);
    int n, m, d, s;
    infile >> n >> m >> d >> s;    
    vector<int> tempdose(d);
    vector<vector<int> > log(m, tempdose);
    vector<int> temp2(2);
    vector<vector<int> > sick(s, temp2);
    vector<int> milktypes(m+1);
    vector<int> people(n);
    for (int i = 0; i < m; i++) {
        milktypes[i] = i+1;
    }
    for (int i = 0; i < n; i++) {
        people[i] = i + 1;
    }
    for (int i = 0; i < d; i++) {
        infile >> log[0][i] >> log[1][i] >> log[2][i];
    }
    for (int i = 0; i < s; i++) {
        infile >> sick[i][0] >> sick[i][1];
    }
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < d; j++) {
            if ((sick[i][0] == log[0][j]) && (sick[i][1] >= log[2][j])) {
                milktypes[log[1][j]] += 1000; //maybe something wrong with this
            }
        }
    }
    int maxElement = *std::max_element(milktypes.begin(), milktypes.end());

    int extra = 0;

    //finding the maximum dose
    for (int i = 0; i < m; i++) {
        if (milktypes[i] >= maxElement - d) {
            for (int j = 0; j < sick.size(); j++) {
                for (int k = 0; k < d; k++) {
                    if (log[1][k] <= sick[j][1] && log[0][k] == sick[j][0]) {
                        tempdose[i]++;
                        break;
                    }
                }
            }
        }
    }
    /*
    vector<int> example = { 3,4,2,2,5,7,100,5,10,11};
    std::cout << std::count(example.begin(), example.end(), 2) << endl;
    vector<int>::iterator found_pos = find(example.begin(), example.end(), 2);
    if (found_pos == example.end())
        cout << "didn't find it" << endl;
    else {
        cout << *found_pos << " is found at " << std::distance(example.begin(), found_pos) <<  endl;
    }
    */

    vector<int> alreadysick(n);


    dose = *std::max_element(tempdose.begin(), tempdose.end());

    vector<int> sickpeople(s);
    vector<int> alreadychecked(s);
    for (int i = 0; i < s; i++) {
        sickpeople[i] = sick[i][0];
        alreadychecked[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        vector<int>::iterator found_pos = find(sickpeople.begin(), sickpeople.end(), i);

        if (found_pos == sickpeople.end()) { //finding potentially sick people
            vector<int>::iterator seeIfSick = find(sick[0].begin(), sick[0].end(), i); //maybe wrong
            if (seeIfSick != log[0].end()) {
                if (1==1) {

                }
            }
        }
    }
    
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sick.size(); j++) {
            vector<int>::iterator found_pos = find(log[0].begin(), log[0].end(), i);
            if (found_pos == log[0].end()) {
                dose++;
            }

        }
    }
    */

    //write another for loop that counts all of the people who might get sick after the party
    outfile << dose;

}

