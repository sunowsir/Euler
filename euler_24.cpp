/*************************************************************************
    * File Name: euler_24.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int fac[10] = {0};
int num[10] = {0};

void Get_Fac_Init() {
   
    fac[0] = 1;
    num[0] = 0;

    for (int i = 1; i < 10; i++) {
        num[i] = 0;
        fac[i] = i * fac[i - 1];
    }

    return ;

}

int Get_Num(int loc, int sta) {
   
    int i, index;

    i = -1;

    //get the location of number where the current location should be placed.
    index = (sta / fac[loc]) + 1;

    while (index) {
        i++;

        //datermine if the current number i is available.
        if (!num[i]) {
            index--;
        }
    }

    num[i] = 1;

    return i;
    
}

int main() {

    //call initialization function.
    Get_Fac_Init();

    int n, k;

    cin >> n >> k;

    k--;

    for (int i = n - 1; i >= 0; i--) {

        //get number that should be placed in the current location;
        int num = Get_Num(i, k);
        
        cout << num;

        //find the remainder of k divided by the factorial of i,
        //and find the number of states remaining.
        k %= fac[i];
    }
    cout << endl;

    return 0;
}
