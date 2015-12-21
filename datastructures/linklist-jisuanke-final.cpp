/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/1251
/*
输入格式
第一行输入两个正整数 N 和 M（1 <= M < N <= 103）。第二行输入 M 个整数 numi（1 <= numi <= 103），表示 boss 依次念出来的数字。
保证 N - M 是奇数，输入的 numi 保证小于等于当前剩余简历数量。
输出格式
输出为一行， 输出 boss 认为最优秀的同学的 id 是多少。
样例1
输入：
7 2
2 4
输出：
4
提示信息
开始序列是：1 2 3 4 5 6 7， 抽掉第 2 份简历后的序列是：1 3 4 5 6 7， 抽掉第 4 份简历后的序列是：1 3 4 6 7。 最后简历里最中间的是 id 为 4 的简历。 请用单链表解决这道难题。
*/
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};
class Linklist {
    private:
    Node* head;
    public:
    Linklist() {
        head = NULL;
    }
    void insert(Node* node, int index) {
        if (head == NULL) {
            head = node;
            return;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node* current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index-1) {
            current_node = current_node->next;
            count++;
        }
        if(count == index-1) {
            node->next = current_node->next;
            current_node->next = node;
        }
    }
    void delete_node(int index) {
        if (head == NULL) {
            return;
        }
        Node* current_node = head;
        int count = 0;
        if (index == 0) {
            head = head->next;
            delete current_node;
            return;
        }
        while (current_node->next != NULL && count < index-1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index-1 && current_node->next != NULL) {
            Node* delete_node = current_node->next;
            current_node->next = delete_node->next;
            delete delete_node;
        }
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    int output_m() {
        if (head == NULL) {
            return 0;
        }
        Node* current_node = head;
        Node* current_node_2x = head;
        int count = 0;
        while (current_node_2x->next != NULL) {
            current_node = current_node->next;
            current_node_2x = current_node_2x->next->next;
            count++;
        }

        /*cout<<current_node->next->data<<endl;*/
        return current_node->data;
    }
};

int main()
{
int N,M;
cout<<"Please input N and M, with 1<=M<N<=10^3 and (N-M) odd..."<<endl;
cin>>N>>M;
cout<<"Please input "<<M<<" numbers within (1, 10^3)..."<<endl;
int num[M] = {};
Linklist linklist;
for (int i=1;i<=N;i++) {
    Node *node = new Node(i);
    linklist.insert(node, i-1);
}
for (int n=0;n<M;n++) {
    cin>>num[n];
    linklist.delete_node(num[n]-1);
}
/*linklist.output();*/
int ans = linklist.output_m();
cout<<ans;
/*system("pause");*/
return ans;
}
