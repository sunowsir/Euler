/*************************************************************************
    * File Name: euler_19.cpp
    * Author:    sunowsir
    * GitHub:    github.com/sunowsir
    * Mail:      sunow.wang@gmail.com
*************************************************************************/

#include <iostream>
using namespace std;

int get_w(int y, int m, int d) {

    if (m == 1 || y == 2) {
        y--;
        m += 12;
    }

    int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + y / 400) % 7;
	return w;
}



 
int getw(int y, int m, int d){

	if(m == 1 || m == 2){
		y--;
		m += 12;
	}

	int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + y / 400) % 7;
	return w;
}


int main() {

    int ans;

    ans = 0;
    
    for (int y = 1901; y <= 2000; y++) {
        
        for (int m = 1; m <= 12; m++) {
            if (getw(y, m, 1) == 6) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
