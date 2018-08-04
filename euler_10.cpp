/*************************************************************************
	> File Name: eular_10.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月16日 星期一 10时29分19秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

#define PRIME_MAX_N 2000000

int64_t isPrime(int *prime) {

    int64_t ans = 0;

    for (int i = 2; i < PRIME_MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            if (i < PRIME_MAX_N) {
                ans += i;
            }
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < PRIME_MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return ans;

}

int main () {    

    int prime[PRIME_MAX_N + 5] = {0};

    cout << isPrime(prime) << endl;
    
    return 0;
}

