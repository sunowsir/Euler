/*************************************************************************
    * File Name: euler_37.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 2000000

bool Is_Prime(int n) {

    //1和0不是素数
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool judge(int num) {
    if (!Is_Prime(num)) {
        return false;
    }

    int len = floor(log10(num)) + 1;

    for (int i = 1; i < len; i++) {
        int power = pow(10, i);
        int num1 = num / power;
        int num2 = num % power;

        if (!Is_Prime(num1) || !Is_Prime(num2)) {
            return false;
        }
    }

    return true;

}

int main() {

    int64_t ans = 0;
    int nums = 0;

    for (int i = 11; i < MAX_N; i++) {
        if (judge(i)) {
            nums++;
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
