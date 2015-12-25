/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/25

//needn't sort at all...
//why there is a label of 'sort'?

#include <cstdio>
#include<iostream>
using namespace std;

/*void quick_sort(int b[], int l, int r) 
{
    int i=l, j=r, mid=b[r];
    do 
    {
        while(b[i]<mid) ++i;
        while(b[j]>mid) --j;
        if(i<=j) 
        {
            swap(b[i],b[j]);
            ++i;--j;
        }
    }
    while(i<j);
    if(l<j) quick_sort(b, l, j);
    if(r>i) quick_sort(b, i, r);
}

void twoSum(int n, int a[], int b[], int tg)
{
    int p=0, q=0;
    for(int i=0;i<n&&b[i]<tg;i++)
    {
        for(int j=i+1;j<n&&b[j]<tg;j++)
        {
            if(b[i]+b[j]==tg) 
            {
                p = b[i];
                q = b[j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==p) p=i;
        else if(a[i]==q) q=i;
    }
    p++;q++;
    if(p<q) cout<<p<<" "<<q;
    else cout<<q<<" "<<p;
}
*/
void twosum(int n, int a[], int tg)
{
    int p=0, q=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=tg) continue;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>=tg) continue;
            if(a[i]+a[j]==tg) 
            {
                p = i;p++;
                q = j;q++;
            }
        }
    }
    if(p<q) cout<<p<<" "<<q;
    else cout<<q<<" "<<p;
}
int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    //int *b = new int[n];
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        //b[i] = a[i];
    }
    int target;
    cin>>target;
    //quick_sort(b, 0, n-1);
    //twoSum(n, a, b, target);
    twosum(n, a, target);
    return 0;
}