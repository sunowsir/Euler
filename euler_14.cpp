/*************************************************************************
	> File Name: eular_14.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月24日 星期二 15时08分38秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;
#define MAX_N 1000000

int keep[MAX_N + 5] = {0};

int64_t Length(int64_t num) {

    if (num == 1) {
        return 1;
    }

    if (num <= MAX_N && keep[num]) {
        return keep[num];
    }

    int temp;

    if (num & 1) {
        temp = Length(3 * num + 1) + 1;
    } else {
        temp =  Length(num >> 1) + 1;
    }

    if (num <= MAX_N) {
        keep[num] = temp;
    }

    return temp;

}

int main() {

    int64_t last, last_ip;

    last = 0;
    last_ip = 0;

    for (int i = 1; i < MAX_N; i++) {
        
        int64_t length = Length(i);

        if (length > last) {
            last_ip = i;
            last = length;
        }
    }

    cout << last_ip << ":"  << last << endl;

    return 0;
}
