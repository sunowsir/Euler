/*************************************************************************
    * File Name: euler_46.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 200000

int prime[MAX_N + 5] = {0};
int gold[MAX_N + 5] = {0};

void Get_Prime_Init() {

    //prime linear sieve, while marking each prime number to 1. 
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            gold[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    //enumerate each prime number.
    for (int i = 1; i <= prime[0]; i++) {

        //mark even number to 1.
        if (i % 2 == 0) {
            gold[i] = 1;
        }
        //mark the number that matches the conjecture as 1
        //enumerate each square number
        for (int j = 1; prime[i] + 2 * j * j < MAX_N; j++) {
            gold[prime[i] + 2 * j * j] = 1;
        }
    }
}


int main() {

    //call initialization function.
    Get_Prime_Init();

    //traversing the tag array gold.
    for (int i = 2; i < MAX_N; i++) {
        
        if (!gold[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
