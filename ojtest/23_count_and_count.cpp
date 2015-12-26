/***********************************************
# Title: count and count
# Author : johnfarrell
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/23
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