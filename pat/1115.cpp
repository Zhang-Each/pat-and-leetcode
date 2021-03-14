#include <iostream>
#include <vector>
using namespace std;

struct node {
    int val = -1001;
    int left = -1;
    int right = -1;
    int level = -1;
};

node* t;
int maxLevel = 0;

void insert(int x, int y) {
    if (t[x].val < t[y].val) {
        if (t[x].right == -1) {
            t[x].right = y;
            return;
        } else {
            insert(t[x].right, y);
        }
    } else {
        if (t[x].left == -1) {
            t[x].left = y;
            return;
        } else {
            insert(t[x].left, y);
        }
    }
}

void setLevel(int index, int level) {
    if (index != -1) {
        t[index].level = level;
        if (level > maxLevel) {
            maxLevel = level;
        }
        setLevel(t[index].left, level + 1);
        setLevel(t[index].right, level + 1);
    }
}

int main()
{
    int n, num;
    cin >> n;
    t = new node[n];
    for (int i = 0; i < n; i ++) {
        cin >> num;
        t[i].val = num;
        if (i >= 1) {
            insert(0, i);
        }
    }
    setLevel(0, 1);
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i ++) {
        if (t[i].level == maxLevel) {
            count1 += 1;
        } else if (t[i].level == maxLevel - 1) {
            count2 += 1;
        }
    }
    printf("%d + %d = %d", count1, count2, count1 + count2);
    return 0;
}