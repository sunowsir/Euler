/*************************************************************************
	> File Name: euler_06.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 15时05分50秒
 ************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main () {

    int sum1, sum2;
    sum1 = 5050;

    for (int i = 1; i <= 100; i++) {
        sum2 += i * i;
    }

    cout << abs(sum1 * sum1 - sum2) << endl;

    return 0;
}
