/*************************************************************************
	> File Name: eular_13.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月24日 星期二 16时23分16秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

char num[55];
int ans[55] = {1, 0};

int main () {

    for (int i = 0; i < 100; i++) {
        //读入
        cin >> num;
        int len = strlen(num);
        //更新ans长度
        if (ans[0] < len) {
            ans[0] = len;
        }
        //做加法
        for (int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');
        }
        //处理进位
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) {
                continue;
            }
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
        
    }

    for (int i = ans[0]; i > ans[0] - 10; i--) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
