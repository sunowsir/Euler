/*************************************************************************
	> File Name: eular_28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月29日 星期五 21时08分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {

    int ans = 1;

    for (int i = 3; i <= 1001; i += 2) {
        /*
        int a = i * i;
        int b = a - i + 1;
        int c = b - i + 1;
        int d = c - i + 1;
        int temp = a + b + c + d;
        */
        ans += 4 * i * i - 6 * i + 6;
    }

    cout << ans << endl;

    return 0;
}
