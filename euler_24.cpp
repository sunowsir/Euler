/*************************************************************************
	> File Name: eular_24.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月29日 星期日 17时52分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int factorial[10] = {0};
int nums[10] = {0};

void init() {

    factorial[0] = nums[0] = 1;

    for (int i = 1; i < 10; i++) {
        factorial[i] = i * factorial[i - 1];
        nums[i] = 1;
    }
}

int jump_num(int n, int k) {
    int index, i;

    index = (k / factorial[n]) + 1;
    i = -1;

    while (index > 0) {
        i++;
        index -= nums[i];
    }

    nums[i] = 0;

    return i;

}

int main() {

    int n, k;

    cin >> n >> k;
    init();
    k--;

    for (int i = n - 1; i >= 0; i--) {
        int num = jump_num(i, k);
        cout << num;
        k %= factorial[i];
    }

    cout << endl;

    return 0;
}
