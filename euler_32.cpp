/*************************************************************************
    * File Name: euler_32.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <inttypes.h>
using namespace std;

int bit;
bool bnum[10];
bool bans[10000];

bool split(int n) {

    while (n) {
        bit++;
        int now_num = n % 10;
        if (!now_num || bnum[now_num]) {
            return false;
        }
        bnum[now_num] = true;
        n /= 10;
    }

    return true;

}

bool judge(int i, int j) {
    
    bit = 0;
    memset(bnum, false, sizeof(bnum));
    if (!split(i)) {
        return false;
    }
    if (!split(j)) {
        return false;
    }
    if (!split(i * j)) {
        return false;
    }
    if (bit < 9) {
        return false;
    }
    return true;
}

int main() {

    int64_t ans = 0;

    memset(bans, false, sizeof(bans));
    for (int i = 1; i < 10000; i++) {
        for (int j = 1; j < 10000; j++) {
            if (judge(i, j) && !bans[i * j]) {
                bans[i * j] = true;
                ans += i * j;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
