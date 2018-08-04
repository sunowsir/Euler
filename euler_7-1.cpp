/*************************************************************************
	> File Name: eular_7-1.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月22日 星期日 18时56分06秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 200000

void is_Prime (int *prime) {
    for (int i = 2; i * i < MAX_N; i++) {
        if (prime[i]) {
            continue;
        }
        for (int j = i * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
    }
}

int main () {

    int prime[MAX_N + 5] = {0};

    is_Prime(prime);

    cout << prime[10001] << endl;

    return 0;
}
