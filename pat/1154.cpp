#include <iostream>
#include <set>
using namespace std;

#define MAX 10001

int a[MAX] = {0}, b[MAX] = {0};
int n, m, k;

bool color(int node[]) {
    set<int> s;
    for (int i = 0; i < m; i ++) {
        if (node[a[i]] == node[b[i]]) {
            return false;
        }
    }
    return true;
}

int main()
{
    
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    for (int i = 0; i < k; i ++) {
        int *a = new int[n];
        set<int> s;
        for (int j = 0; j < n; j ++) {
            cin >> a[j];
            s.insert(a[j]);
        }
        if (!color(a)) {
            cout << "No" << endl;
        } else {
            cout << s.size() << "-" << "coloring" << endl;
        }
    }
    return 0;
}