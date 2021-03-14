#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<int> level, in, post;
struct node {
    int val;
    node* left = NULL;
    node* right = NULL;
};

void travel(node* t) {
    if (t == NULL) {
        return;
    }
    queue<node*> s;
    s.push(t);
    while (s.size() > 0) {
        node* p = s.front();
        level.push_back(p->val);
        if (p->left != NULL) {
            s.push(p->left);
        }
        if (p->right != NULL) {
            s.push(p->right);
        }
        s.pop();
    }
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

void build(node* &t, int in1, int in2, int post1, int post2) {
    if (in1 > in2 || post1 > post2) {
        return;
    }
    t = new node;
    t->val = post[post2];
    int i;
    for (i = in1; i < in2; i++) {
        if (in[i] == post[post2]) {
            break;
        }
    }
    int num = i - in1;
    build(t->left, in1, i - 1, post1, post1 + num - 1);
    build(t->right, i + 1, in2, post1 + num, post2 - 1);
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> m;
        post.push_back(m);
    }
    for (int i = 0; i < n; i ++) {
        cin >> m;
        in.push_back(m);
    }
    node* root = NULL;
    build(root, 0, n - 1, 0, n - 1);
    travel(root);
    show(level);
    return 0;
}