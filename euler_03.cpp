/*************************************************************************
	> File Name: euler_03.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 14时23分07秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 600851475143

int main () {

    int64_t ans = -1;

    for (int64_t i = 2; i * i < MAX_N ; i++) {
        //i是否是该数的因数
        if (MAX_N % i == 0) {
            bool flag = true;
            //判断i是否为素数
            for (int64_t j = 2; j * j < i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            //如果是素数，把较大的存储在ans中
            if (flag) {
                ans = max(ans, i);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

