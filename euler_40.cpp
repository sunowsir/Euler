/*************************************************************************
    * File Name: euler_40.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int power[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int len(int num) {
    return floor(log10(num)) + 1;
}

int get_num(int n, int len, int need) {
    
    int num = n;

    while (n) {
        if (len == need) {
            return n % 10;
        }
        n /= 10;
        len--;
    }

}

int main() {

    int n,i , max_len, ans;
    
    i = 0;
    n = 1;
    ans = 1;
    max_len = 0;

    while (max_len <= power[6]) {
        
        max_len += len(n);
        if (max_len >= power[i]) {
            int temp = get_num(n, max_len, power[i]);
            ans *= temp;
            i++;
            cout << "temp = " << temp << endl;
        }
        n++;
        
    }

    cout << ans << endl;

    return 0;
}
