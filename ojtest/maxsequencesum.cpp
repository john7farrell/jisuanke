/***********************************************
# Title: max subsequence sum
# Author : johnfarrell  
# Date   : 2015-12-25
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/21
//*Reference
//*Data Structures And Algorithm Analysis In C 2nd edition: 2.4.3 algo-4
#include<iostream>

//Original algo4 in the book can not handle the case that all negative elements!!!
int maxSqSum(int N, int a[], int flag) 
{
    int thisSum = 0;
    int maxSum = 0;
    if(flag==0)
    {
        maxSum = a[0];
        for(int i=0;i<N;i++)    
        {
            thisSum = a[i];
            if(thisSum>maxSum) maxSum=thisSum;
        }
        return maxSum;
    }
    for(int i=0;i<N;i++)    
    {
        thisSum += a[i];
        if(thisSum>maxSum)
        {
            maxSum = thisSum;
        }
        else if(thisSum<0)
        {
            thisSum = 0;
        }
    }
    return maxSum;
}

int main () 
{
    int n;
    scanf("%d",&n);
    int* a = new int[n];
    int flag = 0;
    for (int i=0;i<n;i++) 
    {
        scanf("%d", &a[i]);
        if(a[i]>0) flag=1;
    }
    printf("%d", maxSqSum(n, a, flag));
    return 0;
}