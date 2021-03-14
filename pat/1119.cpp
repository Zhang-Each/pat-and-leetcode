#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post, in;
bool single = true;

void find(int pre1, int pre2, int post1, int post2) {
    if (pre1 > pre2) {
        return ;
    } else if (pre1 == pre2) {
        in.push_back(pre[pre1]);
        return;
    }
    if (pre[pre1] == post[post2]) {
        int i;
        for (i = pre1 + 1; i <= pre2; i ++) {
            if (pre[i] == post[post2 - 1]) {
                break;
            }
        }
        if (i - pre1 > 1) {
            find(pre1 + 1, i - 1, post1, post1 + i - pre1 - 2);
        } else {
            single = false;
        }
        in.push_back(post[post2]);
        find(i, pre2, post1 + i - pre1 - 1, post2 - 1);
    }
}

int main()
{
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        pre.push_back(num);
    }
    for (int i = 0; i < n; i ++) {
        cin >> num;
        post.push_back(num);
    }
    find(0, n - 1, 0, n - 1);
    if (single) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = 0; i < in.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << in[i];
    }
    cout << endl;
    return 0;
}