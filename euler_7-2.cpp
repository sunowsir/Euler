/*************************************************************************
	> File Name: eular_7-2.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月24日 星期二 10时30分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 200000

void is_Prime(int *prime) {

    //is_prime数组的作用是标记合数为１，
    //prime数组的作用是存储素数，
    //二者的作用并不冲突
    //而prime数组中合数的位置无用。
    //故可以去掉is_prime数组，用prime数组代替。
    for (int i = 2; i < MAX_N; i++) {
        
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

}

int main () {

    int prime[MAX_N + 5] = {0};

    is_Prime(prime);

    cout << prime[10001] << endl;


    for (int i = 1; prime[0] < 1000; i++) {
        cout << "*";
        if (i % 5 == 0) {
            cout << endl;
        }
        cout << prime[i] << " ";
    }
    cout << endl;

    return 0;
}
