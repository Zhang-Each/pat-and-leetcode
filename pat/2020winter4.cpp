#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct equation {
    int p;
    set<int> r;
};
map<int, int> rs;
equation eq[100];
vector<int> products;
vector<vector<int>> res;
int use[100] = {0}, n, m, k, len;

bool can(int index) {
    for (auto it = eq[index].r.begin(); it != eq[index].r.end(); it ++) {
        if (rs[*it] <= 0) {
            return false;
        }
    }
    return true;
}

bool check(vector<int> x, vector<int> y) {
    for (int i = 0; i < m; i ++) {
        if (eq[x[i]].r.size() < eq[y[i]].r.size()) {
            return false;
        } else if (eq[x[i]].r.size() == eq[y[i]].r.size()) {
            auto it1 = eq[x[i]].r.begin(), it2 = eq[y[i]].r.begin();
            while (it1 != eq[x[i]].r.end()) {
                if (*it1 < *it2) {
                    return true;
                }
                it1 ++;
                it2 ++;
            }
        }
    }
    return true;
}

void dfs(int index, vector<int> &solution) {
    if (solution.size() == m) {
        if (res.size() == 0) {
            res.push_back(solution);
        } else {
            if (check(solution, res[res.size() - 1])) {
                res.push_back(solution);
            }
        }
    }
    if (index == n) {
        return;
    }
    //cout << "target == " << products[index] << endl;
    for (int j = 0; j < k; j ++) {
        if (use[j] == 0 && eq[j].p == products[index] && can(j)) {
            vector<int> loss;
            for (auto it = eq[j].r.begin(); it != eq[j].r.end(); it ++) {
                loss.push_back(*it);
                rs[*it] -= 1;
            }
            solution.push_back(j);
            use[j] = 1;
            dfs(index + 1, solution);
            use[j] = 0;
            solution.pop_back();
            for (int x = 0; x < loss.size(); x ++) {
                rs[loss[x]] += 1;
            }
        }
    }
}

int main()
{
    int s;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        rs[s] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i ++) {
        cin >> s;
        products.push_back(s);
    }
    cin >> k;
    string q;
    for (int i = 0; i < k; i ++) {
        while (true) {
            cin >> q;
            if (q == "+") {
                continue;
            }
            if (q == "->") {
                cin >> q;
                eq[i].p = atoi(q.c_str());
                break;
            }
            eq[i].r.insert(atoi(q.c_str()));
        }
    }
    for (int i = 0; i < m; i ++) {
        eq[k].p = products[i];
        eq[k].r.insert(products[i]);
        k += 1;
    }
    vector<int> temp;
    dfs(0, temp);
    int len = res.size() - 1;
    for (int i = 0; i < res[len].size(); i ++) {
        int count = 0;
        for (auto it = eq[res[len][i]].r.begin(); it != eq[res[len][i]].r.end(); it ++) {
            if (count != 0) {
                printf(" + ");
            }
            printf("%02d", *it);
            count += 1;
        }
        printf(" -> %02d\n", eq[res[len][i]].p);
    }
    return 0;
}