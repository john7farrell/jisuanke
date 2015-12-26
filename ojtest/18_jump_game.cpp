/***********************************************
# Title: jump game
# Author : johnfarrell  
# Date   : 2015-12-22
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/18
#include<iostream>

int main () {
    int n;
    scanf("%d", &n);
    int *a = new int[n];
    int i = 0;
    int sign = 0;
    if (n<=1) sign = 1;
    while(i<n) {
        scanf("%d", &a[i]);
        i++;
    }
    for (i=0;i<n-1;i += a[i]) {
        if (a[i]+i >= n-1) sign = 1;
        if (a[i]+i < n-1 && a[i] == 0) break;
    }
    if (sign==1) {
        printf("true");
    } else printf("false");
    return 0;
}