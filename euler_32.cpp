/*************************************************************************
	> File Name: eular_32.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月27日 星期五 14时26分41秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 10000

int nums[10] = {0};

int digit(int num) {
    return floor(log10(num)) + 1;
}

bool get_valid(int x, int *num) {
    while (x) {
        if (x % 10 == 0) {
            return false;
        }
        if (num[x % 10] == 1) {
            return false;
        }
        num[x % 10] = 1;
        x /= 10;
    }
    return true;
}

bool judge(int a, int b, int c) {
    int num[10] = {0};
    if (!get_valid(a, num)) {
        return false;
    }
    if (!get_valid(b, num)) {
        return false;
    }
    if (!get_valid(c, num)) {
        return false;
    }

    return true;
}

int valid[MAX_N] = {0};

int main () {

    int ans = 0;

    for (int i = 2; digit(i) + digit(i) + digit(i * i) <= 9; i++) {
        for (int j = 1; digit(i) + digit(j) + digit(i * j) <= 9; j++) {
            if (digit(i) + digit(j) + digit(i * j) < 9) {
                continue;
            }
            if (judge(i, j, i * j)) {
                ans += i * j * (1 - valid[i * j]);
                valid[i * j] = 1;
                cout << i << " * " << j << " = " << i * j << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
