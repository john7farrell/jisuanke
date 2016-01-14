/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/25
/*
给定一个数组，找到两个数，使得他们的和为一个给定的数值target。
函数twoSum返回两个数字index1,index2，
其中：number[index1] + number[index2]==target;
注意：index1必须小于index2且不能为0假设每一组输入只有唯一的一组解。
格式：第一行输入一个数n，接下来的两行分别输入数组number[n]和target，返回index1和index2.
例如：
Input:
numbers={2, 7, 11, 15},
target=9
Output:
index1=1, index2=2
提示：vector twoSum(vector &number, int target)
样例1
输入：
3
5 75 25
100
输出：
2 3
*/
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