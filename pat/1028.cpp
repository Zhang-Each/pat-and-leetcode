#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct student {
    string id;
    string name;
    int score;
    student(string x, string y, int z) {
        id = x;
        name = y;
        score = z;
    }
};

vector<student> res;

bool cmp1(student &a, student &b) {
    return a.id < b.id;
}

bool cmp2(student &a, student &b) {
    if (a.name < b.name) {
        return true;
    } else if (a.name == b.name) {
        return a.id < b.id;
    }
    return false;
}

bool cmp3(student &a, student &b) {
    if (a.score < b.score) {
        return true;
    } else if (a.score == b.score) {
        return a.id < b.id;
    }
    return false;
}


int main()
{
    int n, op, s;
    cin >> n >> op;
    string x, y;
    for (int i = 0; i < n; i ++) {
        cin >> x >> y >> s;
        student t(x, y, s);
        res.push_back(t);
    }
    if (op == 1) {
        sort(res.begin(), res.end(), cmp1);
    } else if (op == 2) {
        sort(res.begin(), res.end(), cmp2);
    } else {
        sort(res.begin(), res.end(), cmp3);
    }
    for (int i = 0; i < res.size(); i ++) {
        printf("%s %s %d\n", res[i].id.c_str(), res[i].name.c_str(), res[i].score);
    }
    return 0;
}