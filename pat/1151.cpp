#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> pre, in, post;
map<int, int> num;

void LCA(int in1, int in2, int root, int a, int b) {
    if (in1 > in2) {
        return;
    }
    int pos0 = num[pre[root]], pos1 = num[a], pos2 = num[b];
    if (pos1 < pos0 && pos2 < pos0) {
        LCA(in1, pos0 - 1, root + 1, a, b);
    } else if ((pos1 > pos0 && pos2 < pos0) || (pos1 < pos0 && pos2 > pos0)) {
        printf("LCA of %d and %d is %d.\n", a, b, in[pos0]);
    } else if (pos1 > pos0 && pos2 > pos0) {
        LCA(pos0 + 1, in2, root + 1 + pos0 - in1, a, b);
    } else if (pos1 == pos0) {
        printf("%d is an ancestor of %d.\n", a, b);
    } else if (pos2 == pos0) {
        printf("%d is an ancestor of %d.\n", b, a);
    }
}


int main()
{
    int m, n, val;
    cin >> m >> n;
    pre.push_back(-1);
    in.push_back(-1);
    for (int i = 0; i < n; i ++) {
        cin >> val;
        in.push_back(val);
        num[val] = i + 1;
    }
    for (int i = 0; i < n; i ++) {
        cin >> val;
        pre.push_back(val);
    }

    int a, b;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        if (num[a] < 1 && num[b] < 1) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (num[a] < 1) {
            printf("ERROR: %d is not found.\n", a);
        } else if (num[b] < 1) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            LCA(1, n, 1, a, b);
        }
    }
    return 0;
}