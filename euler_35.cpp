/*************************************************************************
> File Name: eular_35.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年07月27日 星期五 21时32分31秒
************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 20000000
#define PRIME_MAX_N 1000000

int prime[PRIME_MAX_N + 5] = {0};
int isprime[MAX_N + 5] = {0};

void Linear_sieve () {
    for (int i = 2; i <= PRIME_MAX_N + 10; i++) {
        if (!isprime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= PRIME_MAX_N; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return;

}

int main () {

    int ans = 0;

    //线性筛
    Linear_sieve();

    //遍历每个素数，进行判断
    for (int i = 1; prime[i] < PRIME_MAX_N; i++) {

        bool judge = true;
        int num = prime[i];

        //旋转判断每个数是否为素数，旋转的次数就是该素数的位数
        for (int j = 0; j <= floor(log10(prime[i])) + 1; j++) {

            if (prime[i] < 10) {
                break;
            }

            //把个位数除掉，然后把这个个位数乘以10的这个素数位数减一次方就可以得到旋转一位后的数
            num = num / 10 + (num % 10) * pow(10, floor(log10(num / 10)) + 1);

            if (isprime[num] != 0) {
                judge = false;
                break;
            }
        }

        if (judge) {
            cout << prime[i] << endl;
            ans++;
        }

    }

    cout << endl;

    cout << ans << endl;

    return 0;
}
