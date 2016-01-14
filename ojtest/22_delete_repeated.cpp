/***********************************************
# Title: delete repeated
# Author : johnfarrell  
# Date   : 2015-12-25
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/22
#include<iostream>
/*
给定升序排序的数组，如果数组有2个或2个以上相同的数字，去掉他们，直到剩下2个为止。
例如：
数组A[] = [1,1,1,2,2,3]
你的算法需要返回新数组的长度5,
此时A为[1,1,2,2,3].
格式：第一行输入一个不超过200的数字n，第二行输入A[n],
最后输出新数组的长度。
样例1
输入：
6
1 1 1 1 3 3
输出：
4
*/
int delRepeated(int n, int a[])
{
    int num = n;
    for(int i=2;i<n;i++)
    {
        if(a[i]!=a[i-1]) continue;
        if(a[i]==a[i-2]) num--;
    }
    return num;
}
int main () 
{
    int n;
    scanf("%d",&n);
    int *a = new int[n];
    for(int i;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n<=2) {printf("%d\n",n);return 0;}
    printf("%d\n",delRepeated(n, a));
    return 0;
}