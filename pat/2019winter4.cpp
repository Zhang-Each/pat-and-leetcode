#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int val;
    node* left = NULL;
    node* right = NULL;
};
int *a;
node *t = NULL;

// 这道题的关键就是根据最小堆的性质建树，每个子树的根节点都是当前序列中最小的那个
void build(node* &root, int left, int right) {
    if (left > right) {
        return;
    }
    root = new node;
    int minv = a[left], mini = left;
    for (int i = left; i <= right; i ++) {
        if (a[i] < minv) {
            minv = a[i];
            mini = i;
        }
    }
    root->val = minv;
    build(root->left, left, mini - 1);
    build(root->right, mini + 1, right);
}

int main()
{
    int n;
    cin >> n;
    a = new int [n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    build(t, 0, n - 1);
    
    vector<int> res;
    queue<node*> q;
    q.push(t);
    while (q.size() != 0) {
        node* p = q.front();
        q.pop();
        res.push_back(p->val);
        if (p->left != NULL) {
            q.push(p->left);
        }
        if (p->right != NULL) {
            q.push(p->right);
        }
    }
    for (int i = 0; i < res.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
}