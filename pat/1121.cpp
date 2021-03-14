#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int i, j, n, m;
    cin >> n;
    string *a = new string[n], *b = new string[n];
    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> m;
    string temp;
    set<string> s;
    for (i = 0; i < m; i++) {
        cin >> temp;
        s.insert(temp);
    }
    for (i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end() && s.find(b[i]) != s.end()) {
            s.erase(a[i]);
            s.erase(b[i]);
        }
    }
    if (s.empty()) {
        cout << "0" << endl;
        return 0;
    }
    else if (s.size() == 1) {
        cout << "1" << endl;
        cout << (*s.begin()) << endl;
        return 0;
    }
    set<string>::iterator it;
    cout << s.size() << endl;
    for (it = s.begin(); it != s.end(); it++) {
        if (it == s.begin())
            cout << (*it);
        else
            cout << " " << (*it);
    }
    cout << endl;
    return 0;
}