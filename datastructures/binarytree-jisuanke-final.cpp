/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/5835
/*
为了将问题简单，现在蒜头君告诉你这棵二叉树的先序遍历结果和中序遍历结果，求原始二叉树的后序遍历结果，以及镜子里的二叉树的后序遍历结果。
输入格式：
输入第一行是一个字符串 pre_str，代表原始二叉树的先序遍历结果；输入第二行是一个字符串 in_str，代表二叉树的中序遍历结果。每个字符代表结点的编号，
结点的编号互不相同，字符仅由大小写字母组成。保证两个字符串长度相等，长度不超过 50，且保证可以通过先序遍历和中序遍历结果构造出一棵唯一的二叉树。
输出格式：
输出第一行，输出一个字符串，代表原始二叉树的后序遍历结果；
输出第二行，输出一个字符串，代表镜子里的二叉树的后序遍历结果。
样例1
输入：|| 输出：
abdce || dbeca
dbaec || ecdba
*/
#include<iostream>
#include<string>
using namespace std;
class Node {
public:
    int data;
    Node *lchild, *rchild;
    Node(int _data) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL) {
            delete lchild;
        }
        if (rchild != NULL) {
            delete rchild;
        }
    }
    void postorder() {
        if (lchild != NULL) {
            lchild->postorder();
        }
        if (rchild != NULL) {
            rchild->postorder();
        }
        //cout << data << " ";
		cout << char(data);
    }
	void _postorder() {
        
        if (rchild != NULL) {
            rchild->postorder();
        }
		if (lchild != NULL) {
            lchild->postorder();
        }
        //cout << data << " ";
		cout << char(data);
    }
    Node* build(const string &pre_str, const string &in_str, int len) {
        //Node *p = new Node(pre_str[0] - '0');
		Node *p = new Node(pre_str[0]);
        int pos = in_str.find(pre_str[0]);
        if (pos>0) {
            p->lchild = build(pre_str.substr(1, pos), in_str.substr(0, pos), pos);            
        }
        if (len - pos - 1 > 0) {
            p->rchild = build(pre_str.substr(pos+1), in_str.substr(pos+1), len - pos - 1);
        }
        return p;
    }
	void MirrorRecursively(Node *pNode) {
	if(NULL == pNode)
		return;
	if(NULL == pNode->lchild && NULL == pNode->rchild)
		return;
	Node *pTemp = pNode->lchild;
	pNode->lchild = pNode->rchild;
	pNode->rchild = pTemp;
	
	if(pNode->lchild)
		MirrorRecursively(pNode->lchild);
	if(pNode->rchild)
		MirrorRecursively(pNode->rchild);
}
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        if (root != NULL) {
            delete root;
        }
    }
    BinaryTree(const string &pre_str, const string &in_str, int len) {
        root = root->build(pre_str, in_str, len);
    }
    void postorder() {
        root->postorder();
    }
	void _postorder() {
        root->_postorder();
    }
	void MirrorRecursively() {
		root->MirrorRecursively(root);
	}
	
};
int main() {
    string pre_str = "";
	cin>>pre_str;
	string in_str = "";
	cin>>in_str;
	//string pre_str = "abdce";
    //string in_str = "dbaec";
    BinaryTree binarytree(pre_str, in_str, in_str.length());
    binarytree.postorder();
	cout<<endl;
	binarytree.MirrorRecursively();
	binarytree.postorder();
	cout<<endl;
	/*binarytree._postorder();
    cout<<endl;*/
    //system("pause");
	return 0;
}