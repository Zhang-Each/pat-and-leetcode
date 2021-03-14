#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct pat {
    int s;
    string id;
    int g;
    int g_rank = 0;
    int t_rank = 0;
    pat(int x, string y, int z) {
        s = x;
        id = y;
        g = z;
    }
};

vector<pat> total;
vector<vector<pat>> site;

bool cmp(pat &a, pat &b) {
    if (a.s > b.s) {
        return true;
    } else if (a.s == b.s) {
        return a.g < b.g;
    }
    return false;
}

bool cmp2(pat &a, pat &b) {
    if (a.t_rank < b.t_rank) {
        return true;
    } else if (a.t_rank == b.t_rank) {
        return a.id < b.id;
    }
    return 0;
}

int main()
{
    int n, k, m;
    string t;
    cin >> k;
    for (int i = 1; i <= k; i ++) {
        cin >> n;
        vector<pat> single;
        for (int j = 0; j < n; j ++) {
            cin >> t >> m;
            pat temp(m, t, i);
            single.push_back(temp);
        }
        sort(single.begin(), single.end(), cmp);
        int r = 1;
        for (int i = 0; i < single.size(); i ++) {
            if (i >= 1 && single[i].s != single[i - 1].s) {
                r = i + 1;
            }
            single[i].g_rank = r;
            total.push_back(single[i]);
        }
    }
    sort(total.begin(), total.end(), cmp);
    int r = 1;
    for (int i = 0; i < total.size(); i ++) {
        if (i >= 1 && total[i].s != total[i - 1].s) {
            r = i + 1;
        }
        total[i].t_rank = r;
    }
    sort(total.begin(), total.end(), cmp2);
    cout << total.size() << endl;
    for (int i = 0; i < total.size(); i ++) {
        printf("%s %d %d %d\n", total[i].id.c_str(), total[i].t_rank, total[i].g, total[i].g_rank);
    }
    return 0;
}