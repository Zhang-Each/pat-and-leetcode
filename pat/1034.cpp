#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001
int g[MAX][MAX] = {0}, visit[MAX] = {0}, w[MAX] = {0};
map<string, int> label;
map<int, string> label_index;
map<string, int> res;
int cnt = 1, n, m;

void add(string x) {
    if (label[x] == 0) {
        label[x] = cnt;
        label_index[cnt] = x;
        cnt += 1;
    }
}

void dfs(int i, int &maxi, int &maxw, int &num, int &sum) {
    visit[i] = 1;
    num += 1;
    sum += w[i];
    if (w[i] > maxw) {
        maxw = w[i];
        maxi = i;
    }
    for (int j = 1; j < cnt; j ++) {
        if (g[i][j] == 1 && visit[j] == 0) {
            dfs(j, maxi, maxw, num, sum);
        }
    }
}

int main()
{
    int l, number = 0;
    string a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> a >> b >> l;
        add(a);
        add(b);
        g[label[a]][label[b]] = 1;
        w[label[a]] += l;
        w[label[b]] += l;
    }
    for (int i = 1; i < cnt; i ++) {
        int num = 0, maxi = 0, maxw = 0, sum = 0;
        if (visit[i] == 0) {
            dfs(i, maxi, maxw, num, sum);
        }
        if (sum / 2 > m && num >= 3) {
            res[label_index[maxi]] = num;
            number += 1;
        }
    }
    cout << number << endl;
    for (auto it = res.begin(); it != res.end(); it ++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}