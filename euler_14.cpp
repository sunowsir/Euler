/*************************************************************************
	> File Name: euler_14.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月31日 星期二 17时30分45秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

#define MAX_N 1000000

int keep[MAX_N + 5] = {0};

int64_t len(int64_t num) {

    if (num == 1) {
        return 1;
    }

    if (num <= MAX_N && keep[num]) {
        return keep[num];
    }

    int temp;

    if (num & 1) {
        temp = len(3 * num + 1) + 1;
    } else {
        temp =  len(num >> 1) + 1;
    }

    if (num <= MAX_N) {
        keep[num] = temp;
    }

    return temp;

}


int main () {

    int max_ip, max_len;
    max_len = -1;

    for (int i = 1; i <= MAX_N; i++) {
        int temp = len(i);
        if (temp > max_len) {
            max_len = temp;
            max_ip = i;
        }
    }

    cout << max_ip << endl;

    return 0;
}
