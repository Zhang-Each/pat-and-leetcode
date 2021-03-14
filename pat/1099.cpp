#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100
struct node {
    int val;
    int left = -1;
    int right = -1;
};
node* t = new node[MAX];
vector<int> val, in, level;

void travel(int n)
{
    if (n == -1) {
        return;
    } else {
        travel(t[n].left);
        in.push_back(n);
        travel(t[n].right);
    }
}

int main ()
{
    int n, l, r, num;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> l >> r;
        t[i].left = l;
        t[i].right = r;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        val.push_back(num);
    }
    sort(val.begin(), val.end());
    travel(0);
    for (int i = 0; i < n; i ++) {
        t[in[i]].val = val[i];
    }
    queue<node> q;
    q.push(t[0]);
    while (q.size() > 0) {
        node p = q.front();
        q.pop();
        level.push_back(p.val);
        if (p.left != -1) {
            q.push(t[p.left]);
        }
        if (p.right != -1) {
            q.push(t[p.right]);
        }
    }
    for (int i = 0; i < n; i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << level[i];
    }
    cout << endl;
    return 0;
}