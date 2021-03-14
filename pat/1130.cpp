#include <iostream>
#include <string>
using namespace std;

struct node {
    string val;
    int parent = -1;
    int left = -1;
    int right = -1;
};

node* t;
string res;

void travel(int index) {
    if (index != -1) {
        int flag = 0;
        if (t[index].left != -1 || t[index].right != -1) {
            flag = 1;
        }
        if (flag == 1) {
            res += '(';
        }
        travel(t[index].left);
        res += t[index].val;
        travel(t[index].right);
        if (flag == 1) {
            res += ')';
        }
    }
}

int main()
{
    int n, a, b;
    string val;
    cin >> n;
    t = new node[n + 1];
    for (int i = 1; i <= n; i ++) {
        cin >> val >> a >> b;
        t[i].val = val;
        t[i].left = a;
        t[i].right = b;
        if (a != -1) {
            t[a].parent = i;
        }
        if (b != -1) {
            t[b].parent = i;
        }
    }
    int root = 0;
    for (int i = 1; i <= n; i ++) {
        if (t[i].parent == -1) {
            root = i;
            break;
        }
    }
    travel(root);
    if (res.size() <= 2) {
        cout << res << endl;
    } else {
        cout << res.substr(1, res.size() - 2) << endl;
    }
    return 0;
}