#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<vector<char>> subString(const vector<vector<char>> &piece) {
    int maximumj = numeric_limits<int>::min();
    int maximumi = numeric_limits<int>::min();
    int minimumj = numeric_limits<int>::max();
    int minimumi = numeric_limits<int>::max();
    for (int i = 0; i < piece.size(); i++) {
        for (int j = 0; j < piece[i].size(); j++) {
            if (piece[i][j] == '#') {
                if (maximumj < j) {
                    maximumj = j;
                }
                if (minimumj > j) {
                    minimumj = j;
                }
                if (maximumi < i) {
                    maximumi = i;
                }
                if (minimumi > i) {
                    minimumi = i;
                }
            }
        }
    }
    vector<char>temp(maximumj - minimumj + 1);
    vector<vector<char>> returnVector(maximumi-minimumi+1, temp);
    for (int i = minimumi; i < maximumi+1; i++) {
        for (int j = minimumj; j < maximumj + 1; j++) {
            returnVector[i-minimumi][j-minimumj] = piece[i][j];
        }
    }
    return returnVector;
}

bool singleMatch(
    vector<vector<char>>& target,
    const vector<vector<char>>& piece1)
{
    vector<vector<char>> compactString = subString(piece1);
    bool foundMatch = false;
    int matchingShiftx = -1;
    int matchingShifty = -1;
    auto is_right_shift = [&](int shiftx, int shifty) {
        for (int compactx = 0; compactx < compactString.size(); compactx++) {
            for (int compacty = 0; compacty < compactString[compactx].size(); compacty++) {
                if (compactString[compactx][compacty] != target[compactx + shiftx][compacty + shifty] &&
                    compactString[compactx][compacty] == '#')
                    return false;
            }
        }
        return true;    
    };
    for (int shiftx = 0; shiftx < target.size() - compactString.size() + 1; shiftx++) {
        for (int shifty = 0; shifty < target[0].size() - compactString[0].size() + 1; shifty++) {
            bool isRightShift = is_right_shift(shiftx, shifty);
            if (isRightShift == true) {
                foundMatch = true;
                matchingShiftx = shiftx;
                matchingShifty = shifty;
                break;
            }
        }
        if (foundMatch == true) {
            break;
        }
    }
    if (matchingShiftx != -1 && matchingShifty != -1) {
        for (int i = 0; i < compactString.size(); i++) {
            for (int j = 0; j < compactString[1].size(); j++) {
                if(compactString[i][j] == '#')
                    target[matchingShiftx + i][matchingShifty + j] = '.';
            }
        }
    }

    return foundMatch;
}
bool compare(
    const vector<vector<char>> &target, 
    const vector<vector<char>> &piece1, 
    const vector<vector<char>> &piece2) 
{
    vector<vector<char>> copyTarget = target;
    bool firstCheck = singleMatch(copyTarget, piece1);
    if (!firstCheck) {
        return false;
    }
    bool secondCheck = singleMatch(copyTarget, piece2);
    return secondCheck;
}
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
    bool current = false;
    for (int ithpiece = 0; ithpiece < k; ithpiece++) {
        for (int jthpiece = 0; jthpiece < k; jthpiece++) {
            if (ithpiece >= jthpiece) {
                continue;
            }
            current = compare(original, pieces[ithpiece], pieces[jthpiece]);
            if (current == true) {
                outfile << ithpiece + 1<< " " << jthpiece+1;
            }
        }
    }

}
