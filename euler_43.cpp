/*************************************************************************
	> File Name: eular_43.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月28日 星期六 15时37分39秒
 ************************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20

int prime[MAX_N + 5] = {0};
int ans[15] = {1, 0};

void Linear_sieve() {
    for (int i = 2; i < MAX_N + 10; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i * prime[j] == 0) {
                break;
            }
        }
    }

    return;

}

bool judge(string num) {

    for (int i = 1; i <= num.size() - 3; i++) {
        int son_num;
        string son_str = num.substr(i, 3);
        stringstream change;
        change << son_str;
        change >> son_num;
        if (son_num % prime[i] != 0) {
            return false;
        }
    }

    return true;

}

void adds(string num) {
    //更新长度
    int len = num.size();
    if (ans[0] < len) {
        ans[0] = len;
    }
    //做加法
    for (int i = 0; i < len; i++) {
        ans[len - i] += (num[i] - '0');
    }
    //处理进位
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) {
            continue;
        }
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
}

int main () {

    //线性筛
    Linear_sieve();

    string pen_num = "0123456789";

    //利用全排列函数枚举所有的0-9全数
    while (next_permutation(pen_num.begin(), pen_num.end())) {
        if (pen_num[0] == '0') {
            continue;
        }

        //如果符合题意，把该全数加到结果中
        if (judge(pen_num)) {
            cout << pen_num << endl;
            adds(pen_num);
        }
        
    }

    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
