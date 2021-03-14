#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> pre, in;

int main()
{
    int m, n, num;
    cin >> m >> n;
    map<int, int> num_map;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        pre.push_back(num);
        num_map[num] = 1;
    }
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        if (num_map[a] == 0 && num_map[b] == 0) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (num_map[a] == 0) {
            printf("ERROR: %d is not found.\n", a);
        } else if (num_map[b] == 0) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            int res = -1;
            for (int i = 0; i < n; i ++) {
                if (pre[i] >= min(a, b) && pre[i] <= max(a, b)) {
                    res = pre[i];
                    break;
                }
            }
            if (res == a) {
                printf("%d is an ancestor of %d.\n", a, b);
            } else if (res == b) {
                printf("%d is an ancestor of %d.\n", b, a);
            } else {
                printf("LCA of %d and %d is %d.\n", a, b, res);
            }
        }
    }
    return 0;
}