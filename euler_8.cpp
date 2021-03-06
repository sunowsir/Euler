/*************************************************************************
	> File Name: euler_8.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <inttypes.h>
using namespace std;

int main() {

    int64_t ans, max, zero;
    string word, input;

    ans = 1;
    max = 0;
    zero = 0;
    word = "";
    input = "";

    while (cin >> input) {
        word += input;
    }

    for (int i = 0; i < word.size(); i++) {
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
