/*************************************************************************
	> File Name: eular_15.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月29日 星期日 12时07分18秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main () {

    int64_t m, n;

    m = 1;
    n = 1;
    
    for (int64_t i = 21; i <= 40; i++) {
        m *= (i - 20);
        n *= i;
        int64_t temp = gcd(m, n);
        m /= temp;
        n /= temp;
    }

    cout << n / m << endl;

    return 0;
}
