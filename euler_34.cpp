/*************************************************************************
	> File Name: euler_34.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 15时20分21秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 21772800

int fac[10] = {0};

bool judge(int64_t i) {
    int64_t num, fsum;
    num = i;
    fsum = 0;

    while (i) {
        fsum += fac[i % 10];
        i /= 10;
    }

    return fsum == num;

}

int main () {

    int64_t ans = 0;

    fac[0] = 1;
    fac[1] = 1;

    for (int i = 2; i < 10; i++) {
        fac[i] = fac[i - 1] * i;
    }

    for (int i = 10; i <= MAX_N; i++) {
        if (judge(i)) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
