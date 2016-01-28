/***********************************************
# Title: fan game
# Author : johnfarrell  
# Date   : 2016-01-28
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/7186
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
