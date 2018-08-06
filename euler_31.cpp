/*************************************************************************
    * File Name: euler_31.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int w[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[201] = {0};

int main() {

    dp[0] = 1;

    for (int i = 0; i < 8; i++) {
        for (int j = w[i]; j < 201; j++) {
            dp[j] += dp[j - w[i]];
        }
    }

    cout << dp[200] << endl;

    return 0;
}
