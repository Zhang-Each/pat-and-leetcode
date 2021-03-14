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
    int n, val;
    string head, add1, add2;
    vector<node> res;
    map<string, node> list;
    cin >> head >> n;
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
    map<int, int> nums;
    vector<node> l1, l2;
    for (int i = 0; i < res.size(); i ++) {
        if (nums[abs(res[i].val)] == 0) {
            nums[abs(res[i].val)] = 1;
            l1.push_back(res[i]);
        } else {
            l2.push_back(res[i]);
        }
    }
    showList(l1);
    showList(l2);
    return 0;
}