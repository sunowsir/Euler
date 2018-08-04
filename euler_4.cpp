/*************************************************************************
	> File Name: eular_4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月26日 星期二 09时47分36秒
 ************************************************************************/

#include<iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool is_palindromic_num(int is_judged_num) {
    string str_num, res_str_num;
    std::stringstream ss;
    ss << is_judged_num;
    str_num = res_str_num = ss.str();
    reverse(res_str_num.begin(), res_str_num.end());
    if (res_str_num == str_num) {
        return true;
    }
    return false;
}

int bits_num(int another_factor) {
    
    int bisn, every_bitn;
    bisn = 0;

    while (another_factor != 0) {
        every_bitn = another_factor % 10;
        another_factor /= 10;
        bisn++;
    }
    
    return bisn;
}

int main () {

    int max_palindromic_num = 998001;

    for (int i = max_palindromic_num; i > 10001; i--) {
        bool jump_back = false;
        //如果i是回文数
        if (is_palindromic_num(i)) {
            for (int j = 999; j > 100; j--) {
                //找出i的一个三位数因数，并且另一个因数也必须是三位数
                if (i % j == 0 && bits_num(i / j) == 3) {
                    cout << i << "=" << j << "*" << i / j << endl;
                    jump_back = true;
                    break;
                }
            }
        }
        if (jump_back) {
            break;
        }
    }


    return 0;
}
