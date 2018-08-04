/*************************************************************************
	> File Name: eular_22.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月30日 星期一 10时06分53秒
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <inttypes.h>
#include <algorithm>
#include "eular_22.h"
using namespace std;

int main () {
    
    int i;
    int64_t ans;

    i = 0;
    ans = 0;

    //通过循环计算字符串个数
    while (names[i++].size() != 0); 
    
    sort(names, names + i - 1);
    
    i = 0;

    int temps;

    //遍历所有的字符串
    while (names[i].size() != 0) {

        int temp, word_num;
        
        //记录排位
        temp = (i + 1);

        word_num = 0;
        
        //计算字母值
        for (int j = 0; j < names[i].size(); j++) {
            word_num += (names[i][j] - 64);
        }

        ans += temp * word_num;
        i++;
    }

    cout << ans << endl;

    return 0;

}
