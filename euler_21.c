/*************************************************************************
	> File Name: eular_21.c
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年06月09日 星期六 19时31分43秒
 ************************************************************************/
//21题代码
#include <stdio.h>
#include <stdint.h>
#define MAX_N 10000
int32_t isPrime[MAX_N + 5] = {0};//存储每个数字中最小素因子项的幂次值
int32_t prime[MAX_N] = {0};//
int32_t d[MAX_N + 5] = {0};//存储每个数的约数和
int32_t main() {
    d[1] = 0;
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) { 
            //若i是素数，那么它的最小素因子项的幂次值为它本身
            isPrime[i] = i;
            //它的约数为它本身和1;
            d[i] = i + 1;
            //这里把prime[0]作为计数器，节省一个变量。
            prime[++prime[0]] = i;
        }
        for (int32_t j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            //若a和b仅相差一个a中的最小素因子p，那么a/b==p,a%b==0;
            if (i % prime[j] == 0) {
                //若a和b存在如上关系，那么a*b的最小素因子项的幂次值为a和b的最小素数因子项的幂次值之积；
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                //约数和定理结论２
                //f(b) = f(a) * (p1 ^ a1 * p1 ^ 2 - 1) / (p1 ^ a1 * p1 - 1);
                d[i * prime[j]] = d[i] * 
                    (isPrime[i] * prime[j] * prime[j] - 1) / 
                    (isPrime[i] * prime[j] - 1);
                break;
            } else {
                
                //由于i和prime[j]互质，并且i > prime[j],i 不会等于prime[j],如果i == prime[j]，那么i % prime[j] == 0走上面的23行；
                isPrime[i * prime[j]] = prime[j];
                //约数和定理结论１
                d[i * prime[j]] = d[prime[j]] * d[i];
            }
        }
    }
    //根据题意比包括本身的真因数，故减去它本身
    for (int32_t i = 0; i <= MAX_N; i++) {
        d[i] -= i;
    }
    //求和
    int32_t sum = 0;
    for (int32_t i = 0; i <= MAX_N; i++) {
        //根据题意筛选
        if (d[i] <= MAX_N && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}

