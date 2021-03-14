// 这么写只能得17分，要满分必须要用树状数组的数据结构，但我不会
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int i, n;
    cin >> n;
    int stack[100001];
    int len = 0;
    for (i = 0; i < n; i++) {
        string op;
        cin >> op;
        //cout<<op<<endl;
        if (op[1] == 'o') {
            if (len <= 0) {
                cout << "Invalid" << endl;
            }
            else {
                cout << stack[len - 1] << endl;
                len--;
            }
        }

        else if (op[1] == 'u') {
            int a;
            cin >> a;
            stack[len++] = a;
        } else {
            if (len <= 0) {
                cout << "Invalid" << endl;
                continue;
            }
            vector<int> sortlist(stack, stack + len);
            sort(sortlist.begin(), sortlist.end());
            if (len % 2 == 0) {
                cout << sortlist[len / 2 - 1] << endl;
            } else {
                cout << sortlist[(len - 1) / 2] << endl;
            }
        }
    }
    return 0;
}