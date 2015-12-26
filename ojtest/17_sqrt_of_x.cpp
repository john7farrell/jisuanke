/***********************************************
# Title: sqrt of x
# Author : johnfarrell  
# Date   : 2015-12-21
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/17
//*Reference
//*http://www.cnblogs.com/chenyg32/p/3306893.html
#include<iostream>
#include <cmath> 
using namespace std; 
//*using 'printf' will cause mistake in this question somehow...
//run out of time!!!
/*int sqrt(int x) {
    if (x<4) return 1;
    else {
        for (int i=1;i<x;i++) {
            //printf("%d\n", i);
            //printf("%d\n", x);
            if (i*i==x) return i;
            if (i*i>x) return i-1;
        }
        return 0;
    }
}*/
//Newton's method :) Very fast!
int sqrt(int x)  
{  
    double t=1.0;       
    while(abs(t*t-x)>1e-5)       
    {       
        t=(x/t+t)/2.0;       
    }       
    return t;    
}  
int main () {
    int x;
    while(cin>>x) {
        cout<<sqrt(x)<<endl;
    }
    return 0;
}