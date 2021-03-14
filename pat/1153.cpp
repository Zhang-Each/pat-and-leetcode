#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct pat {
    string id, site, date, tester;
    char level;
    int score;
    pat(string s, int num) {
        id = s;
        level = s[0];
        site = s.substr(1, 3);
        date = s.substr(4, 6);
        tester = s.substr(11, 4);
        score = num;
    }
};

struct sit {
    string site;
    int num;
    sit(string x, int y) {
        site = x;
        num = y;
    }
};

bool cmp(const pat &x, const pat &y) {
    if (x.score > y.score) {
        return true;
    } else if (x.score == y.score) {
        if (x.id < y.id) {
            return true;
        }
    }
    return false;
}

bool cmp2(const sit &a, const sit &b) {
    if (a.num > b.num) {
        return true;
    } else if (a.num == b.num) {
        if (a.site < b.site) {
            return true;
        }
    }
    return false;
}

vector<pat> res;
map<string, int> num;
map<string, int> total;
map<string, map<string, int>> table;

int main()
{
    int n, m, score;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> s >> score;
        pat temp(s, score);
        res.push_back(temp);
        num[temp.site] += 1;
        total[temp.site] += temp.score;
        table[temp.date][temp.site] += 1;
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 1; i <= m; i ++) {
        int op;
        cin >> op;
        if (op == 1) {
            char level;
            cin >> level;
            printf("Case %d: 1 %c\n", i, level);
            int count = 0;
            for (int i = 0; i < n; i ++) {
                if (res[i].level == level) {
                    cout << res[i].id << " " << res[i].score << endl;
                    count += 1;
                }
            }
            if (count == 0) {
                cout << "NA" << endl;
            }
        } else if (op == 2) {
            string site;
            cin >> site;
            printf("Case %d: 2 %s\n", i, site.c_str());
            if (num[site] == 0 || total[site] == 0) {
                cout << "NA" << endl;
            } else {
                cout << num[site] << " " << total[site] << endl;
            }    
        } else if (op == 3) {
            string date;
            cin >> date;
            printf("Case %d: 3 %s\n", i, date.c_str());
            map<string, int>::iterator it = table[date].begin();
            vector<sit> t;
            while (it != table[date].end()) {
                if (it->second != 0) {
                    sit temp(it->first, it->second);
                    t.push_back(temp);
                }
                it ++;
            }
            if (t.size() == 0) {
                cout << "NA" << endl;
                continue;
            }
            sort(t.begin(), t.end(), cmp2);
            for (int j = 0; j < t.size(); j ++) {
                cout << t[j].site << " " << t[j].num << endl;
            }
        }
    }
    return 0;
}