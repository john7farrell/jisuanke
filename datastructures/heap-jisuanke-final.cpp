/***********************************************
# Title: heap-jisuanke-final
# Author : johnfarrell  
# Date   : 2016-01-10
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/6747
/*
蒜头君最近买了一套新玩具，这套玩具由一台小机器和 N
个小球组成，经过蒜头君几天的钻研，他终于知道玩具的玩法了。
这台小机器能将两个质量为 a 和 b 的小球合并成一个质量为 (a*b^2)^(1/3)
玩了一会儿，蒜头君就深深迷上了这套玩具，根本停不下来。
每次他都随机选两个球进行合并，直到最后把 n 个小球合并成一个球。
蒜头君发现，每次合并顺序不一样，最后得到球的质量也不一样。
现在我们知道了每个小球的质量，蒜头君想知道最后得到的小球质量最小为多少，聪明的你快来帮他算一下吧。

输入格式：
输入第一行是一个正整数 N (1 <= N <= 1000)，表示蒜头君一共有 N 个小球。
接下来输入 N 个正整数，表示每个小球的质量。每个小球的质量最大为 1000。
输出格式：
输出一行。输出合并最后，球的最小质量。最终结果和标准答案的误差在 10^-3 以内均认为正确。

样例1

输入：
5
4 1 12 100 60
输出：
1.915696862302

提示 
当我们每次选一个当前质量最大和质量次大的小球（质量分别为 a 和 b）进行合并时，最后得到的小球质量最小。        
*/
#include<iostream>
#include<math.h>
using namespace std;
class Heap {
private:
    float *data;
    int size;
public:
    Heap(int length_input) {
        data = new float[length_input];
        size = 0;
    }
    ~Heap() {
        delete[] data;
    }
    void push(float value) {
        data[size] = value;
        int current = size;
        int father = (current - 1) / 2;
        while (data[current] > data[father]) {
            swap(data[current], data[father]);
            current = father;
            father = (current - 1) / 2;
        }
        size++;
    }
    float top() {
         return data[0];
    }
    void update(int pos, int n) {
        int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
        int min_value = pos;
        if (lchild < n && data[lchild] > data[min_value]) {
            min_value = lchild;
        }
        if (rchild < n && data[rchild] > data[min_value]) {
            min_value = rchild;
        }
        if (min_value != pos) {
            swap(data[pos], data[min_value]);
            update(min_value, n);
        }
        //output();//
    }
    void pop() {
        swap(data[0], data[size - 1]);
        size--;
        update(0, size);
    }
    void output() {
        for (int i=0;i<size;i++) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    int heap_size() {
        return size;
    }
    float calc(float a, float b) {
        return pow(a * b * b, 1.0/3.0);
    }
};
int main() {
    int n;
    cin>>n;
    float value, ans=0.0;
    Heap heap(n);
    for(int i=1;i<=n;i++) {
        cin>>value;
        heap.push(value);
    }
    if(n==1) {
        ans += heap.top();
    }
    //heap.output();//
    while(heap.heap_size()>1) {
        float a = heap.top();
        //cout<<"current a="<<a<<endl;//
        heap.pop();
        float b = heap.top();
        //cout<<"current b="<<b<<endl;//
        heap.pop();
        ans = heap.calc(a, b);
        //cout<<"current ans="<<ans<<endl;//
        heap.push(ans);
    }
    cout<<ans<<endl;
    return 0;
}