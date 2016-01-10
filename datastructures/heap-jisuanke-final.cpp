/***********************************************
# Title: heap-jisuanke-final
# Author : johnfarrell  
# Date   : 2016-01-10
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/6747

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