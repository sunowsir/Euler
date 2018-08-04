/*************************************************************************
	> File Name: eular_5.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月03日 星期二 13时33分14秒
 ************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main () {

    int ans = 1;

    for (int i = 1; i <= 20; i++) {
        ans *= i / gcd(i, ans);
    }

    cout << ans << endl;

    return 0;
}
