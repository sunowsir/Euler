/*************************************************************************
	> File Name: eular_2-2.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月20日 星期五 15时46分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main () {

    int f[3] = {1, 0, 0}, sum = 0, n = 1;

    while (f[(n - 1) % 3] + f[(n + 1) % 3] <= 4000000) {
        f[n % 3] = f[(n - 1) % 3] + f[(n + 1) % 3];
        if (f[n % 3] % 2 == 0) {
            sum += f[n % 3];
        }
        n += 1;
    }

    cout << sum << endl;

    return 0;
}
