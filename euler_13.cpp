/*************************************************************************
	* File Name: euler_13.cpp
	* Author:    sunowsir
	* GitHub:    github.com/sunowsir
	* Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int ans[100] = {1, 0};

void adds(string num) {
    int num_len = num.size();
    //更新ans的长度ans[0];
    if (ans[0] < num_len) {
        ans[0] = num_len;
    }

    for (int i = 0; i < num_len; i++) {
        //字符需减去字符０
        ans[num_len - i] += num[i] - '0';
    }

    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) {
            continue;
        }
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }

    return;

}

int main() {

    string num = "";

    while (cin >> num) {
        adds(num);
    }

    for (int i = ans[0]; i > ans[0] - 10; i--) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
