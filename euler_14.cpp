/*************************************************************************
	> File Name: euler_14.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 1000000

int keep[MAX_N + 5] = {0};

int64_t get_len(int64_t num) {

    if (num == 1) {
        return 1;
    }

    //先判断num的范围，再判断记忆数组。
    //否则会段错误
    if (num <= MAX_N && keep[num]) {
        return keep[num];
    }

    int ans;
    
    if (num & 1) {
        ans = get_len(3 * num + 1) + 1;
    }
    else {
        ans = get_len(num / 2) + 1;
    }

    if (num <= MAX_N) {
        keep[num] = ans;
    }

    return ans;

}

int main() {

    int64_t max_len, max_ip;

    keep[1] = 1;
    max_len = -1;
    max_ip = 0;

    for (int64_t i = 1; i < MAX_N; i++) {
        int len = get_len(i);
        if (len > max_len) {
            max_ip = i;
            max_len = len;
        }
    }

    cout << max_ip << " => " << max_len << endl;

    return 0;
}
