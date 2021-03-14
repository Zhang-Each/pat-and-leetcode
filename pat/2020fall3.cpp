#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int val;
    int level = -1;
    node* left = NULL;
    node *right = NULL;
};
vector<int> pre, in;
vector<int> level[100];
node *t = NULL;

void build(node* &t, int pre1, int pre2, int in1, int in2) {
    if (pre1 > pre2 || in1 > in2) {
        return;
    }
    t = new node;
    t->val = pre[pre1];
    int i;
    for (i = in1; i <= in2; i ++) {
        if (in[i] == pre[pre1]) {
            break;
        }
    }
    int len = i - in1;
    build(t->left,pre1 + 1, pre1 + len, in1, i - 1);
    build(t->right, pre1 + len + 1, pre2, i + 1, in2);
}

void set(node *t, int l) {
    if (t != NULL) {
        t->level = l;
        set(t->left, l + 1);
        set(t->right, l + 1);
    }
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n ; i ++) {
        cin >> x;
        in.push_back(x);
    }
    for (int i = 0; i < n; i ++) {
        cin >> x;
        pre.push_back(x);
    }
    build(t, 0, n - 1, 0 , n - 1);
    set(t, 1);
    queue<node*> q;
    q.push(t);
    while (q.size() != 0) {
        node* p = q.front();
        q.pop();
        level[p->level].push_back(p->val);
        if (p->left != NULL) {
            q.push(p->left);
        }
        if (p->right != NULL) {
            q.push(p->right);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (level[i].size() == 0) {
            break;
        }
        if (i != 1) {
            cout << " ";
        }
        cout << level[i][0];
    }
    return 0;
}