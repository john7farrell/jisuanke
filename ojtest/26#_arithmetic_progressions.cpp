/***********************************************
# Title: arithmetic progressions
***********************************************/
//http://nanti.jisuanke.com/t/26
/*
一个等差数列是一个能表示成a, a+b, a+2b,..., a+nb (n=0,1,2,3,...)的数列。
在这个问题中a是一个非负的整数，b是正整数。写一个程序来找出在双平方数集合(双平方数集合是所有能表示成p2＋q2的数的集合)S中长度为n的等差数列。
输入包括两行，第一行为N要找的等差数列的长度（3≤ N≤25）。第二行是找到的双平方数p和q的上界M（0≤p,q≤M）。
输出一行或者多行，如果没有找到数列,输出NONE。否则输出一个整数对a b（这些行应该先按b排序再按a排序）
样例1
输入：
5
7
输出：
1 4
37 4
2 8
29 8
1 12
5 12
13 12
17 12
5 20
2 24
*/
//*
//*http://blog.csdn.net/z9550695/article/details/47143047

#include<iostream>
#include<cstring>
using namespace std;
bool is[125001];
int a[125001];
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= m; ++j)
			is[i * i + j * j] = 1;
	int k = 0;
	for (int i = 0, z = m * m * 2; i <= z; ++i)
		if (is[i])
			a[k++] = i;
	int l = 1, ma = (m * m * 2 - 0) / (n - 1);
	int nu = 0;
	for (; l <= ma; ++l) {
		for (int i = 0; a[i] + (n - 1) * l <= m * m * 2 && i < k; ++i) {
			bool f = 1;
			for (int j = 1; j < n && f; ++j)
				if (!is[a[i] + j * l]) {
					f = 0;
				}
			if (f) {
				printf("%d %d\n", a[i], l);
				++nu;
			}
		}
	}
	if (!nu)
		puts("NONE");
	return 0;
}
//*others

//http://my.oschina.net/kaneiqi/blog/261884
//http://my.oschina.net/u/347565/blog/62199


/*mine is too slow(stupid)
#include<iostream>

bool test(int a, int b, int n, int m)
{
    int l = 0;
    for(int i=0;i<n;i++)
    {
        int q = 0;
        for(int p=0;p*p<=a+i*b&&p<=m;p++)
        {
            q=0;
            //printf("%d+%d*%d=%d--p=%d q=%d\n",a,i,b,a+i*b,p,q);
            for(q=0;p*p+q*q<=a+i*b&&q<=m;q++)
            {
                //printf("--%d+%d*%d=%d--p=%d q=%d\n",a,i,b,a+i*b,p,q);
                if(p*p+q*q==a+i*b) 
                {
                    l++;
                    //printf("--%d+%d*%d=%d--p=%d q=%d\n",a,i,b,a+i*b,p,q);
                    break;                    
                }
            }
            //printf("l=%d\n",l);
            if(l>i) break;
        }
        if(l!=i+1) break;
    }
    //printf("fin l=%d\n",l);
    if(l!=n) return false;
    else return true;
}
void disp(int a, int b)
{
    printf("%d %d\n",a, b);
}
void solve(int n, int m)
{
    int flag=0;
    //int *sq = new int[n];
    
    int a=0, b=1;
    //printf("n=%d m=%d",n,m);
    while(a+(n-1)*b<=2*m*m) 
    {
        //printf("a=%d b=%d",a,b);
        while(a+(n-1)*b<=2*m*m)
        {
            //printf("a=%d b=%d",a,b);
            if(test(a, b, n, m))
            {
                flag++;
                disp(a, b);
            }
            a++;
        }
        a = 0;
        b++;
    }
    if(flag==0) {printf("NONE");return;}
}
int main() 
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    solve(n, m);
    //if(test(25, 12, n, m)) disp(25, 12);
    return 0;
}
*/