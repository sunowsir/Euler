/*************************************************************************
	> File Name: eular_20.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月30日 星期一 09时34分37秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int main () {

    int ans[160] = {1, 1};
    int ans_num = 0;

    for (int i = 2; i <= 100; i++) {
        
        //做乘法
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }

        //处理进位
        for (int j = 1; j <= ans[0]; j++) {
            
            if (ans[j] < 10) {
                continue;
            }
            
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);

        }

    }

    for (int i = ans[0]; i > 0; i--) {
        ans_num += ans[i];
    }
    cout << ans_num << endl;

    return 0;
}
