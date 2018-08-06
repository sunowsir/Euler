/*************************************************************************
	> File Name: euler_02.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 14时17分14秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N  4000000

int main () {

    int a, b, ans;

    a = 0;
    b = 1;
    ans = 0;

    while (a + b <= MAX_N) {
        int temp = a;
        a = b;
        b = temp + b;
        if (b % 2 == 0) {
            ans += b;
        }
    }

    cout << ans << endl;

    return 0;
}
