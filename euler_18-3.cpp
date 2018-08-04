/*************************************************************************
	> File Name: eular_18-3.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月29日 星期日 15时40分47秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 15 

int keep[MAX_N + 5][MAX_N + 5] = {0};

int main () {

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> keep[i][j];
        }
    }

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j < i) {
                keep[i][j] += max(keep[i - 1][j], keep[i - 1][j - 1]);
            }
            if (j == i) {
                keep[i][j] += keep[i - 1][j - 1];
            }
        }
    }

    int ans = keep[14][0];

    for (int i = 1; i < MAX_N; i++) {
        ans = max(ans, keep[14][i]);
    }

    cout << ans << endl;

    return 0;
}
