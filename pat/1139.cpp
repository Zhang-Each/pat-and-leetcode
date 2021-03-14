// 这题测试样例全过了，交上去只有20分，不知道为什么了
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 301
int g[MAX][MAX] = {0};
int node[10000] = {0};
int n, m, k, number = 1;
map<int, int> gender, label;

struct Node {
    int x, y;
    Node (int a, int b) {
        x = a;
        y = b;
    }
};

int cmp(Node &a, Node &b) {
    if (a.x < b.x) {
        return true;
    } else if (a.x == b.x) {
        return a.y < b.y;
    }
    return false;
}

void add(int x) {
    if (node[abs(x)] == 0) {
        node[abs(x)] = number;
        gender[number] = x > 0 ? 1 : -1;
        label[number] = abs(x);
        number ++;
    }
}

int main()
{
    int id1, id2;
    cin >> n >> m;
    for (int i = 0 ; i < m; i ++) {
        cin >> id1 >> id2;
        add(id1);
        add(id2);
        g[node[abs(id1)]][node[abs(id2)]] = g[node[abs(id2)]][node[abs(id1)]] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i ++) {
        cin >> id1 >> id2;
        vector<Node> res;
        int a = node[abs(id1)], b = node[abs(id2)];
        for (int j = 1; j <= n; j ++) {
            for (int k = 1; k <= n; k ++) {
                if (g[a][j] && g[b][k] && g[j][k] && gender[j] == gender[a] && gender[k] == gender[b]) {
                    Node temp(label[j] ,label[k]);
                    res.push_back(temp);
                }
            }
        }
        sort(res.begin(), res.end(), cmp);
        cout << res.size() << endl;
        for (int j = 0; j < res.size(); j ++) {
            printf("%04d %04d\n", res[j].x, res[j].y);
        }
    }
    return 0;
}