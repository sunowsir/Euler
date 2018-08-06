/*************************************************************************
    * File Name: euler_25.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int f[3][1100];

int fib(int fs) {


    int *f0, *f1, *f2, n;

    n = 1;
    f[0][0] = 1;
    f[0][1] = 0;
    f[1][0] = 1;
    f[1][1] = 1;
    f[2][0] = 1;
    f[2][1] = 1;

    while (f[(n + 2) % 3][0] < fs) {
        
        f0 = f[(n + 2) % 3];
        f1 = f[n % 3];
        f2 = f[(n + 1) % 3];

        //f0 = f1 + f2
        int len = max(f0[0], f1[0]) > f2[0] ? max(f0[0], f1[0]) : f2[0];
        f0[0] = len;

        for (int i = 1; i <= len; i++) {
            f0[i] = f1[i] + f2[i];
        }

        //carry
        for (int i = 1; i <= f0[0]; i++) {

            if (f0[i] < 10) {
                continue;
            }

            f0[i + 1] += f0[i] / 10;
            f0[i] %= 10;
            f0[0] += (i == f0[0]);
            
        }

        n++;
        
    }

    return (n - 1);

}

int main() {

    int n;

    cin >> n;

    cout << fib(n) << endl;;

    return 0;
}
