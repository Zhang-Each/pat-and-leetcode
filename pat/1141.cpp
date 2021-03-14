#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct school {
    string id;
    int number = 0;
    int score = 0;
    int rank = 0;
    int a = 0, b = 0, t = 0;
};
map<string, int> name;
vector<school> res;

bool cmp(const school &a, const school &b) {
    if (a.score > b.score) {
        return true;
    } else if (a.score == b.score) {
        if (a.number < b.number) {
            return true;
        } else if (a.number == b.number && a.id < b.id) {
            return true;
        }
    }
    return false;
}

string toLower(string s) {
    string res;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            res += s[i] - 'A' + 'a';
        } else {
            res += s[i];
        }
    }
    return res;
}

int main()
{
    int n, s;
    string id, sc;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> id >> s >> sc;
        sc = toLower(sc);
        if (name[sc] == 0) {
            school t;
            t.id = sc;
            res.push_back(t);
            name[sc] = res.size();
        }
        if (id[0] == 'A') {
            res[name[sc] - 1].a += s;
        } else if (id[0] == 'B') {
            res[name[sc] - 1].b += s;
        } else if (id[0] == 'T') {
             res[name[sc] - 1].t += s;
        }
        res[name[sc] - 1].number += 1;
    }
    for (int i = 0; i < res.size(); i ++) {
        res[i].score = int(1.0 * res[i].b / 1.5 + res[i].a + (double)res[i].t * 1.5);
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i ++) {
        res[i].rank = i + 1;
    }
    for (int i = 1; i < res.size(); i ++) {
        if (res[i].score == res[i - 1].score) {
            res[i].rank = res[i - 1].rank;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i ++) {
        cout << res[i].rank << " " << res[i].id << " " << res[i].score << " " << res[i].number << endl;
    }
    return 0;
}