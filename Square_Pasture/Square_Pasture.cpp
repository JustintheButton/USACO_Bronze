#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("square.in");
    outfile.open("square.out");
    int x1;
    int x2;
    int y1;
    int y2;
    int x3;
    int x4;
    int y3;
    int y4;
    infile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int ans;
    vector<int> xvalues(4);
    vector<int> yvalues(4);
    xvalues[0] = x1;
    xvalues[1] = x2;
    xvalues[2] = x3;
    xvalues[3] = x4;
    yvalues[0] = y1;
    yvalues[1] = y2;
    yvalues[2] = y3;
    yvalues[3] = y4;
    int maxx = *max_element(xvalues.begin(), xvalues.end());
    int minx = *min_element(xvalues.begin(), xvalues.end());
    int maxy = *max_element(yvalues.begin(), yvalues.end());
    int miny = *min_element(yvalues.begin(), yvalues.end());
    int xdiff = abs(maxx - minx);
    int ydiff = abs(maxy - miny);
    if (xdiff >= ydiff) {
        ans = xdiff * xdiff;
    }
    else
        ans = ydiff * ydiff;
    outfile << ans;
    outfile.close();

}
