
#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int ans = 0;
    for (c = 0; c < 4; c++) {
        for (a = 0; a < 10; a++) {
            for (b = 0; b < 10; b++) {
                for (d = 0; d < 10; d++) {
                    for (e = 0; e < 10; e++) {
                        for (f = 0; f < 10; f++) {
                            for (g = 0; g < 10; g++) {
                                if (a > b&& b > c&& g > f&& f > e&& e > d&& d > c && (a!=b!=c!=d != e != f != g)) {
                                    ans++;
                                }

                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;

}
