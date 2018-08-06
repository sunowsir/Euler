/*************************************************************************
	> File Name: euler_29.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年08月01日 星期三 12时32分16秒
 ************************************************************************/

#include <set>
#include <cstdio>
#include <iostream>
using namespace std;

set<string> s;
int ans = 0;
int nnum = 0;
int *nums[100000] = {0};

void same(int *mul) {
    int judge_num = 0;
    //遍历二维数组，在二维数组中是否有mul
    for (int i = 0; i < nnum; i++) {
        cout << "20:::" << endl;
        //如果二位数组本行大数长度都与mul不等，直接判定不相等；
        if (nums[i][0] != mul[0]) {
            judge_num++;
            continue;
        }
        for (int j = 1; j <= mul[0]; j++) {
            //哪怕有一位数不相等，就直接判断下一个大数；
            if (nums[i][j] != mul[j]) {
                judge_num++;
                break;
            }
        }
    }

    if (judge_num == nnum) {
        nums[nnum][0] = mul[0];
        for (int i = 1; i <= mul[0]; i++) {
            nums[nnum][i] = mul[i];
        }
        nnum++;
        ans++;
    }
}

int num(int a, int b) {
    
    int mul[100000] = {1, 1};

    //乘法，计算a的b次幂
    //b个a相乘
    for (int i = 0; i < b; i++) {
        //把a累乘进mul数组
        for (int j = 1; j <= mul[0]; j++) {
            mul[j] *= a;
        }
        
        //处理进位
        for (int j = 1; j <= mul[0]; j++) {
            if (mul[j] < 10) {
                continue;
            }
            mul[j + 1] += mul[j] / 10;
            mul[j] %= 10;
            mul[0] += (j == mul[0]);
        }
    }


    string mul_num = "";
    for (int i = mul[0]; i > 0; i--) {
        char temp[5];
        sprintf(temp, "%d", mul[i]);
        mul_num += temp[0];
    }

    //cout << mul_num << endl;
    s.insert(mul_num);
  
    /*
    */


    //same(mul);

}

int main() {

    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            num(i, j);
        }
    }

    string temp = "";
    for (set<string>::iterator i = s.begin(); i != s.end(); i++) {
        if (temp == *i) {
            continue;
        }
        ans++;
        temp = *i;
        cout << *i << endl; 
    }

    cout << endl  << ans << endl;

    return 0;
}
