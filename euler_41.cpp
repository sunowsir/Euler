/*************************************************************************
    * File Name: euler_41.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

bool Is_Prime(int64_t num) {
    
    for (int64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;

}

int num[10] = {0};

bool Is_Pand(int64_t n) {
    
    while (n) {
        
        int every_num = n % 10;

        if (num[every_num]) {
            return false;
        }

        num[every_num] = 1;

        n /= 10;
    }

    return true;

}

int main () {

    for (int64_t i = 1; i < 9876543210; i++) {
        
    }

    return 0;
}
