/*************************************************************************
    * File Name: euler_21.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 10000

void Get_Psum(int *prime, int *pnum, int *fnum) {
    
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            pnum[i] = 1;
            fnum[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                pnum[i * prime[j]] = pnum[i] + 1;
                fnum[i * prime[j]] = fnum[i] / (pow(prime[j], pnum[i] + 1) - 1) * (pow(prime[j], pnum[i] + 2) - 1);
                break;
            } else {
                pnum[i * prime[j]] = 1;
                fnum[i * prime[j]] = fnum[i] * fnum[prime[j]];
            }
        }
    }

    return;

}

int main() {

    int prime[MAX_N + 5] = {0};
    int pnum[MAX_N + 5] = {0};
    int fnum[MAX_N + 5] = {0};

    Get_Psum(prime,pnum,fnum);

    for (int i = 2; i < MAX_N; i++) {
        fnum[i] -= i;
    }

    int ans = 0;

    for (int i = 2; i < MAX_N; i++) {
        if (fnum[fnum[i]] == i && fnum[i] != i) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
