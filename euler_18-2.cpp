/*************************************************************************
	> File Name: eular_18-2.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月29日 星期日 15时07分06秒
 ************************************************************************/

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

    for (int i = 13; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            keep[i][j] += max(keep[i + 1][j], keep[i + 1][j + 1]);
        }
    }

    cout << keep[0][0] << endl;

    return 0;
}
