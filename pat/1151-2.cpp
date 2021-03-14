#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node {
    int val;
    node* left = NULL;
    node* right = NULL;
};

vector<int> pre, in, post;
map<int, int> num;

void build(node* &t, int pre1, int pre2, int in1, int in2) {
    if (pre1 > pre2 || in1 > in2) {
        return;
    }
    t = new node;
    t->val = pre[pre1];
    int i, len;
    for (i = in1; i <= in2; i ++) {
        if (in[i] == pre[pre1]) {
            break;
        }
    }
    len = i - in1;
    build(t->left, pre1 + 1, pre1 + len, in1, i - 1);
    build(t->right, pre1 + len + 1, pre2, i + 1, in2);
}

node* LCA(node* root, node* u, node* v){
	if (u == root || v == root || root == nullptr) {
        return root;
    }
    node* left = LCA(root->left, u, v);
    node* right = LCA(root->right, u, v);
    if (left != NULL && right != NULL) {
        return root;
    }
    return left ? left : right;
}

node* find(node* root, int x) {
    if (root == NULL || root->val == x) {
        return root;
    }
    node* t = find(root->left, x);
    if (t == NULL) {
        return find(root->right, x);
    }
    return t;
}

int main()
{
    int m, n, val;
    cin >> m >> n;
    for (int i = 0; i < n; i ++) {
        cin >> val;
        in.push_back(val);
        num[val] = 1;
    }
    for (int i = 0; i < n; i ++) {
        cin >> val;
        pre.push_back(val);
    }
    node * root = NULL;
    build(root, 0, n - 1, 0, n - 1);
    cout << root->left->val << " " << root->right->val << endl;
    int a, b;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        if (num[a] != 1 && num[b] != 1) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (num[a] != 1) {
            printf("ERROR: %d is not found.\n", a);
        } else if (num[b] != 1) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            node* x = find(root, a);
            node* y = find(root, b);
            node* res = LCA(root, x, y);
            if (res->val != a && res->val != b) {
                printf("LCA of %d and %d is %d\n", a, b, root->val);
            } else if (res->val == a && res->val != b) {
                printf("%d is an ancestor of %d.", a, b);
            } else if (res->val != a && res->val == b) {
                printf("%d is an ancestor of %d.\n", b, a);
            } else {
                printf("%d is an ancestor of %d.\n", b, a);
            }
            
        }
    }
    return 0;
}