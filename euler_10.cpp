/*************************************************************************
	> File Name: euler_10.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 17时11分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 2000000 

int64_t Prime(int *prime) {
    int64_t max = 0;

    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            if (i < MAX_N) {
                max += i;
            }
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return max;

}

int main() {
    
    int prime[MAX_N + 5] = {0};

    cout << Prime(prime) << endl;

    return 0;

}
