/*************************************************************************
	> File Name: euler_01.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 14时04分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int main () {

    int sum3, sum5, sum15;

    sum3 = (3 + 999) * 333 / 2;
    sum5 = (5 + 995) * 200 / 2;
    sum15 = 0;

    for (int i = 1; i < 1000; i++) {
        if (i % 15 == 0) {
            sum15 += i;
        }
    }

    cout << sum3 + sum5 - sum15 << endl;

    return 0;
}
