/*************************************************************************
    * File Name: euler_12.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 2000000

int prime[MAX_N + 5] = {0};
int tnum[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};

void gtnum() {

    for (int i = 2; i * 2 < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;
            tnum[i] = 2;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                //i * prime[j]的最小素因子比i多了一个
                dnum[i * prime[j]] = dnum[i] + 1;
                tnum[i * prime[j]] = tnum[i] / (dnum[i] + 1) * (dnum[i] + 2);
                break;
            }
            else {
                //prime[j]成为i * prime[j]的最小素因子
                dnum[i * prime[j]] = 1;
                tnum[i * prime[j]] = tnum[i] * tnum[prime[j]];
            }
        }
    }

    return ;

}

int get_num(int n) {
    if (n % 2 != 0) {
        return tnum[n] * tnum[(n + 1) / 2];
    }
    return tnum[n / 2] * tnum[n + 1];
}

int main() {

    gtnum();

    int n = 1;
    while (get_num(n) < 500) ++n;

    cout << n * (n + 1) / 2 << endl;


    return 0;
}
