/*************************************************************************
	> File Name: eular_9.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月29日 星期日 20时02分37秒
 ************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 40
int gcd(int a,int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main () {

    bool jump;
    int a, b, c;

    jump = true;

    //获取勾股数
    for (int n = 1; n < MAX_N && jump; n++) {
        for (int m = n + 1; m < MAX_N && jump; m++) {
            //根据素勾股数性质构建素勾股数
            if (gcd(n, m) == 1) {

                a = 2 * n * m;
                b = m * m - n * n;
                c = m * m + n * n;
                //判断1000是否为三个数加和的倍数。
                if (1000 % (a + b + c) == 0) {
                    //根据素勾股数性质
                    int x = pow(1000 / (a + b + c), 3);
                    cout << a * b * c * x << endl;
                    jump = false;
                }
            }
        }
    }

    return 0;
}
