/***********************************************
# Title: PlusOne
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/19

#include<iostream>

int main () {
    int n;
    scanf("%d", &n);
    n++;
    int *a = new int[n];
    a[0] = 0;
    int i=1;
    for (;i<n;i++) {
        scanf("%d", &a[i]);
    }
	int j = n;
    n = 1;// n as a flag
    for (--i;i>=0;i--) {
        if (n==1 && a[i]==9) { 
            a[i] = 0;
            n = 1; 
            //printf("%d %d %d\n", i,n,a[i]);
        } else {
            a[i] += n;
            n = 0;
            //printf("%d %d %d\n", i,n,a[i]);
        }
    }
    if (a[0]!=0) printf("%d ", *a);
    for (i=1;i<j;i++) {
        printf("%d ", a[i]);
    }
	//system("pause");
    return 0;
}