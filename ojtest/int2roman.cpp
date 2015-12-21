/***********************************************
# Title: integer to roman numeral(and roman to integer)
# Author : johnfarrell  
# Date   : 2015-12-21
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://nanti.jisuanke.com/t/13
//http://nanti.jisuanke.com/t/14
/*
13
给定一个整数num，( 1<=num<=3999)，将整数转换成罗马数字。
如1,2,3,4,5对应的罗马数字分别位I，II，III，IV，V等。
格式：
   第一行输入一个整数，接下来输出对应的罗马数字。
提示：
   罗马数字的常识见此链接，对做题有帮助哦～尤其是表示方法。
http://baike.baidu.com/link?url=injU8M4bAoc2zRZQ1GtgrfvuzCJO9PLnq6fpQGJLenakbzo-rS8p-qsYHR_81-aN

样例1
输入：
123
输出：
CXXIII
*/
#include<iostream>
int convert(int input) {
	if(input>0 && input<4){
		printf("I");
		convert(input-1);
	}
	else if(input>=4 && input<9) {
		if(input<5) printf("I");
		printf("V");
		convert(input-5);
	}
	else if(input>=9 && input<40) {
		if(input<10) printf("I");
		printf("X");
		convert(input-10);
	}
	else if(input>=40 && input<90) {
		if(input<50) { 
			printf("XL");
			convert(input%10);
		}
		else {
			printf("L");
			convert(input-50);
		}
	}
	else if(input>=90 && input<400) {
		if(input<100) {
			printf("XC");
			convert(input%10);
		}
		else {
			printf("C");
			convert(input-100);
		}
	}
	else if(input>=400 && input<900) {
		if(input<500) {
			printf("CD");
			convert(input-400);
		}
		else {
			printf("D");
			convert(input-500);
		}
	}
	else if(input>=900 && input<4000) {
		if(input<1000) {
			printf("CM");
			convert(input-900);
		}
		else {
			printf("M");
			convert(input-1000);
		}
	}

	return 0;
}

int rconvert(char* roma, int &result) {
	if(roma[0] == '\0') return result;
	else if(roma[0] == 'M') {
		result += 1000;
		rconvert(++roma, result);
	}
	else if(roma[0]=='C' && roma[1]=='M'){
		result += 900;
		++roma;
		rconvert(++roma, result);
	}
	else if(roma[0] == 'D') {
		result += 500;
		rconvert(++roma, result);
	}
	else if(roma[0]=='C' && roma[1]=='D') {
		result += 400;
		++roma;
		rconvert(++roma, result);
	}
	else if(roma[0] == 'C') {
		result += 100;
		rconvert(++roma, result);
	}
	else if(roma[0]=='X' && roma[1]=='C') {
		result += 90;
		++roma;
		rconvert(++roma, result);
	}
	else if(roma[0] == 'L') {
		result += 50;
		rconvert(++roma, result);
	}
	else if(roma[0]=='X' && roma[1]=='L') {
		result += 40;
		++roma;
		rconvert(++roma, result);
	}
	else if(roma[0] == 'X') {
		result += 10;
		rconvert(++roma, result);
	}
	else if(roma[0]=='I' && roma[1]=='X') {
		result += 9;
		++roma;
		rconvert(++roma, result);
	}
	else if(roma[0] == 'V') {
		result += 5;
		rconvert(++roma, result);
	}
	else if(roma[0]=='I' && roma[1]=='V') {
		result += 4;
		++roma;
		rconvert(++roma, result);
	}
	else if(roma[0] == 'I') {
		result += 1;
		rconvert(++roma, result);
	}
	else {
		return result;
	}
}
int main () {
	//int2roma
    int a;
    scanf("%d", &a);
	convert(a);
	//roma2int
	/*char* roma = new char[20];
    scanf("%s", roma);
	int result = 0;
	result = rconvert(roma, result);
	printf("%d", result);*/

	system("pause");
    return 0;
}