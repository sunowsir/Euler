/*************************************************************************
    * File Name: euler_9.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 1000

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {

    bool flag = true;

    for (int i = 1; i < MAX_N && flag; i++) {
        for (int j = i + 1; j < MAX_N && flag; j++) {
            if (gcd(j, i) == 1) {
                int a = 2 * i * j;
                int b = j * j - i * i;
                int c = j * j + i * i;
                int sum = a + b + c;
                if (MAX_N % sum == 0) {
                    int power = 1;
                    if (sum < MAX_N) {
                        power = pow(MAX_N / sum, 3); 
                    }
                    cout << power  * a * b * c << endl;
                    flag = false;
                    break;
                }
            }
        }
    }

    return 0;
}
