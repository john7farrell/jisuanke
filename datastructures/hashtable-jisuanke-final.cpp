/***********************************************
# Title: 
# Author : johnfarrell  
# Date   : 2015
# HomePage : github.com/john7farrell/
# Email  : xjz199273@163.com
***********************************************/
//http://www.jisuanke.com/course/35/5428
/*
输入格式：
输入第一行是一个正整数 N (1 <= N <= 100000)，表示一共有 N 个用户名。接下来有 N 行，每一行是一个用户名，长度不超过 100，均由大写字母和小写字母组成。
输出格式：
请按照输入顺序输出，如果用户名在前面出现过则输出“Yes”，否则输出“No”，一行输出一个。
样例1
输入：
5
AbC
jisuanke
abc
JiSuanKe
Hello
输出：
No
No
Yes
Yes
No
提示信息
可以参考之前课程的代码。
建议将 size 设置为 200000 以上。
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable() {
        size = 200000;
        elem = new string[size];
        for (int i = 0; i < size; i++) {
            elem[i] = "#";
        }
    }
    ~HashTable() {
        delete[] elem;
    }
    int hash(string& index) {
        int code = 0;
        for (size_t i = 0; i < index.length(); i++) {
            code = (code * 256 + index[i] + 128) % size;
        }
        return code;
    }
    bool search(string& index, int& pos, int& times) {
        pos = hash(index);
        times = 0;
        while (elem[pos] != "#" && elem[pos] != index) {
            times++;
            if (times < size) {
                pos = (pos + 1) % size;
            } else {
                return false;
            }
        }
        if (elem[pos] == index) {
            return true;
        } else {
            return false;
        }
    }
    int insert(string& index) {
        int pos, times;
        if (search(index, pos, times)) {
            return 2;
        } else if (times < size / 2) {
            elem[pos] = index;
            return 1;
        } else {
            recreate();
            return 0;
        }
    }
	string strtoupper(string s) {
		//transform(s.begin(), s.end(), s.begin(), toupper);
		//return s;
		for (int i=0;i<s.length();i++) {
			if(s[i]>='a'&&s[i]<='z') {
				s[i] = s[i] - 32;
			} else {
				continue;
			}
		}
		return s;
	}

    void recreate() {
        string *temp_elem;
        temp_elem= new string[size];
        for (int i=0;i<size;i++) {
            temp_elem[i] = elem[i];
        }
        int copy_size = size;
        size = size * 2;
        delete[] elem;
        elem = new string[size];
        for (int i=0;i<size;i++) {
            elem[i] = "#";
        }
        for (int i=0;i<copy_size;i++) {
            if (temp_elem[i]!="#") {
                insert(temp_elem[i]);
            }
        }
        delete[] temp_elem;
    }
};
int main() {
    HashTable hashtable;
    string buffer;
    int n;// Number of usernames
    cin >> n;
	string *outpt;
	outpt = new string[n];
    for (int i = 1; i <= n; i++) {
        cin >> buffer;// username repeat for n times
		buffer = hashtable.strtoupper(buffer);
        int ans = hashtable.insert(buffer);
        if (ans == 0) {
            cout << "insert failed!" << endl;
        } else if (ans == 1) {
            //cout << "insert success!" << endl;
			//cout << "No" << endl;
			outpt[i-1] = "No";
        } else if (ans == 2) {
            //cout << "It already exists!" << endl;
			//cout << "Yes" << endl;
			outpt[i-1] = "Yes";
        }
    }
	for (int i=0;i<n;i++) {
		cout<<outpt[i]<<endl;
	}
	delete[] outpt;
/*    int temp_pos, temp_times;
    cin >> buffer;
    if (hashtable.search(buffer, temp_pos, temp_times)) {
        cout << "search success!" << endl;
    } else {
        cout << "search failed!" << endl;
    }*/
	//system("pause");
    return 0;
}
