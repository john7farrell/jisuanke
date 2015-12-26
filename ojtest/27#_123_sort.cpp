/***********************************************
# Title: 123 sort
***********************************************/
//http://nanti.jisuanke.com/t/27
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