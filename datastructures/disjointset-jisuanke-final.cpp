/***********************************************
# Title: game group
# Author : johnfarrell  
# Date   : 2016-01-17
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/

//http://www.jisuanke.com/course/35/6899
/*
为了活跃蒜厂的工作气氛，促进彼此间的友谊，蒜头君决定挑个阳光明媚的周末，带领大家一起玩游戏。
一共有 n 位同学要参加，编号为 0 到 n - 1 。
蒜头君要对这些同学进行分组，而且蒜头君已经知道哪两个同学之间是好友关系。
为了让大家都玩得开心，蒜头君决定最终的分组方案要将所有好友组合都被分在一组。
蒜头君现在知道有 m 对好友关系，
需要注意的是，有可能一个同学有很多个好友，也有可能一个同学没有好友。
为了让游戏更有趣，蒜头君希望最后分出的组数尽可能多。
你能帮蒜头君算出来最多可以分成多少组么？
输入格式：
第一行输入两个数 m 和 n ，1<=n,m<=1000000。
接下来输入 m 行，每行输入两个数a，b，表示编号 a 和 b 的同学是好友关系，
输出格式：
输出为一行，表示最多可以分成多少组。
样例1
输入： 
 5 2
 0 2
 2 3
输出：
 3
提示信息
样例解释：
第一组：编号为 0、2、3 的同学
第二组：编号为 1 的同学
第三组：编号为 4 的同学
*/

#include <iostream>
using namespace std;

class DisjointSet {
private:
    int *father, *rank;
public:
    DisjointSet(int size) {
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            father[i] = i;
            rank[i] = 0;
        }
    }
    ~DisjointSet() {
        delete[] father;
        delete[] rank;
    }
    int find_set(int node) {
        if (father[node] != node) {
            father[node] = find_set(father[node]);
        }
        return father[node];
    }
    void merge(int node1, int node2) {
        int ancestor1 = find_set(node1);
        int ancestor2 = find_set(node2);
        if (ancestor1 != ancestor2) {
            if (rank[ancestor1] > rank[ancestor2]) {
                swap(ancestor1, ancestor2);
            }
            father[ancestor1] = ancestor2;
            rank[ancestor2] = max(rank[ancestor1] + 1, rank[ancestor2]);
        }
    }
};

int main() {
    DisjointSet dsu(1000000);
    int m, n, a, b;
    cin >> n >> m;
    int *rootarr = new int[n]();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        dsu.merge(a, b);
    }
    b = 0;
    for (int i = 0; i < n; ++i) {
        a = dsu.find_set(i);
        //cout<<"node" <<i<<"'s root is "<<a<<endl;
        if(a == i) b++;
    }
    cout<<b<<endl;
    return 0;
}