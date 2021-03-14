#include <iostream>
#include <map>
using namespace std;

#define MAX 10001
int a[MAX] = {0}, b[MAX] = {0};

int main()
{
    int n, m, l;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a[i] >> b[i];
    }
    cin >> l;
    for (int i = 0; i < l; i ++) {
        int len, node, found = 0;
        cin >> len;
        map<int, int> cover;
        for (int j = 0; j < len; j ++) {
            cin >> node;
            cover[node] = 1;
        }
        for (int i = 0; i < m; i ++) {
            if (!cover[a[i]] && !cover[b[i]]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}