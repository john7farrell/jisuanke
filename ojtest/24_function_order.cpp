/***********************************************
# Title: function order
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/24
/*
下面我将描述一个简单的函数：
f(8)=2
f(16)=1
f(32)=0
f(2048)=3
读入一个x(1≤x≤101000)，请你找出f(x)的值。
输入包括一行，仅一个数字x。
输出包括一行，仅一个数字f(x)。
提示：
f(0)=1, f(1)=0, f(2)=0, f(3)=0, f(4)=0, f(5)=0, f(6)=1, f(7)=0, f(8)=2, f(9)=1
有时候看数据猜题意也是很重要的技能，如果你看到这里还不知道题意的话，那么我来告诉你，f(x)表示x的十进制表示中有多少个圈圈。

样例1
输入：
2048
输出：
3
*/
#include<iostream>
using namespace std;

int f(string s)
{
    int sum=0, ele=0;
    int len = s.length();
    const char *num = s.c_str();
    for(int i=0;i<len;i++)
    {
        //cout<<"num["<<i<<"]="<<num[i]<<endl;
        //cout<<"sum="<<sum<<" ele="<<ele<<endl;
        switch(num[i])
        {
            case '0':
                ele = 1;
                break;
            case '6':
                ele = 1;
                break;
            case '8':
                ele = 2;
                break;
            case '9':
                ele = 1;
                break;
            default:
                ele = 0;                
        }
        sum += ele;
    }
    return sum;   
}
int main () 
{
    string str;
    cin>>str;
    cout<<f(str)<<endl;
    return 0;
}