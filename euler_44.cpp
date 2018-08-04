/*************************************************************************
	> File Name: eular_44.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月27日 星期五 16时23分06秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

bool is_pentagonal(int64_t x) {
    int64_t head, tail, mid;

    head = 1;
    tail = 10000;
    
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) {
            return true;
        }
        else if (pentagonal(mid) > x) {
            tail = mid - 1;
        }
        else {
            head = mid + 1;
        }
    }

    return false;

}

int main () {

    int64_t i, j, ans;

    j = 1;
    i = 0;
    ans = INT64_MAX;

    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        
        j++;
        i = j - 1;

        do {

            int64_t diff = pentagonal(j) - pentagonal(i);
            int64_t with = pentagonal(j) + pentagonal(i);
            
            if (is_pentagonal(with) && is_pentagonal(diff)) {
                if (ans > diff) {
                    ans = diff;
                    cout << "Pi = " << i << "  Pj = " << j << "  Pi - Pj = " << ans << endl;
                }
            }

            i--;
            
        } while (i > 0 && pentagonal(j) - pentagonal(i) < ans);
    }

    cout << ans << endl;

    return 0;
}
