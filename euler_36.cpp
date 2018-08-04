/*************************************************************************
	> File Name: eular_36.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月01日 星期日 16时39分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool is_palindromic (int n, int x) {

    int num, rec_num;

    num = n;
    rec_num = 0;

    while (n) {
        rec_num = rec_num * x + n % x;
        n /= x;
    }
    
    return num == rec_num;
}

int main () {

    int ans = 0;

    for (int i = 1; i <= 1000000; i++) {
        if (!is_palindromic(i, 2) || !is_palindromic(i, 10)) {
            continue;
        }
        ans += i;
    }

    cout << ans << endl;

    return 0;
}
