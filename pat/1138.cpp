#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<int> pre, in, post;
struct node {
    int val;
    node* left = NULL;
    node* right = NULL;
};

void travel(node* t) {
    if (t != NULL) {
        travel(t->left);
        travel(t->right);
        post.push_back(t->val);
    }
}

void build(node* &root, int pre1, int pre2, int in1, int in2) {
    if (pre1 > pre2 || in1 > in2) {
        return;
    }
    root = new node;
    root->val = pre[pre1];
    int i;
    for (i = in1; i <= in2; i ++) {
        if (in[i] == pre[pre1]) {
            break;
        }
    }
    int len = i - in1;
    build(root->left, pre1 + 1, pre1 + len, in1, i - 1);
    build(root->right, pre1 + len + 1, pre2, i + 1, in2);
}

void show(vector<int> s) {
    for (int i = 0; i < s.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n ; i ++) {
        cin >> m;
        pre.push_back(m);
    }
    for (int i = 0; i < n ; i ++) {
        cin >> m;
        in.push_back(m);
    }

    node* root = NULL;
    build(root, 0, n - 1, 0, n - 1);
    travel(root);
    cout << post[0] << endl;
    return 0;
}
