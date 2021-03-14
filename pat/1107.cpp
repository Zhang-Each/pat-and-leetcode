#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1001
using namespace std;

int n;
int f[MAXN] = {0};
int cnt[MAXN] = {0};
vector<vector<int> > v;

int Find(int x) {
    if (f[x] == 0) {
        return x;
    } else {
        return f[x] = Find(f[x]);
    }
}

int Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy) f[fy] = fx;
    return fx;
}

bool cmp(int x, int y) {
    return x > y;
}

int main() 
{
    scanf("%d" , &n);
    for (int i = 0; i < n; i ++) {
        int len;
        scanf("%d: ", &len);
        vector<int> h(len);
        for (int j = 0; j < len; j ++) {
            scanf("%d", &h[j]);
        }
        // 这里其实是将一个人的爱好转化成树状的关系，因为只要有一个爱好相同就组成一个cluster
        // 所以一个人的所有爱好可以作为并查集中的一棵树，然后根据后面输入的爱好不断扩充树的关系
        for (int j = 1; j < len; j ++) {
            Union(h[0], h[j]);
        }
        v.push_back(h);
    }
    int num = 0;
    for (int i = 0; i < n; i ++) {
        int root = Find(v[i][0]);
        if (cnt[root] == 0) {
            num ++;
        }
        cnt[root] += 1;
    }
    sort(cnt, cnt + MAXN, cmp);
    printf("%d\n", num);
    for (int i = 0; i < num; i ++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", cnt[i]);
    }
    cout << endl;
    return 0;
}