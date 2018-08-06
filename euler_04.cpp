/*************************************************************************
	> File Name: euler_04.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 14时46分26秒
 ************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

bool judge(int i, int j) {
    int num, n, rec_num, x;
    x = 1;
    num = n = i * j;

    rec_num = n % 10;
    n /= 10;

    while(n) {
        rec_num *= 10;
        rec_num += (n % 10);
        n /= 10;
        x++;
    }

    return rec_num == num;
}

int main () {

    int ans = -1;
    bool flag = true;
    //找出两个三位数
    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > 99; j--) {
            if (judge(i, j)) {
                ans = max(ans, i * j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
