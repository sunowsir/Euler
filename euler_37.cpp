/*************************************************************************
	> File Name: eular_37.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir > Created Time: 2018年07月28日 星期六 14时54分03秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 20000000
#define PRIME_MAX_N 1000000

int prime[PRIME_MAX_N + 5] = {0};
int is_prime[MAX_N] = {0};

void Linear_sieve() {
    for (int i = 2; i < PRIME_MAX_N + 10; i++) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= PRIME_MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return;

}

bool judge (int num) {
    
    //循环次数是该数的位数减一次
    for (int i = 1; i <= floor(log10(num)); i++) {
        int power = pow(10, i);
        if (is_prime[num % power] || is_prime[num / power]) {
            return false;
        }
    }

    return true;

}

int main () {

    int ans = 0;

    //线性筛
    Linear_sieve();
    
    is_prime[1] = 1;

    /*
    //测试线性筛
    for (int i = 1; prime[i] < PRIME_MAX_N; i++) {
        if (i % 5 == 0) {
            cout << endl;
        }
        cout << prime[i] << " ";
    }
    cout << endl;
    */

    //测试judge函数
    //cout << judge(3797) << endl;

    //从11开始遍历素数
    for (int i = 5; prime[i] <= PRIME_MAX_N; i++) {
        //判断是否符合题目要求
        if (judge(prime[i])) {
            cout << prime[i] << endl;
            ans += prime[i];
        }
    }

    cout << endl << ans << endl;

    return 0;
}
