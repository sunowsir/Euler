/*************************************************************************
    * File Name: euler_18.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 15

int nmap[MAX_N + 5][MAX_N + 5] = {0};
int book[MAX_N + 5][MAX_N + 5] = {0};

int solve(int x, int y) {
    if (x >= MAX_N) {
        return 0;
    }

    if (book[x][y]) {
        return book[x][y];
    }

    int lnum = solve(x + 1, y) + nmap[x][y];
    int rnum = solve(x + 1, y + 1) + nmap[x][y];

    book[x][y] = lnum > rnum ? lnum : rnum;

    return book[x][y];

}

int main() {

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> nmap[i][j];
        }
    }

    cout << solve(0, 0) << endl;

    return 0;
}
