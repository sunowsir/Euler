/*************************************************************************
	> File Name: euler_26.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月01日 星期三 11时48分27秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int get_len(int n) {
    
    int num[1005] = {0};
    int rem, index;
    rem = 1;
    index = 0;

    //判断余数是否为０，并且该余数是否第一次出现
    //如果之前已经出现过，就已经可以求出该分数的循环节。
    while (rem != 0 && num[rem] == 0) {

        num[rem] = index;
        rem = rem * 10 % n;
        index++;
        
    }

    return index - num[rem];

}

int main () {

    int max_id, max_len;

    for (int i = 999; i > 10; i--) {
        int now_len = get_len(i);
        if (max_len < now_len) {
            max_len = now_len;
            max_id = i;
        }
    }

    cout << max_id << "=>" << max_len << endl;

    return 0;
}
