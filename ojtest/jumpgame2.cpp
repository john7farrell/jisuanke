/***********************************************
# Title: jump game 2
# Author : johnfarrell  
# Date   : 2015-12-24
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/20
#include<iostream>
#include<cstdio>
//*Reference
//*http://blog.csdn.net/zhangzhengyi03539/article/details/50173193
int main () 
{
    int n;
    scanf("%d", &n);
    int *a = new int[n];
    for (int i=0;i<n;i++) 
	{
        scanf("%d", &a[i]);
    }
	int *log = new int[n]();
	for (int i=1;i<n;i++) { log[i]=n+1;}
	for (int i=0;i<n;i++)
	{	
		for (int j=i+1;j<=i+a[i]&&j<n;j++) 
		{
			printf("i=%d j=%d log[%d]=%d log[%d]=%d\n",i,j,i,log[i],j,log[j]);
			if (log[i]+1<log[j]) log[j]=log[i]+1;
		}
	}
	delete[] a;
    printf("%d\n", log[n-1]);    
	delete[] log;
	system("pause");
    return 0;
}

//*
//#include <iostream>
//using namespace std;
//
//int func(int *p, int length)
//{
//    int* state = new int[length]();
//	cout<<"length="<<length<<endl;
//    for (int i = 1; i<length; i++)
//    {
//        state[i] = length + 1;
//		cout<<"state["<<i<<"]="<<state[i]<<endl;
//    }
//    for (int i = 0; i<length; i++)
//    {
//        for (int j = i+1; (j<=i+p[i])&&(j<length); j++)
//        {
//			cout<<"i="<<i<<" "<<"j="<<j<<endl;
//            if (state[i] + 1<state[j])
//                state[j] = state[i] + 1;
//			cout<<"state["<<j<<"]="<<state[j]<<endl;
//        }
//    }
//    int result = state[length - 1];
//    delete[] state;
//    return result;
//}
//
//int main()
//{
//    int length;
//    cin >> length;
//    int* p = new int[length];
//    for (int i = 0; i < length; i++)
//    {
//        cin>>p[i];
//    }
//    cout << func(p, length);
//    delete[] p;
//	system("pause");
//	return 0;
//}