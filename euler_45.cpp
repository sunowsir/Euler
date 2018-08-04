/*************************************************************************
	> File Name: eular_45.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月28日 星期六 19时57分49秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

int64_t Pentagonal (int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal (int64_t n) {
    return n * (2 * n - 1);
}

bool Half_fold (int64_t (* num)(int64_t), int64_t len, int64_t search_num) {

    int64_t left, right, mid;
    left = 1;
    right = len;

    while (left <= right) {
        mid = (left + right) >> 1;
        if (num(mid) == search_num) {
            return true;
        }
        else if (num(mid) > search_num) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return false;

}

int main () {

    int64_t ans = 144;

    while (Half_fold(Pentagonal, 2 * ans, Hexagonal(ans)) == 0) {
        ++ans;
    }

    cout << Hexagonal(ans) << endl;

    return 0;
}
