#include <iostream>
#include <vector>
#include <string>
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

bool cmp(node &a, node &b) {
    return a.val < b.val;
}

int main()
{
    int n, v;
    vector<node> res;
    string add1, add2, head;
    map<string, node> list;
    cin >> n >> head;
    for (int i = 0; i < n; i ++) {
        cin >> add1 >> v >> add2;
        if (add1 == "-1") {
            continue;
        }
        node temp(add1, v, add2);
        list[add1] = temp;
    }
    
    while (head != "-1") {
        res.push_back(list[head]);
        head = list[head].next;
    }
    if (res.size() == 0) {
        cout << "0 -1" << endl;
        return 0;
    }
    sort(res.begin(), res.end(), cmp);
    cout << res.size() << " " << res[0].add << endl;
    for (int i = 0; i < res.size() - 1; i ++) {
        printf("%s %d %s\n", res[i].add.c_str(), res[i].val, res[i + 1].add.c_str());
    }
    cout << res[res.size() - 1].add << " " << res[res.size() - 1].val << " -1" << endl;
    return 0;
}