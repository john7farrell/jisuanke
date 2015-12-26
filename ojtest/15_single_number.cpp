/***********************************************
# Title: singleNumber
# Author : johnfarrell  
# Date   : 2015-12-22
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/15
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