/*************************************************************************
	> File Name: eular_17.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月24日 星期二 19时12分34秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

int main () {

    int ans = 0;

    char const  *word[] = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", //1-9:9个
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", //11-19:9个
        "ten" , "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" //10, 20, ..., 90:9个
    };

    //100以内；
    for (int i = 0; i < 9; i++) {
        //1000中的one
        if (word[i] == "one") {
            ans += strlen(word[i]);
        }
        // 1-9中每个数在100以内有9个，1000以内有10组
        // 1-9中每个数在100-999中10组中的一组中含有100个
        // strlen(word[i]) * 9 * 10 + 100
        ans += strlen(word[i]) * 190;
        //11-19中每个数在每一百个中含有1个，1000之内每个数含有10个
        ans += strlen(word[i + 9]) * 10;
        //10在每100组里含有1个，1000以内共有10个
        if (word[i + 18] == "ten") {
            ans += 3 * 10;
        } else {
            //除了10以外的整10的整数在每100组中含有10个，1000以内共有100个
            ans += strlen(word[i + 18]) * 100;
        }
        //cout << word[i] << " " << word[i + 9] << " " <<word[i + 18] << endl;
    }

    //加上hundred、thousand、and
    cout << ans + 900 * 7 + 8 + 3 * 891 << endl;

    return 0;
}
