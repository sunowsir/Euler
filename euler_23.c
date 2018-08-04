/*************************************************************************
  > File Name: eular_23.c
  > Author: sunowsir
  > GitHub: github.com/sunowsir
  > Created Time: 2018年06月11日 星期一 11时02分46秒
 ************************************************************************/


//23题代码
#include <stdio.h>
#include <stdint.h>
#define MAX_N 28123
int32_t isPrime[MAX_N + 5] = {0};
int32_t prime[MAX_N] = {0};
int32_t d[MAX_N + 5]  = {0};
int32_t num[MAX_N + 5] = {0};
int32_t main() {
    d[1] = 0;
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) { 
            isPrime[i] = i;
            d[i] = i + 1;
            prime[++prime[0]] = i;
        }
        for (int32_t j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * 
                    (isPrime[i] * prime[j] * prime[j] - 1) / 
                    (isPrime[i] * prime[j] - 1);
                break;
            } else {
                isPrime[i * prime[j]] = prime[j];
                d[i * prime[j]] = d[prime[j]] * d[i];
            }
        }
    }

    d[0] = 0;
    for (int32_t i = 0; i <= MAX_N; i++) { 
        //真因数为约数和减去它本身；
        d[i] -= i;
        //筛选盈数；
        //真因数之和大于它本身为盈数；
        if (d[i] > i) {
            //用d[0]作为计数器，节省一个变量；
            //把盈数重新存到d数组里，节省一个数组；
            d[++d[0]] = i;

        }
    }
    //把所有的盈数两两相加把新数标记，这些数可以写成两个盈数的和；
    for (int32_t i = 1; i <= d[0]; i++) {
        for (int32_t j = i; j <= d[0]; j++) {
            if (d[i] + d[j] > MAX_N) {
                break;
            }
            num[d[i] + d[j]] = 1;
        }
    }
    //求所有不能写成两个盈数之和的数的和；
    int32_t sum = 0;
    for (int32_t i = 0; i <= MAX_N; i++) {
        if (!num[i]) {
            sum += i;
        }
    }
    printf("%d\n", sum); 
    return 0;
}
