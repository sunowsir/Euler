/*************************************************************************
	> File Name: euler_26.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 09时27分30秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int get_len(int d) {
    
    int dnum[1010] = {0};

    int rem, n;

    rem = 1;
    n = 1;

    //余数不为零才可以继续计算
    //rem如果出现过就可以求出循环节长度
    while (rem != 0 && dnum[rem] == 0) {
        //存储第一次rem出现的位置
        dnum[rem] = n;
        //计算下一个余数
        rem = rem * 10 % d;
        n++;
    }

    return n - dnum[rem];

}


    
int main () {

    int ans, max_len;

    ans = 0;
    max_len = -1;
    
    for (int i = 1; i < 1000; i++) {
        int temp = get_len(i);
        if (max_len < temp) {
            max_len = temp;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
