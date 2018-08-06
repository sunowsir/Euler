/*************************************************************************
	> File Name: eular_8.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月15日 星期日 18时45分23秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <string.h>
#include <inttypes.h>
using namespace std;

int main () {

    char word[1005] = {0}, temp[1005] = {0};
    int64_t ans, zero, max;
    ans = 1;
    zero = 0;
    max = 0;

    while(~scanf("%s", temp)) {
        strcat(word, temp);
    }

    for (int i = 0; word[i]; i++) {

        if (word[i] != '0') {
            ans *= word[i] - '0';
        }
        else {
            zero++;
        }
        if (i >= 13) {
            if (word[i - 13] != '0') {
                ans /= word[i - 13] - '0';
            }
            else {
                zero--;
            }
        }


        if (zero == 0 && ans > max) {
            max = ans;
        }

    }

    cout << max << endl;

    return 0;
}
