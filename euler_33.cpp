/*************************************************************************
	> File Name: eular_33.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月27日 星期五 20时24分38秒
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
    
    //四种情况：
    //1. ab / ac == b / c
    //十位相同，个位不同，自己的十位和个位不同
    if (a_ones != b_ones && a_ten == b_ten && a_ones != a_ten && b_ones != b_ten) {
        //ab / ac == b / c <==> ab * c == ac * b
        if (a * b_ones == b * a_ones) {
            return true;
        }
    }
    //2. ab / cb = a / c
    //个位相同，十位不同，自己的十位和个位不同
    if (a_ones == b_ones && a_ten != b_ten && a_ones != a_ten && b_ones != b_ten) {
        if (a * b_ten == b * a_ten) {
            return true;
        }
    }
    //3. ab / bc = a / c
    //a的个位和b的十位相同，a的十位和b的个位不同
    if (a_ones == b_ten && a_ten != b_ones && a_ones != a_ten && b_ones != b_ten) {
        if (a * b_ones == b * a_ten) {
            return true;
        }
    }
    //4. ab / ca = b / c
    //a的十位和b的个位相同，a的个位和b的十位不同
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
        //去掉后面带有０的。
        if (i % 10 == 0) {
            continue;
        }
        for (int j= 11; j < 100; j++) {
            //去掉后面带有０的。
            if (j % 10 == 0) {
                continue;
            }
            //比值小于１
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
