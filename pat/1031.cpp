#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    int n = s.size(), n1, n2;
    if ((n + 2) % 3 == 0) {
        n2 = (n + 2) / 3;
    } else {
        n2 = (n + 2) / 3 + 1;
    }
    if ((n - n2) % 2 == 1 ) {
            n2 += 1;
        }
    n1 = (n - n2) / 2;
    for (int i = 0; i < n1; i ++) {
        cout << s[i];
        for (int j = 0; j < n2 - 2; j ++) {
            cout << ' ';
        }
        cout << s[n - 1 - i] << endl;
    }
    for (int i = n1; i < n2 + n1; i ++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}