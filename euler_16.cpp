/*************************************************************************
> File Name: eular_16.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年07月25日 星期三 16时40分02秒
************************************************************************/

#include <iostream>
using namespace std;

int ans[400] = {0};

int main () {

    ans[0] = 1;
    ans[1] = 1;

    for (int i = 0; i < 50; i++) {

        //做乘法
        for (int j = ans[0]; j > 0; j--) {
            ans[j] *= 1024 * 1024;
        }

        //处理进位
        for (int j = 1; j <= ans[0]; j++) {
            if(ans[j] < 10) {
                continue;
            }
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }

    }

    int ans_sum = 0;

    for (int i = ans[0]; i > 0; i--) {
        ans_sum += ans[i];
    }

    cout << ans_sum << endl;

    return 0;
}
