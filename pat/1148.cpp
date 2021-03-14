#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 101
int n, say[MAX] = {0};

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> say[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            // 这里假设i和j是狼人
            int wolf[MAX] = {0};
            wolf[i] = 1;
            wolf[j] = 1;
            int count1 = 0, count2 = 0;
            for (int k = 1; k <= n; k ++) {
                if ((say[k] < 0 && wolf[-say[k]] == 0) || (say[k] > 0 && wolf[say[k]] == 1)) {
                    count1 ++;
                    if (k == i || k == j) {
                        count2 ++;
                    }
                }
            }
            if (count1 == 2 && count2 == 1) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}