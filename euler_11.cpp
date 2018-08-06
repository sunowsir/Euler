/*************************************************************************
> File Name: eular_11.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年07月16日 星期一 17时29分51秒
************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int main () {

    int maps[30][30] = {0};
    int dx[4] = {0, 1, 1, 1};
    int dy[4] = {1, 1, 0, -1};

    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            cin >> maps[i][j];
        }
    }

    int ans, maxn;
    maxn = 0;

    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int dir = 0; dir < 4; dir++) {
                ans = 1;
                int nx = i;
                int ny = j;
                for (int step = 0; step < 4; step++) {
                    ans *= maps[nx][ny];
                    nx += dx[dir];
                    ny += dy[dir];
                }
                maxn = max(maxn, ans);
            }
        }
    }

    cout << maxn << endl;

    return 0;
}
