/*************************************************************************
	> File Name: euler_5.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 16时14分45秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main () {

    int ans = 1;

    for (int i = 1; i <= 20; i++) {
        ans *= i / gcd(i, ans);
    }

    cout << ans << endl;

    return 0;
}
