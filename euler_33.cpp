/*************************************************************************
	> File Name: eular_33.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月01日 星期三 14时19分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool judge(int a, int b) {
    int a_ones, b_ones, a_ten, b_ten;

    a_ones = a / 10;
    b_ones = b / 10;
    a_ten = a % 10;
    b_ten = b % 10;
    
    if (a_ones != b_ones && a_ten == b_ten && a_ones != a_ten && b_ones != b_ten) {
        if (a * b_ones == b * a_ones) {
            return true;
        }
    }
    if (a_ones == b_ones && a_ten != b_ten && a_ones != a_ten && b_ones != b_ten) {
        if (a * b_ten == b * a_ten) {
            return true;
        }
    }
    if (a_ones == b_ten && a_ten != b_ones && a_ones != a_ten && b_ones != b_ten) {
        if (a * b_ones == b * a_ten) {
            return true;
        }
    }
    if (a_ten == b_ones && a_ones != b_ten & a_ones != a_ten && b_ones != b_ten) {
        if (a * b_ten == b * a_ones) {
            return true;
        }
    }

    return false;

}

int main () {

    int numerator, denominator;

    numerator = 1;
    denominator = 1;

    for (int i = 11; i < 100; i++) {
        if (i % 10 == 0) {
            continue;
        }
        for (int j= 11; j < 100; j++) {
            if (j % 10 == 0) {
                continue;
            }
            if (i > j) {
                continue;
            }
            if (judge(i, j)) {
                numerator *= i;
                denominator*= j;
            }
        }
    }

    cout << denominator / gcd(numerator, denominator)<< endl;

    return 0;
}
