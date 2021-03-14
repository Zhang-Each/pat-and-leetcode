#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i ++) {
        vector<int> stack;
        int *a = new int[n];
        bool find = true;
        for (int j = 0; j < n; j ++) {
            cin >> a[j];
        }
        for (int j = 1; j <= a[0]; j ++) {
            stack.push_back(j);
        }
        if (stack.size() > m) {
            cout << "NO" << endl;
            continue;
        }
        stack.pop_back();
        int count = a[0];
        for (int j = 1; j < n; j ++) {
            if (a[j] == stack[stack.size() - 1]) {
                stack.pop_back();
            } else {
                if (a[j] <= count) {
                    find = false;
                    break;
                }
                for (int l = count + 1; l <= a[j]; l ++) {
                    stack.push_back(l);
                    if (stack.size() > m) {
                        find = false;
                        break;
                    }
                }
                count = a[j];
                stack.pop_back();
            }
        }
        if (find) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}