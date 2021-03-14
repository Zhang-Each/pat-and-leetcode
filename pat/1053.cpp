// 回溯+自定义排序，比较套路的题型
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
int n, m, target;
struct node {
    int val;
    vector<int> son;
};

node tree[MAX];
vector<vector<int>> res;

void travel(int index, vector<int> &path, int sum) {
    if (sum == target && tree[index].son.size() == 0) {
        res.push_back(path);
        return;
    } else if (sum < target) {
        for (int i = 0; i < tree[index].son.size(); i ++) {
            int delta = tree[tree[index].son[i]].val;
            if (sum + delta <= target) {
                path.push_back(delta);
                travel(tree[index].son[i], path, sum + delta);
                path.pop_back();
            }
        }
    }
}

bool cmp(vector<int> x, vector<int> y) {
    int len = min(x.size(), y.size());
    for (int i = 0; i < len; i ++) {
        if (x[i] != y[i]) {
            return x[i] > y[i];
        }
    }
    return x.size() > y.size();
}

int main()
{
    cin >> n >> m >> target;
    for (int i = 0; i < n; i ++) {
        cin >> tree[i].val;
    }
    for (int i = 0; i < m; i ++) {
        int num, father, son;
        cin >> father >> num;
        for (int j = 0; j < num; j ++) {
            cin >> son;
            tree[father].son.push_back(son);
        }
        sort(tree[father].son.begin(), tree[father].son.end());
    }
    vector<int> temp;
    temp.push_back(tree[0].val);
    travel(0, temp, tree[0].val);
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i ++) {
        for (int j = 0; j < res[i].size(); j ++) {
            if (j != 0) {
                cout << " ";
            }
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}