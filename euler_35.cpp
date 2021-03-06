/*************************************************************************
    * File Name: euler_35.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 1000000

bool Is_Prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool judge(int n) {
    
    int len = floor(log10(n)) + 1;

    for (int i = 0; i < len; i++) {
        if (!Is_Prime(n)) {
            return false;
        }
        n = n / 10 + n % 10 * pow(10, len - 1);
    }

    return true;

}

int main() {

    int ans = 0;

    for (int i = 2; i < MAX_N; i++) {
        if (judge(i)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
