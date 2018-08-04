/*************************************************************************
	> File Name: eular_30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月30日 星期六 08时12分38秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 354294; //9^5 * 6

int Split_Sum(int num) {

    int sum, n;
    sum = 0;
    n = num;

    while (num) {
        sum += pow(num % 10, 5);
        num /= 10;
    }

    return sum == n;

}

int main () {

    int ans = 0;

    for (int i = 2; i <= maxn; i++) {
        if (Split_Sum(i)) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
