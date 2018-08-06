/*************************************************************************
    * File Name: euler_49.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 100000

int prime[MAX_N + 5] = {0};

void get_prime() {
    
    for (int i = 2; i < MAX_N; i++) {
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

    return ;

}

bool judge(int a, int b, int c) {

    int num[10] = {0};
    while (a) {
        int temp = a % 10;
        num[temp]++;
        a /= 10;
    }
    int bnum[10] = {0};
    while (b) {
        int temp = b % 10;
        bnum[temp]++;
        b /= 10;
    }
    int cnum[10] = {0};
    while (c) {
        int temp = c % 10;
        cnum[temp]++;
        c /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (bnum[i] != num[i] || cnum[i] != num[i]) {
            return false;
        }
    }
    
    return true;

}

bool judgecon(int pnum, int index) {
    for (int i = index + 1; prime[i] < 10000; i++) {
        for (int j = i + 1; prime[j] < 10000; j++) {
            if (judge(pnum, prime[i], prime[j])) {
                if ((prime[j] - prime[i] == prime[i] - pnum)) {
                    cout << pnum << prime[i] << prime[j] << endl;
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {

    get_prime();

    bool flag;

    flag = true;

    for (int i = 1; prime[i] < 10000 && flag; i++) {
        //if (prime[i] == 1487) {
        //    cout << "i = " << i << endl;
        //}
        if (prime[i] < 1000) {
            continue;
        }
        int index = i;
        judgecon(prime[i], index);
    }
    cout << endl;

    return 0;
}
