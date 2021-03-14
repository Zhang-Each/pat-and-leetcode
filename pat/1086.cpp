#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<int> pre, in, post;
struct node {
    int val;
    node* left= NULL;
    node* right = NULL;
};

void show(vector<int> s) {
    for (int i = 0; i < s.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << endl;
}

void build(node* &t, int pre1, int pre2, int in1, int in2) {
    if (pre1 > pre2) {
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
    int num = i - in1;
    build(t->left, pre1 + 1, pre1 + num, in1, i - 1);
    build(t->right, pre1 + 1 + num, pre2, i + 1, in2);
}

void travel(node* t) {
    if (t != NULL) {
        travel(t->left);
        travel(t->right);
        post.push_back(t->val);
    }
}

int main ()
{
    stack<int> t;
    string s;
    int n, m;
    cin >> n;
    for (int i = 0; i < 2 * n; i ++) {
        cin >> s;
        if (s == "Push") {
            cin >> m;
            t.push(m);
            pre.push_back(m);
        } else {
            m = t.top();
            t.pop();
            in.push_back(m);
        }
    }
    node* root = NULL;
    build(root, 0, n - 1, 0, n - 1);
    travel(root);
    show(post);
    return 0;
}