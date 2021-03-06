/*************************************************************************
	> File Name: euler_28.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 15时08分38秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int main () {

    int ans = 1;

    for (int i = 3; i <= 1001; i += 2) {
        int a = i * i;
        int b = a - (i - 1);
        int c = b - (i - 1);
        int d = c - (i - 1);
        ans = ans + a + b + c + d;
    }

    cout << ans << endl;

    return 0;
}
