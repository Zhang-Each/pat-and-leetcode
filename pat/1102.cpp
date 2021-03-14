#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int parent = -1;
    int left = -1;
    int right = -1;
};
node* t;
vector<int> in, level;

void show(vector<int> s) {
    for (int i = 0; i < s.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << endl;
}

void traval(int n) {
    if (n != -1) {
        traval(t[n].left);
        in.push_back(n);
        traval(t[n].right);
    }
}

int main()
{
    int n, root;
    char l, r;
    cin >> n;
    t = new node[n];
    for (int i = 0; i < n; i ++) {
        cin >> l >> r;
        if (l != '-') {
            t[i].right = l - '0';
            t[l - '0'].parent = i;
        }
        if (r != '-') {
            t[i].left = r - '0';
            t[r - '0'].parent = i;
        }
    }
    for (int i = 0; i < n; i ++) {
        if (t[i].parent == -1) {
            root = i;
        }
    }
    traval(root);
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        level.push_back(p);
        if (t[p].left != -1) {
            q.push(t[p].left);
        }
        if (t[p].right != -1) {
            q.push(t[p].right);
        }
    }
    show(level);
    show(in);
    return 0;
}