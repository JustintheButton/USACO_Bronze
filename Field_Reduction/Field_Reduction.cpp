#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;
int minWithFilter(const vector<int>& inputVector, int filter) {
    int minimumValue = numeric_limits<int>::max();
    for (int i = 0; i < inputVector.size(); i++) {
        if (i != filter && inputVector[i] < minimumValue) {
            minimumValue = inputVector[i];
        }
    }
    return minimumValue;
}
int maxWithFilter(const vector<int>& inputVector, int filter) {
    int maximum = numeric_limits<int>::min();
    for (int i = 0; i < inputVector.size(); i++) {
        if (i != filter && inputVector[i] > maximum) {
            maximum = inputVector[i];
        }
    }
    return maximum;
}
enum RequestType {requestMin, requestMax, numOfRequestType};
list<int> findMultipleExtremes(const vector<int>& inputVector, RequestType a_request_type) {
    list<int> returnedList;
    int extreme = a_request_type == requestMin ? *min_element(inputVector.begin(), inputVector.end())
        : *max_element(inputVector.begin(), inputVector.end());
    for (int i = 0; i < inputVector.size(); i++) {
        if (extreme == inputVector[i]) {
            returnedList.push_back(i);
        }
    }
    return returnedList;
}
 
int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("reduce.in");
    outfile.open("reduce.out");
    int n;
    infile >> n;
    vector<int> temp(2);
    vector<int> locations[2];
    for (size_t i = 0; i < 2; i++)
        locations[i].resize(n);
    for (int readIn = 0; readIn < n; readIn++) {
        infile >> locations[0][readIn] >> locations[1][readIn];
    }
    int min = numeric_limits<int>::max();

    std::list<int> candidate_locations;
    for (int dim = 0; dim < 2; dim++) {
        for (int request_type = 0; request_type < numOfRequestType; request_type++) {
            auto list_of_extremes = findMultipleExtremes(locations[dim], (RequestType)request_type);
            candidate_locations.insert(candidate_locations.end(), list_of_extremes.begin(), list_of_extremes.end());
        }
    }
    for (int i : candidate_locations) {
        auto minx = minWithFilter(locations[0], i);
        auto miny = minWithFilter(locations[1], i);
        auto maxx = maxWithFilter(locations[0], i);
        auto maxy = maxWithFilter(locations[1], i);
        auto currentArea = (maxx - minx) * (maxy - miny);
        if (currentArea < min) {
            min = currentArea;
        }
    }
    outfile << min;
    

}

