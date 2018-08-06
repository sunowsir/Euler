/*************************************************************************
	> File Name: euler_07.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 16时23分47秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 2000000


void Prime(int *prime) {
    for (int i = 2; i < MAX_N + 10; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return;

}

int main () {
    
    int prime[MAX_N + 5] = {0};

    Prime(prime);

    cout << prime[10001] << endl;

    return 0;
}
