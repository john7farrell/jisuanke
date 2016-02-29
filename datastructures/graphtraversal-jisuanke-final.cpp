/***********************************************
# Title: shortest path simple
# Author : johnfarrell  
# Date   : 2016-02-29
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/7317
/*经过一周忙碌的工作后，蒜头君想趁着周末好好游玩一番。蒜头君想去好多好多地方，他想去南锣鼓巷吃各种好吃的，
想去颐和园滑冰，还想去怀柔滑雪场滑雪……可是时间有限，蒜头君并不能玩遍所有的地方，最后他决定去几个离他较近的地方。

我们知道蒜头君一共想去 N 个地方玩耍，编号从 1 到 N，并且知道了蒜头君所在地方的编号 C，
以及 M 条路径。现在蒜头君想让你帮他算一算，他到每个地方分别需要经过多少个地方？

输入格式：
第一行输入三个正整数 N, M, C。代表蒜头君想去 N 个地方，有 M 条路径，蒜头君在编号为 C 的地方。
1≤N,C≤1000, 1≤C≤N, 1≤M≤10000。
保证没有重复边，且图中所有点互相连通。

输出格式：
输出 NN 行，按编号从小到大，输出结果。第 ii 行表示蒜头君到编号为 ii 的地方，需要经过多少个地方。

样例1
输入：
5 5 2
1 2
2 3
2 4
3 4
3 5
输出：
1
0
1
1
2

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Graph {
private:
    int n;
    bool *visited;
    vector<int> *edges;

public:
    Graph(int input_n) {
        n = input_n;
        edges = new vector<int>[n];
        visited = new bool[n];
        memset(visited, 0, n);
    }

    ~Graph() {
        delete[] edges;
        delete[] visited;
    }

    void insert(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    void findpathbfs(int start_vertex, int length) {
        int j = 0;
        queue<int> bfs_queue;
        bfs_queue.push(start_vertex);
        visited[start_vertex] = true;
        int *step = new int[length]();
        step[start_vertex] = 0;
        while(!bfs_queue.empty()) {
            int vertex = bfs_queue.front();
            //cout <<"vertex = "<< vertex <<" will be popped!"<< endl;
            bfs_queue.pop();
            for(int adj_vertex: edges[vertex]) {
                //cout << "adj_vertex = "<< adj_vertex << " | ";
                if(!visited[adj_vertex]) {
                    //cout << "if entry" << " | ";
                    visited[adj_vertex] = true;
                    j = adj_vertex;
                    step[j] = step[vertex] + 1;
                    bfs_queue.push(adj_vertex);
                }
                //cout <<"j = "<< j << " | ";
                //cout <<"step["<< j <<"] = "<< step[j] << endl;
            }
            bool stopflag = true;
            for(int i=0;i<length;i++) {
                //cout <<"visited["<<i<<"] = "<< visited[i] << " | ";
                if(visited[i]==false) {
                    stopflag = false;
                }
            }
            //cout << "stop = " << stopflag <<" | ";
            if(stopflag==true) {
                //cout <<"stop entry = "<<stopflag<<" ";
                for(int i=0;i<length;i++) {
                    cout << step[i] << endl;
                }
                delete[] step;
                return;
            }
        }
    }
};

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g.insert(x-1, y-1);
    }
    g.findpathbfs(c-1, n);
    return 0;
}