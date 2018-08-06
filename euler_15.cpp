/*************************************************************************
    * File Name: euler_15.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

int64_t gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {

    int64_t a, b;
    a = 1;
    b = 1;
    
    for (int i = 21; i <= 40; i++) {
        a *= i - 20;
        b *= i;
        int64_t temp = gcd(a, b);
        a /= temp;
        b /= temp;
    }

    cout << b / a << endl;

    return 0;

}
