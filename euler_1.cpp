/*************************************************************************
	> File Name: eular_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 14时21分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {

    int sum3, sum5, sum15;

    sum3 = (3 + 999) * 333 / 2;
    sum5 = (5 + 995) * 199 / 2;
    sum15 = (15 + (1000 / 15) * 15) * (1000 / 15)  / 2;

    cout << sum3 + sum5 - sum15 << endl;

    return 0;
}
