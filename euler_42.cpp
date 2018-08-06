/*************************************************************************
	> File Name: euler_42.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月01日 星期三 16时14分01秒
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <inttypes.h>
#include "euler_42.h"
using namespace std;

int fun(int64_t n) {
    return n * (n + 1) >> 1;
}

bool judge(int64_t n) {
    int64_t num, left, right;

    num = n;
    left = 1;
    right = 10000;


    while (left <= right) {
        int mid = (left + right) >> 1;
        if (fun(mid) == num) {
            return true;
        }
        else if (fun(mid) > num) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return false;

}

int main() {

    int64_t i, ans;
    i = 0;
    ans = 0;


    while (word[i].size() != 0) {
        int num = 0;
        for (int64_t j = 0; j < word[i].size(); j++) {
            
            num += word[i][j] - 'A' + 1;
        }
        if (judge(num)) {
            ans++;
        }
        i++;
    }

    cout << ans << endl;


    return 0;
}
