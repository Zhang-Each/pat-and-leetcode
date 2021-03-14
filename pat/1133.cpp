#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

struct node {
    string add, next;
    int val;
    node(string x, int y, string z) {
        add = x;
        val = y;
        next = z;
    }
    node() {}
};

void showList(vector<node> res) {
    if (res.size() == 0) {
        return;
    }
    for (int i = 0; i < res.size() - 1; i++) {
        printf("%s %d %s\n", res[i].add.c_str(), res[i].val, res[i + 1].add.c_str());
    }
    printf("%s %d -1\n", res[res.size() - 1].add.c_str(), res[res.size() - 1].val);
}

int main()
{
    int n, val, k;
    string head, add1, add2;
    vector<node> res;
    map<string, node> list;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> add1 >> val >> add2;
        if (add1 == "-1") {
            continue;
        }
        node temp(add1, val, add2);
        list[add1] = temp;
    }
    while (head != "-1") {
        res.push_back(list[head]);
        head = list[head].next;
    }
    vector<node> l1, l2, l3, l;
    for (int i = 0; i < res.size(); i ++) {
        if (res[i].val < 0) {
            l1.push_back(res[i]);
        } else if (res[i].val <= k) {
            l2.push_back(res[i]);
        } else {
            l3.push_back(res[i]);
        }
    }
    l1.insert(l1.end(), l2.begin(), l2.end());
    l1.insert(l1.end(), l3.begin(), l3.end());
    showList(l1);
    return 0;
}