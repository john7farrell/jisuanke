/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/4970
/*
输入格式：
输入有两行，第一行是一个正整数 N (1 <= N <= 100)，表示输入魔法机序列的长度，第二行是序列 a，共有 N 个整数，表示要得到的目标序列。序列为 1 到 N 的排列，即序列 a 长度为 N，保证序列中的整数都不相同，且整数在区间 [1, N] 内。
输出格式：
输出一行。如果能通过魔法机得到序列 a，则输出“YES”，否则输出“NO”。
样例1
输入：
5
2 1 5 4 3
输出：
YES
提示信息
用栈模拟即可。
样例解释：
数字 1 进栈；
数字 2 进栈，此时让栈顶的 2 出栈，继续让栈顶的 1 出栈；
数字 3 进栈；
数字 4 进栈；
数字 5 进栈，此时让栈顶的 5 出栈，继续让栈顶的 4 出栈，继续让栈顶的 3 出栈。
程序结束，我们得到的出栈顺序为：2 1 5 4 3。
*/
#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template<class Type> class Stack {
private:
    Type *urls;
    int max_size, top_index;
public:
    Stack(int length_input) {
        urls = new Type[length_input];
        max_size = length_input;
        top_index = -1;
    }
    ~Stack() {
        delete[] urls;
    }
    bool push(const Type &element) {
        if (top_index >= max_size - 1) {
            return false;
        }
        top_index++;
        urls[top_index] = element;
        return true;
    }
    bool pop() {
        if (top_index < 0) {
            return false;
        }
        top_index--;
        return true;
    }
    Type top() {
        assert(top_index >= 0);
        return urls[top_index];
    }
    bool empty () {
        if (top_index<0) {
            return true;
        } else {
            return false;
        }
    }

};
int main() {
    int i, n, a[101];
    cin>>n;
	for (i=0;i<n;i++) {
		cin>>a[i];	
	}
	Stack<int> stacka(n);
	for (i=n-1;i>-1;i--) {
		stacka.push(a[i]);
	}
	Stack<int> stackn(n);
    for(i=1;i<=n;i++) {
		stackn.push(i);
		while (stackn.top()==stacka.top()) {
			stackn.pop();
            stacka.pop();
			if (stackn.empty()) {
				break;
			}
		}

	}
	if (stacka.empty()) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}
    //system("pause");
    return 0;
}