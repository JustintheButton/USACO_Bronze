#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
void add(vector<int> &nums, int maxCitations) {    
    nums[nums.size() - maxCitations-1]++;    
}
int maxCitationsCalc(vector<int> nums) {
    int maxCitations = 0;
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] >= i) {
                count++;
            }
        }
        if (count >= i) {
            maxCitations = i;
        }
    }
    return maxCitations;
}
int weakestLinkCalculator(vector<int> nums) {
    int maxCitations = maxCitationsCalc(nums);
    int weakestLink = nums[nums.size()- maxCitations-1];    
    return weakestLink;
}
int main()
{
    int n;
    int l;
    int ans;
    cin >> n >> l;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int maxCitations = maxCitationsCalc(nums);
    if (maxCitations != n) {
        for (int j = maxCitations; j >= 0 && j > maxCitations - l; j--) {
            nums[j]++;
        }
    }
    cout << maxCitationsCalc(nums);

}

