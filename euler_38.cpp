/*************************************************************************
	> File Name: eular_38.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月27日 星期五 15时41分52秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int valid(int x) {
    
    int num[10] = {0};
    int n, digit;
    n = 0;
    digit = 0;

    //求乘积并且利用抽屉原理判断乘积中各位数是否出现过
    do{

        n++;
        int  y = x * n;

        while (y) {
            
            if (y % 10 == 0) {
                return 0;
            }
            if (num[y % 10]) {
                return 0;
            }
            num[y % 10] = 1;
            y /= 10;
            digit++;

        }

    } while (digit < 9);

    //拼接后的全数的长度达不到９说明不可能是个全数
    if (digit < 9) {
        return 0;
    }

    int ret_num = 0;

    //拼接
    for (int i = 1; i <= n; i++) {
        ret_num = ret_num * pow(10, floor(log10(x * i)) + 1) + x * i;
    }

    return ret_num;

}
int main () {

    int ans = 0;

    for (int i = 1; i < 10000; i++) {
        int temp = valid(i);
        if (temp != 0) {
            ans = max(ans, temp);
            cout << i << " * (1, 2, 3...) = " << temp << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
