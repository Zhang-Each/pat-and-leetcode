#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 10001

struct student {
    string id;
    int final = -1;
    int mid = -1;
    int total = -1;
    int assignment = -1;
    bool operator < (const student &s) const {
        if (total == -1 || s.total == -1) {
            return s.total < total;
        } else if (total == s.total) {
            return id < s.id;
        } else {
            return total > s.total;
        }
    }
};

vector<student> s;
map<string, int> name;

void add(string id) {
    name[id] = s.size() + 1;
    student t;
    t.id = id;
    s.push_back(t);
}

int main()
{
    int p, m, n;
    int val;
    string id;
    
    cin >> p >> m >> n;
    for (int i = 0; i < p; i ++) {
        cin >> id >> val;
        if (name[id] == 0) {
            add(id);
        }
        s[name[id] - 1].assignment = val;
    }
    for (int i = 0; i < m; i ++) {
        cin >> id >> val;
        if (name[id] == 0) {
            add(id);
        }
        s[name[id] - 1].mid = val;
    }
    for (int i = 0; i < n; i ++) {
        cin >> id >> val;
        if (name[id] == 0) {
            add(id);
        }
        s[name[id] - 1].final = val;
    }
    for (int i = 0; i < n; i ++) {
        if (s[i].assignment < 200 || s[i].final == -1) {
            continue;
        } else {
            if (s[i].mid == -1 || s[i].mid < s[i].final) {
                if (s[i].final >= 60) {
                    s[i].total = s[i].final;
                }
            } else if (s[i].mid > s[i].final && s[i].final != -1) {
                s[i].total = (int)round(s[i].mid * 0.4 + s[i].final * 0.6);
            }
        }
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i ++) {
        if (s[i].total >= 60) {
            printf("%s %d %d %d %d\n",s[i].id.c_str(), s[i].assignment, s[i].mid, s[i].final, s[i].total);
        }
    }
    return 0;
}