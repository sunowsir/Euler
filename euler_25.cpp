/*************************************************************************
	> File Name: eular_25.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月26日 星期四 10时47分33秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main () {

    int f[3][1005] = {{0, 0}, {1, 1}, {1, 1}};
    int f_num = 2;

    int *f0, *f1, *f2, max_len;

    while (f[f_num % 3][0] < 1000) {
        
        f_num++;
        
        f0 = f[f_num % 3];
        f1 = f[(f_num - 1) % 3];
        f2 = f[(f_num - 2) % 3];

        max_len = max(max(f[0][0], f[1][0]), f[2][0]);
        f0[0] = max_len;
        
        //加法
        for (int i = 1; i <= max_len; i++) {
            f0[i] = f1[i] + f2[i];
        }
        //处理进位
        for (int i = 1; i <= max_len; i++) {
            if (f0[i] < 10) {
                continue;
            }
            f0[i + 1] += f0[i] / 10;
            f0[i] %= 10;
            f0[0] += (i == f0[0]);
        }

    }

    cout << f_num << endl;

    return 0;
}
