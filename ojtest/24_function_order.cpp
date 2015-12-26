/***********************************************
# Title: function order
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/24
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