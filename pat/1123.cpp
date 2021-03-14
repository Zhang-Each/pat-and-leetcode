#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct TreeNode *pointer;
typedef pointer Tree;
struct TreeNode {
    int val;
    int height;
    int id;
    Tree left;
    Tree right;
};

int getHeight(Tree T) {
    if (T == NULL) return -1;
    else {
        int x, y;
        x = getHeight(T->left);
        y = getHeight(T->right);
        if (x > y) return x + 1;
        else return y + 1;
    }
}

Tree Lrotation(Tree T) {
    Tree S = T->left;
    T->left = S->right;
    S->right = T;
    T->height = getHeight(T);
    S->height = getHeight(S);
    return S;
}

Tree Rrotation(Tree T) {
    Tree S = T->right;
    T->right = S->left;
    S->left = T;
    T->height = getHeight(T);
    S->height = getHeight(S);
    return S;
}

Tree LRrotation(Tree T) {
    T->left = Rrotation(T->left);
    return Lrotation(T);
}

Tree RLrotation(Tree T) {
    T->right = Lrotation(T->right);
    return Rrotation(T);
}

Tree AVLInsert(int x, Tree T) {
    if (T == NULL) {
        T = (Tree)malloc(sizeof(struct TreeNode));
        T->val = x;
        T->left = NULL;
        T->right = NULL;
        T->height = 0;
        return T;
    } else if (T != NULL) {
        if (x > T->val) {
            T->right = AVLInsert(x, T->right);
            if (abs(getHeight(T->left) - getHeight(T->right)) >= 2) {
                if (x < T->right->val) T = RLrotation(T);
                else T = Rrotation(T);
            }
        } else if (x <= T->val) {
            T->left = AVLInsert(x, T->left);
            if (abs(getHeight(T->left) - getHeight(T->right)) >= 2) {
                if (x > T->left->val) T = LRrotation(T);
                else T = Lrotation(T);
            }
        }
        T->height = getHeight(T);
        return T;
    }
    return NULL;
}

int node[1000] = {0};
vector<int> res;

void Level_Order(Tree t) {
    if (t == NULL) {
        return;
    }
    queue<Tree> q;
    t->id = 0;
    q.push(t);
    while (q.size() != 0) {
        Tree p = q.front();
        if (p->left != NULL) {
            p->left->id = 2 * p->id + 1;
            q.push(p->left);
        }
        if (p->right != NULL) {
            q.push(p->right);
            p->right->id = 2 * p->id + 2;
        }
        res.push_back(p->val);
        node[p->id] = 1;
        q.pop();
    }
}

int main()
{
    int i, n;
    cin >> n;
    if (n == 1) {
        cin >> i;
        cout << i << endl << "YES" << endl;;
        return 0;
    }
    int *a = new int[n];
    Tree T = NULL;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        T = AVLInsert(a[i], T);
    }
    Level_Order(T);
    for (int i = 0; i < res.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
    bool is = 1;
    for (int i = 0; i < n; i ++) {
        if (node[i] == 0) {
            is = 0;
        }
    }
    if (res.size() <= 1) {
        is = 1;
    } 
    if (is) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}