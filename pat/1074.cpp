#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

int main()
{
    vector<node> res;
    map<string, node> list;
    string head, add1, add2;
    int n, k, val;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
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
    if (k > 1) {
        for (int i = 0; i < res.size(); i += k) {
            if (res.size() - i < k) {
                break;
            }
            for (int j = i; j <= i + k / 2; j++) {
                swap(res[j], res[i + k - 1 - j]);
            }
        }
    }
    for (int i = 0; i < res.size() - 1; i++) {
        printf("%s %d %s\n", res[i].add.c_str(), res[i].val, res[i + 1].add.c_str());
    }
    printf("%s %d -1\n", res[res.size() - 1].add.c_str(), res[res.size() - 1].val);
    return 0;
}