#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> in, level;
int n;

void inorder(int index) {
    if (index < n) {
        inorder(2 * index + 1);
        in.push_back(index);
        inorder(2 * index + 2);
    }
}

// 利用完全二叉树的性质，得到中序遍历的下标的顺序，对应着下标赋值就可以了，BST的中序遍历一定是递增的
int main()
{ 
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int *heap = new int[n];
    inorder(0);
    for (int i = 0; i < n; i ++) {
        heap[in[i]] = a[i];
    }
    for (int i = 0; i < n; i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << heap[i];
    }
    cout << endl;
    return 0;
}