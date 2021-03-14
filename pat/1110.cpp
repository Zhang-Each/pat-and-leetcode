#include <iostream>
#include <string>
using namespace std;

struct node {
    int parent = -1;
    int left = -1;
    int right = -1;
};

node* t;
int* tree;
int n;

void makeCBT(int i, int index) {
    if (index < n && i != -1) {
        tree[index] = i;
        makeCBT(t[i].left, 2 * index + 1);
        makeCBT(t[i].right, 2 * index + 2);
    }
}

int main()
{
    string x, y;
    cin >> n;
    t = new node[n];
    tree = new int[n];
    for (int i = 0; i < n; i ++) {
        tree[i] = -1;
    }
    for (int i = 0; i < n; i ++) {
        cin >> x >> y;
        if (x != "-") {
            t[i].left = atoi(x.c_str());
            t[atoi(x.c_str())].parent = i;
        }
        if (y != "-") {
            t[i].right = atoi(y.c_str());
            t[atoi(y.c_str())].parent = i;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i ++) {
        if (t[i].parent == -1) {
            root = i;
            break;
        }
    }
    makeCBT(root, 0);
    for (int i = 0; i < n; i ++) {
        if (tree[i] == -1) {
            cout << "NO " << root << endl;
            return 0;
        }
    }
    cout << "YES " << tree[n - 1] << endl;
    return 0;
} 