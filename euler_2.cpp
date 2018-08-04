/*************************************************************************
	> File Name: eular_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 15时21分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main () {

    int a, b, sum;
    a = 0;
    b = 1;
    sum = 0;
    
    while (a + b <= 4000000) {
        int temp = a + b;
        a = b;
        b = temp;
        if (b & 1) {
            continue;
        }
        sum += b;
    }

    cout << sum << endl;
    return 0;
}
