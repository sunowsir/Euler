/*************************************************************************
    * File Name: euler_45.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

int64_t tnum(int64_t n) {
    return n * (n + 1) >> 1;
}

int64_t pnum(int64_t n) {
    return n * (3 * n - 1) >> 1;
}

int64_t hnum(int64_t n) {
    return n * (2 * n - 1);
}

bool search(int64_t (* nums)(int64_t), int64_t snum, int64_t len) {
    int l, r;
    l = 0;
    r = len;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums(mid) == snum) {
            return true;
        }
        else if (nums(mid) > snum) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return false;

}

int main() {

    int64_t ans = 144;
    
    //根据推导规律，五边形数一定是三角形数，所以不能查找某个三角形数是否是五边形数
    while (!search(pnum, hnum(ans), ans * 2) || !search(tnum, hnum(ans), ans * 2)) {
        ++ans;
    }

    cout << hnum(ans) << endl;

    return 0;
}
