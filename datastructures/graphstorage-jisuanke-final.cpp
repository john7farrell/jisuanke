/***********************************************
# Title: fan game
# Author : johnfarrell  
# Date   : 2016-01-28
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/7186
/*
蒜头君和他的同事们最近在玩一个好玩的游戏：互粉攻略。一共有 N 个人参加游戏，
编号从 0 到 N-1 ，游戏前每个人都会展示自己最靓丽的一面。当游戏开始时，
每个人可以选择去关注别人。当 A 关注了 B ，则 A 就成了 B 的粉丝，但是并不意味着
 B 同时关注了 A。当所有人都选好后，游戏结束，人气指数最高的人成为冠军。
蒜头君制订了奇怪的规定：一个人的人气指数等于他的粉丝数减去关注数，
因为蒜头君觉得人气高的人，往往有更多粉丝，并且一般都非常高冷，很少关注别人。

蒜头君发现一共有 M 条关注，粗心的他在统计师出了点小问题，所以可能会出现重复的
关注。现在蒜头君想知道每个人的人气指数，聪明的你能帮帮他么？

输入格式：
第一行输入两个数n和m，
1<=n<=1000,1<=m<=100000。
接下来输入m行，美行输入两个数a和b，表示编号a的人关注了编号b的人，0<=a,b<=n-1，
a!=b。
输出格式：
输出n行，每行输出每个人的人气指数，按编号依次输出即可。

样例1
输入：
4 3
0 2
2 3
0 1

输出：
-2
1
0
1

*/
#include <iostream>
#include <cstring>
using namespace std;

class FanMat {
private:
    int **mat;
    int n;

public:
    FanMat(int input_n) {
        n = input_n;
        mat = new int*[n];
        for (int i = 0; i < n; ++i) {
            mat[i] = new int[n];
            memset(mat[i], 0, sizeof(int) * n);
        }
    }

    ~FanMat() {
        for (int i = 0; i< n; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void insert(int x, int y) {
        mat[x][y] = 1;
    }

    void output() {
        int* pt0 = new int[n](); // pt0 for col, num of fan
        int* pt1 = new int[n](); // pt1 for row, num of focus
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                pt1[i] += mat[i][j];
                pt0[j] += mat[i][j];
            }
        }
        for (int i=0;i<n;i++) {
            cout << pt0[i] - pt1[i] << endl;
        }
        delete[] pt0;
        delete[] pt1;    
    }
};

int main() {
    int n, m, x, y;
    cin >> n >> m;
    FanMat g(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g.insert(x, y);
    }
    g.output();
    return 0;
}
