/*************************************************************************
	> File Name: eular_4-2.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月22日 星期日 09时26分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool is_palindromic(int n) {
    int num, rec_num;
    num = n;
    rec_num = 0;
    while (n) {
        rec_num = rec_num * 10 + n % 10;
        n /= 10;
    }

    return num == rec_num;

}

int main () {

    int ans = 0;

    for (int i = 1; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (i * j < ans) {
                continue;
            }
            if (!is_palindromic(i * j)) {
                continue;
            }
            ans = i * j;
        } 
    }

    cout << ans << endl;

    return 0;
}
