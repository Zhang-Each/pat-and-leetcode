#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define MAX 10001

int tree[MAX] = {0};
vector<vector<int>> all;
set<int> bird;

int search(int x) {
    if (tree[x] == 0) {
        return x;
    } else {
        return tree[x] = search(tree[x]);
    }
}

int add(int x, int y) {
    int xx = search(x), yy = search(y);
    if (xx != yy) {
        tree[yy] = xx;
    }
    return xx;
}

int main()
{
    int n, a, b, k;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> k;
        vector<int> t(k);
        for (int j = 0; j < k; j ++) {
            cin >> t[j];
            bird.insert(t[j]);
        }
        for (int j = 1; j < k; j ++) {
            add(t[0], t[j]);
        }
        all.push_back(t);
    }
    map<int, int> r;
    int count = 0;
    for (int i = 0; i < all.size(); i ++) {
        int root = search(all[i][0]);
        if (r[root] == 0) {
            count ++;
        }
        r[root] ++;
    }
    cout << count << " " << bird.size() << endl;
    cin >> k;
    for (int i = 0; i < k; i ++) {
        cin >> a >> b;
        if (search(a) == search(b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        } 
    }
    return 0;
}