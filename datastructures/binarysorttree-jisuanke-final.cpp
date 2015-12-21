/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/5957
/*
为输入格式：
第一行输入一个正整数 N (1 <= N <= 1000)，代表序列里元素个数。
第二行输入 N 个正整数，代表序列 a 的 N 个元素(0 <= ai <= 10000)。保证序列里的元素值互不相同。
输出格式：
请按格式“a(b, c)”，输出引号之间的内容，a 代表每个结点的权值，b 代表其左孩子结点权值，c 代表右孩子结点权值，如果孩子结点为空，则输出“#”代替。一个结点输出一行，按结点的权值从小到大输出。注意输出“,”后面的空格。
样例1
输入：
5
2 5 3 1 4
输出：
1(#, #)
2(1, 5)
3(#, 4)
4(#, #)
5(3, #)
*/
#include <iostream>
class Node {
	public:
    int data;
	Node *lchild, *rchild, *father;
	Node (int _data, Node *_father = NULL) {
		data = _data;
		father = _father;
		lchild = NULL;
		rchild = NULL;
	}
	~Node () {
		if (lchild != NULL) {
			delete lchild;
		}
		if (rchild != NULL) {
			delete rchild;
		}
	}
	void insert(int value) {
		if (value == data) {
			printf("Already exists!\n");//
			return;
		}
		else if (value > data ) {
			if (rchild == NULL) {
				rchild = new Node(value, this);
			} else {
				rchild->insert(value);
			}
		} else {
			if (lchild == NULL) {
				lchild = new Node(value, this);
			} else {
				lchild->insert(value);
			}
		}
	}
	void disp() {
        if (lchild != NULL) {
            lchild->disp();
        }
		printf("%d", data);
		if (lchild==NULL) {
			printf("(#,");
		}
		if (lchild!=NULL) {
			printf("(%d,",lchild->data);
		}
		if (rchild==NULL) {
			printf(" #)");
		}
		if (rchild!=NULL) {
			printf(" %d)",rchild->data);
		}
		printf("\n");
        if (rchild != NULL) {
            rchild->disp();
        }
		
		
	}
};

class Binarytree {
    private:
	Node *root;
	public:
	Binarytree() {
		root = NULL;
	}
	~Binarytree() {
		if (root != NULL) {
            delete root;
        }
	}
	void insert(int value) {
		if (root == NULL) {
			root = new Node(value);
		} else {
			root->insert(value);
		}
	}
	void disp() {
		root->disp();
	}
};

int main() {
    int n;
	//printf("Please input an integer between 1 and 1000 included:\n");
	scanf("%d", &n);
	int val;
	Binarytree binarytree;
	for(int i=0;i < n;i++ ) {
		//printf("Please input an integer between 0 and 100000 included as a%i:\n", i);
		scanf("%d", &val);
		binarytree.insert(val);
	}
	binarytree.disp();
    //system("pause");
    return 0;
}