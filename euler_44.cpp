/*************************************************************************
    * File Name: euler_44.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
#include <inttypes.h>
using namespace std;

int64_t get_pan(int64_t n) {
    return n * (3 * n - 1) / 2;
}

bool is_pan(int64_t snum,int64_t (*num)(int64_t), int64_t slen) {
    int64_t l, r;

    l = 1;
    r = slen;

    while (l <= r) {
        int64_t mid = (l + r) / 2;
        if (num(mid) == snum) {
            return true;
        } else if (num(mid) > snum)  {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return false;

}

int main() {

    int64_t i, j, ans;

    i = 1;
    ans = INT64_MAX;

    while (get_pan(i + 1) - get_pan(i) < ans) {


        i++;
        j = i;

        do {
            
            
            /*
            //if i and j don't pentagonal numbers ,continue;
            if (!is_pan(i, get_pan, i) || !is_pan(j, get_pan, j)) {
                continue;
            }
            */

            //find the sum and the difference of i and j;
            int64_t with = get_pan(i) + get_pan(j);
            int64_t diff = get_pan(i) - get_pan(j);

            //all of with number and different number is pentagonal numbers
            //and make the diff variable is the smallest;
            if (is_pan(with, get_pan, with) && is_pan(diff, get_pan, diff) && diff < ans) {
                ans = diff;
            }
            
            //if j varilable is placed at beginning , j == 0 will occur
            j--;
            
        } while (j > 0 && get_pan(i) - get_pan(j) < ans);

    }

    cout << ans << endl;

    return 0;
}
