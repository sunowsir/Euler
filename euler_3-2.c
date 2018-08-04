/*************************************************************************
	> File Name: eular_3-2.c
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月20日 星期五 17时16分23秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define maxn 600851475143

int main () {

    int64_t num, ans, n;
    num = maxn;
    ans = 0;
    n = 2;

    while (n * n <= num) {
        if (num % n == 0) {
            ans = n;
        }
        while (num % n == 0) {
            num /= n;
        }
        n++;
    }
     
    if (num != 1) {
        ans = num;
    }

    printf("%" PRId64 "\n", ans);

    return 0;
}
