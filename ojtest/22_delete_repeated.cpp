/***********************************************
# Title: delete repeated
# Author : johnfarrell  
# Date   : 2015-12-25
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/22
#include<iostream>

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