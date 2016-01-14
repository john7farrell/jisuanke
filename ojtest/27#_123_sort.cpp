/***********************************************
# Title: 123 sort
***********************************************/
//http://nanti.jisuanke.com/t/27
/*
排序是一种很频繁的计算任务。一个实际的例子是，当我们给某项竞赛的优胜者按金银铜牌排序的时候。在这个任务中可能的值只有三种1，2和3。我们用交换的方法把他排成升序的。
写一个程序计算出，计算出的一个包括1、2、3三种值的数字序列，排成升序所需的最少交换次数。
输入第1行为类别的数量N（1≤N≤1000）
输入第2行到第N+1行，每行包括一个数字（1或2或3）。
输出包含一行，为排成升序所需的最少交换次数。
样例1
输入：
9
2
2
1
3
3
3
2
3
1
输出：
4
*/
//*
//http://blog.csdn.net/z9550695/article/details/47310633
#include<stdio.h>
#include<iostream>
int a[1001];
int count[4];//交换次数
int num1, num2, num3, n ,ans = 0;
// num1表示位置为1的地方非1的个数;num2表示位置为2的地方3的个数;num3表示位置为3的地方2的个数;
// ans = x + max(y,z)
int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		++count[a[i]];
	}

	for (int i = 1; i <= count[1]; ++i)
		if (a[i] != 1)
			++num1;
	for (int i = count[1] + 1; i <= count[1] + count[2]; ++i)
		if (a[i] == 3)
			++num2;
	for (int i = count[1] + count[2] + 1; i <= n; ++i)
		if (a[i] == 2)
			++num3;
	int max = 99999;
	if (num2 > num3)
		max = num2;
	else
		max = num3;
	ans = num1 + max;
	printf("%d\n", ans);
	return 0;
}

// = = 
/*
#include<iostream>
#include<cstdio>
using namespace std;
int times = 0;
class Matrix {
private:
	int **p;
	int M, N;
public:
	Matrix(int MM, int NN) {
		M = MM;N = NN;
		p = new int*[M]();
		for (int i=0;i<M;i++) {
			p[i] = new int[N]();
		}
	}  
	~Matrix() {
		for(int i=0; i<3; i++) {
			delete[] p[i];
		}
		delete[] p;
	}
    void disp()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void init(int n, int a[], int log[])
    {
        for(int j=0;j<n;j++) 
        {
            if(j<log[0]) p[0][a[j]-1]++;
            else if(j<n-log[2]) p[1][a[j]-1]++;
            else p[2][a[j]-1]++;
        }
    }
    void solve(int n, int a[], int log[], int &times)
    {
        int i=0,j=0;
        
    }
};

int main() 
{
    int n;
    cin>>n;
    int *a = new int[n];
    int log[3] = {0,0,0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1) log[0]++;
        else if(a[i]==2) log[1]++;
        else log[2]++;
    }
    Matrix matrix(3, 3);
    matrix.init(n, a, log);
    //matrix.disp();
    matrix.solve(n, a, log, times);
    cout<<times<<endl;
    delete[] a, log;
    return 0;
}
*/