/***********************************************
# Title: jump game
# Author : johnfarrell  
# Date   : 2015-12-22
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/18
/*
给定一个非负整数数组，假定你的初始位置为数组第一个下标。
数组中的每个元素代表你在那个位置能够跳跃的最大长度。
请确认你是否能够跳跃到数组的最后一个下标。
例如：
A = [2,3,1,1,4],
return true.
A = [3,2,1,0,4],
return false.
格式：
第一行输入一个正整数n，接下来的一行，输入数组A[n]。如果能跳到最后一个下标，输出“true”，否则输出“false”
样例1
输入：
5
2 0 2 0 1
输出：
true
*/
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