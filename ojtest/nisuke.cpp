/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/6
/*
小米老师在不同的学期可能会带一个班或者同时带多个班，因此输入数据可能有一组或者多组。每组输入数据的第一行为一个整数n，表示了这个班的小朋友数，之后n行每行包括了由空格分隔的三个整数和一个字符串，那个字符串表示了小朋友的名字，前面三个整数则是这个学生手里橡皮泥块的长、宽、高数据。按照幼儿园的规定，每个班最多有9个小朋友，最少也要有2个小朋友，每个小朋友在学籍系统中的名称不超过8个字符长。当出现一个班级的小朋友数为-1时，表示没有更多的班级了。
输出行数与小米老师带的班级数相同，形式为“X took clay from Y.”，具体请参考样例输出。
样例1
输入：
3
10 10 2 Jill
5 3 10 Will
5 5 10 Bill
4
2 4 10 Cam
4 3 7 Sam
8 11 1 Graham
6 2 7 Pam
-1
输出：
Bill took clay from Will.
Graham took clay from Cam.
*/
#include <iostream>
typedef struct stu{
	int num;
    char name[9];
} stu;

int main(){
	int n=1;
	int a,b,c;
	stu stdt[9];
	char* took;
	char* taken;
    while(1) {
		scanf("%d",&n);
		if (n==-1) break;
		int v=0;
		int i=0;
		while(n--) {
			scanf("%d%d%d%s",&a,&b,&c,&stdt[i].name);
			stdt[i].num = a*b*c;
			i++;
			v+=a*b*c;
		}
		v/=i;
		int j=0;
		while(i--) {
			if (stdt[j].num>v) {
				took = stdt[j].name;
			}
			if (stdt[j].num<v) {
				taken = stdt[j].name;
			}
			j++;
		}
		printf("%s took clay from %s.\n",took,taken);
	}
	return 0;
}