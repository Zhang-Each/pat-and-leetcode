#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<long int> c;
    int n;
    long long num;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        c.push_back(num);
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        c.push_back(num);
    }
    sort(c.begin(), c.end());
    if (c.size() % 2 == 1) {
        cout << c[c.size() / 2] << endl;
    } else {
        cout << c[c.size() / 2 - 1] << endl;
    }
    return 0;
}