/*************************************************************************
	> File Name: euler_30.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 15时15分06秒
 ************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

#define MAX_N 531442

bool judge(int i) {
    int num, sum_num;
    num = i;
    sum_num = 0;

    while (num) {
        sum_num += pow(num % 10, 5);
        num /= 10;
    }

    return sum_num == i;

}

int main () {

    int ans = 0;

    for (int i = 2; i <= MAX_N; i++) {
        if (judge(i)) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
