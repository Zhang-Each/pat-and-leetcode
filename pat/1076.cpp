// 这道题只得了22分，不知道为什么过不了其中两个点，可能是题目意思理解错了
#include <iostream>
#include <set>
#include <map>
using namespace std;

#define MAX 1001
set<int> follow[MAX];
int n, l, k;
int has[MAX] = {0};

void forward(int index, int count, int &total) {
    if (count >= l) {
        return ;
    }
    set<int>::iterator it = follow[index].begin();
    while (it != follow[index].end()) {
        if (!has[*it]) {
            total += 1;
            has[*it] = 1;
            forward(*it, count + 1, total);
        }
        it ++;
    }
}

int main()
{
    int query;
    cin >> n >> l;
    for (int i = 1; i <= n; i ++) {
        int m, num;
        cin >> m;
        for (int j = 0; j < m; j ++) {
            cin >> num;
            follow[num].insert(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i ++) {
        cin >> query;
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            has[i] = 0;
        }
        forward(query, 0, res);
        cout << res << endl;
    }
    return 0;
}