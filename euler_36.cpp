/*************************************************************************
	> File Name: euler_36.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 15时53分36秒
 ************************************************************************/

#include <cstdio>
#include <sstream>
#include <iostream>
using namespace std;

#define MAX_N 1000000

//判断ｎｕｍ在ｘ进制下是否是回文数
bool judge(int num, int x) {

    int n, rnum;
    n = num;
    rnum = 0;

    while (n) {
        rnum = rnum * x + n % x;
        n /= x;
    }

    return num == rnum;

}

int main () {

    int ans = 0;

    for (int i = 1; i < MAX_N; i++) {
        if (judge(i, 10) && judge(i, 2)) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
