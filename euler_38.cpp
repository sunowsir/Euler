/*************************************************************************
	> File Name: eular_38.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月01日 星期三 15时41分52秒
 ************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int valid(int x) {
    
    int num[10] = {0};
    int n, digit;
    n = 0;
    digit = 0;

    do{

        n++;
        int  y = x * n;

        while (y) {
            
            if (y % 10 == 0) {
                return 0;
            }
            if (num[y % 10]) {
                return 0;
            }
            num[y % 10] = 1;
            y /= 10;
            digit++;

        }

    } while (digit < 9);

    if (digit < 9) {
        return 0;
    }

    int ret_num = 0;

    for (int i = 1; i <= n; i++) {
        ret_num = ret_num * pow(10, floor(log10(x * i)) + 1) + x * i;
    }

    return ret_num;

}
int main () {

    int ans = 0;

    for (int i = 1; i < 10000; i++) {
        int temp = valid(i);
        if (temp != 0) {
            ans = max(ans, temp);
            cout << i << " * (1, 2, 3...) = " << temp << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
