/*************************************************************************
	> File Name: eular_7-x.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月24日 星期二 09时34分46秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000

int main () {

    int prime[MAX_N + 5] = {0};

    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) {
            continue;
        }
        for (int j = i; j <= MAX_N; j += i) {
            //不断的更新素因子；
            //eg.i = 2:j = 2 * ... ，j = 5: 2 * 5 = 10;prime[10] = 2;显然这不是10的最大素因子；
            //i = 5:j = 5 * ... ，j = 2:  5 * 2 = 10;prime[10] = 5;ok;
            prime[j] = i;
        }
    }

    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) {
            continue;
        }
        prime[i] = i;
    }

    for (int i = 2; i <= MAX_N; i++) {
        cout << i << " " << prime[i] << endl;
    }

    return 0;
}
