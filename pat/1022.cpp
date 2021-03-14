#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
using namespace std;

map<string, set<int>> title, author, key, pub, year;

void show(string word, map<string, set<int>> &m) {
    if (m[word].size() == 0) {
        cout << "Not Found" << endl;
    } else {
        set<int>::iterator it = m[word].begin();
        while (it != m[word].end()) {
            printf("%07d\n", *it);
            it ++;
        }
    }
}

int main()
{
    int n, m, id;
    cin >> n;
    string a, b, c, d, e;
    int i;
    for (i = 0; i < n; i ++) {
        scanf("%d%*c", &id);
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);
        getline(cin, d);
        getline(cin, e);
        title[a].insert(id);
        author[b].insert(id);
        istringstream iss(c);
        string temp;
        while (getline(iss, temp, ' ')) {
            key[temp].insert(id);
        }
        pub[d].insert(id);
        year[e].insert(id);
    }
    cin >> m;
    int type;
    string input;
    for (int i = 0; i < m; i ++) {
        scanf("%d: ", &type);
        getline(cin, input);
        cout << type << ": " << input << endl;
        if (type == 1) {
            show(input, title);
        } else if (type == 2) {
            show(input, author);
        } else if (type == 3) {
            show(input, key);
        } else if (type == 4) {
            show(input, pub);
        } else {
            show(input, year);
        }
    }
    return 0;
}