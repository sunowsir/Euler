/*************************************************************************
	> File Name: eular_6.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月26日 星期四 10时38分46秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main () {

    int sum1, sum2;

    sum1 = (1 + 100) * 100 / 2;
    sum2 = 0;

    for (int i = 1; i <= 100; i++) {
        sum2 += i * i;
    }

    cout << sum1 * sum1 - sum2 << endl;

    return 0;
}
