/***********************************************
# Title: count and count
# Author : johnfarrell
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/23
/*
“伯爵说”序列如下：1, 11, 21, 1211, 111221, ...1 读作 "one 1" 或者 11。11 读作 "two 1s" 或者21。21 读作 "one 2, one 1" 或者 1211。
格式：多组输入，读到文件结束。每组输入给定一个整数n，输出第n个序列。(1<=n<=30)
注意：整数序列以字符串的形式表示。
PS：相信你已经看懂了题目，如果没看懂，小提示下，
其实类似于求”菲波拉契“数列的第n项哦～
样例1
输入：
6
输出：
312211
*/
//*Reference
//*http://www.ithao123.cn/content-8305290.html
//*http://blog.csdn.net/rainxbow/article/details/42153197
#include<iostream>
using namespace std; 
string result[100];

string str(string s)
{
    string a = "";
    int m;
    for(int i=0;i<s.length();i += m)
    {
        m = 1;
        for(int j=i+1;j<s.length();j++)
        {
            if(s[i]==s[j]) m++;
            else break;
        }
        char c = m+'0';
        a.push_back(c);
        a.push_back(s[i]);
    }
    return a;
    
}
string count(int n)
{
    string res;
    if(result[n]!="") res=result[n];
    else if(n==1) res="1";
    else res=str(count(n-1));
    return res;
}

int main() 
{   
	int n;   
	while(cin>>n)     
	cout<<count(n)<<endl; 
}
/*
#include<iostream> 
using namespace std; 
string result[100]; 
string str(string s)  //transfer function
{          
	string a = "";   
	int l = s.length(), i, j, m;   
	for (i = 0; i < l; i = i + m) 
	{      
		m = 1;       
		for (j = i + 1; j < l; j++) 
		{         
			if (s[i] == s[j])           
			m++;         
		else           
			break;       
		}       
	    char c = m + '0';      
	    a.push_back(c);       
	    a.push_back(s[i]);   
	}   
	return a; 
} 
string rec(int n) // recursion 
{    
	string res;   
	if(result[n] != "")      
		return result[n];   
	if (n == 1)     
		res = "1";   
	else  
		res = str(rec(n - 1));   
	return res; 
}  
int main() 
{   
	int n;   
	while(cin >> n)     
	cout << rec(n) << endl; 
}
*/