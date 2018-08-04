/*************************************************************************
	> File Name: eular_34.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月01日 星期日 14时14分38秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 2177280;

int main () {

    int factorial[10];
    int ans;
    
    ans = 0;

    //1--9的阶乘打表；
    for (int i = 1; i < 10; i++) {
        factorial[0] = i;
        factorial[i] = 1;
        while (factorial[0]) {
            factorial[i] *= factorial[0];
            factorial[0]--;
        }
    }

    factorial[0] = 1;

    for (int i = 10; i <= maxn; i++) {
        int num = i;
        int sum = 0;
        while (num) {
            int temp = num % 10;
            num /= 10;
            sum += factorial[temp];
        }
        if (sum == i) {
            ans += i;
        }
    }

/*
    int x;
    cin >> x;
    cout << "factorial[9] * n = " << factorial[9] * x << endl;
    cout << "10 ^ n = " << pow(10, x) << endl;
    if (factorial[9] * x > pow(10, x)) {
        cout << "g(n) > f(n)" << endl;
    }
    else {
        cout << "g(n) < f(n)" << endl;
    }
    cout << "9! = " << factorial[9] << endl;
*/
    cout << ans << endl;

    return 0;
}
