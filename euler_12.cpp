/*************************************************************************
    * File Name: euler_12.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 200000

int prime[MAX_N + 5] = {0};
int pnum[MAX_N + 5] = {0};
int fnum[MAX_N + 5] = {0};

void Get_Fnum() {
    
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            pnum[i] = 1;
            fnum[i] = 2;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = i;
            if (i % prime[j] == 0) {
                pnum[i * prime[j]] = pnum[i] + 1;
                fnum[i * prime[j]] = fnum[i] / (pnum[i] + 1) * (pnum[i] + 2);
                break;
            } else {
                pnum[i * prime[j]] = 1;
                fnum[i * prime[j]] = fnum[i] * fnum[prime[j]];
            }
        }
    }

    return ;

}

int Get_Tri(int n){
    
    if (n % 2 == 0) {
        return fnum[n / 2] * fnum[n - 1];
    } else {
        return fnum[n] * fnum[(n - 1) / 2];
    }

}

int main() {

    Get_Fnum();

    int i = 29;

    while (Get_Tri(i) < 500) {
        i++;
    }

    //the formula for number of triangles is : T(n) = n * (n - 1) / 2;
    //the variable i in the above loop is n in the formula. 
    //however, the title requires the number of triangles.
    cout << i * (i - 1) / 2 << endl;

    return 0;    
}
