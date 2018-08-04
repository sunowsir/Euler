/*************************************************************************
	> File Name: eular_18.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月29日 星期日 14时40分58秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 15

int maps[MAX_N][MAX_N] = {0};
int keep[MAX_N][MAX_N] = {0};

int solve(int x, int y) {
    if (x == MAX_N) {
        return 0;
    }
    if (keep[x][y]) {
        return keep[x][y];
    }
    int lnum, rnum;
    
    lnum = solve(x + 1, y);
    rnum = solve(x + 1, y + 1);

    keep[x][y] = (lnum > rnum ? lnum : rnum) + maps[x][y];

    return keep[x][y];
}

int main () {

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> maps[i][j];
        }
    }

    cout << solve(0, 0) << endl;

    return 0;
}
