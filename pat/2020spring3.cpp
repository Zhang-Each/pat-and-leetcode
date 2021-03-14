#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX 501

vector<int> a, b;

int main()
{
    int m, n, r, k, x, y;
    cin >> n >> r >> k;
    for (int i = 0; i < r; i ++) {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    cin >> m;
    for (int i = 0; i < m; i ++) {
        set<int> s;
        int *ani = new int [n + 1];
        for (int j = 1; j <= n; j ++) {
            cin >> ani[j];
            s.insert(ani[j]);
        }
        if (s.size() > k) {
            cout << "Error: Too many species." << endl;
            continue;
        } else if (s.size() < k) {
            cout << "Error: Too few species." << endl;
            continue;
        }
        bool find = 1;
        for (int j = 0; j < r; j ++) {
            cout << ani[a[j]] << " "<< ani[b[j]] << endl;
            if (ani[a[j]] == ani[b[j]]) {
                find = 0;
                break;
            }
        }
        if (find == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}