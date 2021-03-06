/***********************************************
# Title: PlusOne
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/19
/*
动态数组存放了一些个位数字(正数)，组成一个大数。将这个数加1。
例如：
A = [2,3,1,1,4],
return [2,3,1,1,5]
A = [7,8,9],
return [7,9,0].
格式：
第一行输入一个正整数n，接下来的一行，输入数组A[n](每一位都是正数且为个位数)。
最后输出新的数组。
样例1
输入：
5
8 9 9 9 9
输出：
9 0 0 0 0
*/

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