/***********************************************
# Title: matrix reverse
# Author : johnfarrell  
# Date   : 2015-12-23
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/5
/*
输入第一行包括由空格分开的整数M、N、T（0 < M < 200，0 < N < 200，T=0或1），其中M和N分别表示待处理矩阵的行数与列数，T为0时表示左右翻转，为1时表示上下翻转。
之后的M行，每行包括由空格分隔的N个整数，依次为输入矩阵的每一行的数据。
输出包括M行N列，每个数字之间用一个空格分隔，每一行行末均有一个空格，表示的是按照要求翻转后的矩阵。
样例1
输入：
4 4 1
1 2 3 4
5 6 7 8
9 0 1 2
3 4 5 6
输出：
3 4 5 6 
9 0 1 2 
5 6 7 8 
1 2 3 4 
*/
#include<iostream>
using namespace std;
class Matrix {
private:
	int **p;
	int M, N;
public:
	Matrix(int MM, int NN) {
		M = MM;N = NN;
		p = new int*[M];
		for (int i=0;i<M;i++) {
			p[i] = new int[N];
		}
	} 
	~Matrix() {
		for(int i=0; i<M; i++) {
			delete[] p[i];
		}
		delete[] p;
	}
	void insert(int row, int column, int& data) {
		p[row][column] = data;
	}
	void init() {
		int data;
		for (int i=0;i<M;i++) {
			for (int j=0;j<N;j++) {
				cin>>data;
				insert(i,j,data);
			}
			//cout<<endl;
		}
	}
	int display(int row, int column) {
		return p[row][column];
	}
	void reverse(int& t) {
		if (t==0) { // left and right
			for (int i=0;i<M;i++) {
				for (int j=N-1;j>=0;j--) {
					cout<<display(i, j)<<" ";
				}
				cout<<endl;
			}
		} else if (t==1) { // up and down
			for (int i=M-1;i>=0;i--) {
				for (int j=0;j<N;j++) {
					cout<<display(i, j)<<" ";
				}
				cout<<endl;
			}
		}
		else {
		cout<<"please contirm that T is 0 or 1 !"<<endl;
		}
	
	}
};

int main() {
    int m,n,t,i,j,data;
    //cout<<"please input M,N,T(0<M<200, 0<N<200, T=0 or 1), where M is for row and N is for column and "<<endl;
	//cout<<"when T = 0, reverse its left and right; when T = 1, reverse its up and down."<<endl;
	cin>>m>>n>>t;
	Matrix matrix(m, n);
	//cout<<"please input each row"<<endl;
	matrix.init();
	//matrix.displayAll();
	matrix.reverse(t);
	//system("pause");
}