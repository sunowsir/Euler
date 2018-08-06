/*************************************************************************
	> File Name: euler_39.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月01日 星期三 14时37分04秒
 ************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a,int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    
    int num[1010] = {0};
    int max_p, max_x;
    max_x = -1;

    for (int i = 1; i <= 1000; i++) {
        for (int j = i + 1; j * j <= 1000; j++) {
            int a, b, c;
            if (gcd(i, j) == 1) {
                a = 2 * i * j;
                b = j * j - i * i;
                c = j * j + i * i;
                int len = a + b + c;
                for (int i = 1; i < 1000; i++) {
                    //int power = pow(i, 3);
                    //新边长需要在１０００以内
                    if (len * i < 1000) {
                        num[len * i]++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (max_x < num[i]){
            max_x = num[i];
            max_p = i;
        }
    }

    cout << max_p << endl;


    return 0;
}
