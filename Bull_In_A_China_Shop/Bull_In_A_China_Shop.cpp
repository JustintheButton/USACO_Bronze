#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("bcs.in");
    outfile.open("bcs.out");
    int n;
    int k;
    infile >> n >> k;
    vector<char> temp(n);
    vector<vector<char>> original(n, temp);
    vector< vector< vector<char> > > pieces(k, vector< vector<char> >(n, vector<char>(n)));

    for (int assigningOriginalArrayx = 0; assigningOriginalArrayx < n; assigningOriginalArrayx++) {
        for (int assigningOrigianlArrayy = 0; assigningOrigianlArrayy < n; assigningOrigianlArrayy++) {
            infile >> original[assigningOriginalArrayx][assigningOrigianlArrayy];
        }
    }
    for (int pieceNumber = 0; pieceNumber < k; pieceNumber++) {
        for (int piecex = 0; piecex < n; piecex++) {
            for (int piecey = 0; piecey < n; piecey++) {
                infile >> pieces[pieceNumber][piecex][piecey];
            }
        }
    }
    //for (int i = 0; i < k; i++) {
    //    for (int j = 0; j < k; j++) {
    //        if (isFilledPieces[i] + isFilledPieces[j] == originalFilled && i != j && i < j) {
    //            outfile << i+1 << " " << j+1;
    //        }
    //    }
    //}

    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        cout << original[i][j];
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    //for (int i = 0; i < k; i++) {
    //    for (int j = 0; j < n; j++) {
    //        for (int k = 0; k < n; k++) {
    //            cout << pieces[i][j][k];
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}
}
