/*************************************************************************
    * File Name: euler_43.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int prime[7] = {2, 3, 5, 7, 11, 13, 17};

bool judge(string pan) {
    

    for (int i = 1; i < 8; i++) {
        stringstream ss;
        string temp = pan.substr(i, 3);
        int temp_num;
        ss << temp;
        ss >> temp_num;
        if (temp_num % prime[i - 1] != 0) {
            return false;
        }
    }

    return true;

}

int ans[20] = {1, 0};

void add(string num) {
    
    int len = num.size();
    if (ans[0] < len) {
        ans[0] = len;
    }

    for (int i = 0; i < len; i++) {
        ans[len - i] += (num[i] - '0');
    }

    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) {
            continue;
        }
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }

    return ;

}

int main() {
   
    string pan = "0123456789";

    while (next_permutation(pan.begin(), pan.end())) {
        if (pan[0] == '0') {
            continue;
        }
        if (judge(pan)) {
            add(pan);
        }
    }

    for (int i = ans[0]; i > 0; i--)  {
        cout << ans[i];
    }
    cout << endl;

    

    return 0;
}
