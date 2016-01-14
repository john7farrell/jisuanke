/***********************************************
# Title: singleNumber
# Author : johnfarrell  
# Date   : 2015-12-22
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/15
/*
给定一个数组，除了一个数出现1次之外，其余数都出现3次。找出出现一次的数。
如：{1, 2, 1, 2, 1, 2, 7}, 找出7.
格式：
   第一行输入一个数n，代表数组的长度，接下来一行输入数组A[n],(输入的数组必须满足问题描述的要求),最后输出只出现一次的数。
要求：
   你的算法只能是线性时间的复杂度，并且不能使用额外的空间哦～
样例1
输入：
4
0 0 0 5
输出：
5
*/
//*Reference
//*http://www.cnblogs.com/wei-li/p/SingleNumberII.html
#include<iostream>
// return once from others twice
int singleNumberI(int A[], int n) {
    int res = 0;
    for(int i = 0; i < n; i++){
        res ^= A[i];
    }
    return res;
}
// return once from others three times
int singleNumberII(int A[], int n) {
    int ones = 0, twos = 0, threes = 0;
    for (int i=0;i<n;i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones ^= threes;
        twos ^= threes;
    }
    return ones;
}
int main () {
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    for (int i=0;i<n;i++) {
        scanf("%d", &A[i]);
    }
    printf("%d", singleNumberII(A, n));
    return 0;
}