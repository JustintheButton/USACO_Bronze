// USACO_Bronze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    int sum;
    ifstream myfile;
    ofstream outfile;
    myfile.open("paint.in");
    outfile.open("paint.out");
    myfile >> a >> b >> c >> d;
    if (c >= b) {
        sum = (b - a) + (d - c);
    }
    if (a >= d) {
        sum = (d - c) + (b - a);
    }
    if (b >= c && d >= a && b >= d){
        sum = b - c;
    }
    if (b <= d && a <= c && b >= c) {
        sum = d - a;
    }
    if (b >= d&& c >= a) {
        sum = b - a;
    }
    if (a >= c&& d >= b) {
        sum = d - c;
    }
    outfile << sum;

}

