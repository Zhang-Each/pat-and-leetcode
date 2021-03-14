#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <algorithm>
using namespace std;

struct node {
    int add, next, val;
    node (int x, int y, int z) {
        add = x;
        next = y;
        val = z;
    }
    node () {}
};

map<int, node> list;

int main()
{
    int head, n, k, x, y, z;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> x >> z >> y;
        node temp(x, y, z);
        list[x] = temp;
    }
    vector<node> l, res;
    while (head != -1) {
        l.push_back(list[head]);
        head = list[head].next;
    }
    int i;
    for (i = 0; i < l.size(); i += k) {
        if (i + k - 1 >= l.size()) {
            for (int j = l.size() - 1; j >= i; j --) {
                res.push_back(l[j]);
            }
            break;
        }
        for (int j = i + k - 1; j >= i; j --) {
            res.push_back(l[j]);
        }
    }
    for (int i = res.size() - 1; i >= 1; i --) {
        printf("%05d %d %05d\n", res[i].add, res[i].val, res[i - 1].add);
    }
    printf("%05d %d -1\n", res[0].add, res[0].val);
    return 0;
}