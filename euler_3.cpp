/*************************************************************************
	> File Name: eular_3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月24日 星期日 15时51分09秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long

int main () {

    ll num, max_factor;

    cin >> num;

    for (int i = 2; i <= num; i++) {
        bool try_fac = true;
        if (num % i == 0) {
            max_factor = num / i;
            for (ll j = 2; j <= sqrt(max_factor); j++) {
                if (max_factor % j == 0) {
                    try_fac = false;
                    break;
                }
            }
        }
        if (try_fac && num % i == 0) {
            break;
        }
        try_fac = true;
    }

    cout << max_factor << endl;

    return 0;
}
