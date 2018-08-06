/*************************************************************************
    * File Name: euler_47.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 1000000

int pfac[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};

void Get_Prime() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            pfac[i] = 1;
        }
        for (int j = 1; j < prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                pfac[i * prime[j]] = pfac[i];
                break;
            } else {
                pfac[i * prime[j]] = pfac[i] + 1;
            }
        }
    }
}

bool judge(int a) {
    int b, c, d;

    b = a + 1;
    c = b + 1;
    d = c + 1;

    if (pfac[a] == 4 && pfac[b] == 4 && pfac[c] == 4 && pfac[d] == 4) {
        return true;
    }

    return false;

}


int main() {

    Get_Prime();

    for (int i = 10; i < MAX_N; i++) {
        if (!judge(i)) {
            continue;
        }
        cout << i << endl;
        break;
    }

    return 0;
}
