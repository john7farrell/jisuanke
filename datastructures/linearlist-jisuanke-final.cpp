/***********************************************
# Title: ring shift left
# Author : johnfarrell  
# Date   : 2016-02-25
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/7653
/*
在前面的课程中，我们学习了顺序表的构造、插入、扩展、查找、删除、遍历这 6 种操作。然而蒜头君并不满足于实现这些基本的操作，于是蒜头君想到了一种新的操作：
循环左移。

对于顺序表 L=(a_0, a_1, ..., a_{n-1})，循环左移k位意味着将顺序表变为
L_k=(a_k, a_{k+1}, ..., a_{n-1}, a_0, a_1, ..., a_{k-1})。

比如：长度为 8 的顺序表 (1, 2, 3, 4, 5, 6, 7, 8)，循环左移 3 位后的结果为
(4, 5, 6, 7, 8, 1, 2, 3)。

输入格式：

第一行输入两个整数 n(1≤n≤100) 和 k(1≤k≤n)，分别表示顺序表的元素个数和循环左移的位移量。
第二行一共 n 个整数 ai(0≤ai≤10000)，表示顺序表中元素的值。

输出格式：

输出输出只有一行n个整数，顺序输出循环左移后顺序表中每个元素的值，每个元素之间用一个空格分隔。行末不要有多余空格。

样例1
输入：
8 3
1 2 3 4 5 6 7 8
输出：
4 5 6 7 8 1 2 3
*/
#include <iostream>
#include <cstring>
using namespace std;
class Vector {
private:
    int size, length;
    int *data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new int[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, int value) {
        if (loc < 0 || loc > length) {
            return false;
        }
        if (length >= size) {
            //return false;
            expand();
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void expand() {
        int *old_data = data;
        size = size * 2;
        data = new int[size];
        for(int i=0;i<length;i++) {
            data[i] = old_data[i];
        }
        delete[] old_data;
    }
    int search(int value) {
        for (int i = 0; i < length; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    bool remove(int index) {
        if (index < 0 || index >= length) {
            return false;
        }
        for (int i = index + 1; i < length; ++i) {
            data[i - 1] = data[i];
        }
        length = length - 1;
        return true;
    }
    void print() {
        for(int i=0;i<length;i++) {
            if(i>0) {
                cout<<" ";
            }
            cout<<data[i];
        }
        cout<<endl;
    }
    void shift(int offset) {
        int *old_data = data;
        data = new int[size];
        int nplus;
        for(int i=0;i<size;i++) {
            nplus = (i+offset) % size;
            //cout << nplus << endl;
            data[i] = old_data[nplus];
        }
        print();
        delete[] old_data;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Vector a(n);
    int ai;
    for(int i=0;i<n;i++) {
        cin >> ai;
        if(a.insert(i, ai)) continue;
    }
    //a.print();
    a.shift(k);
    return 0;
}