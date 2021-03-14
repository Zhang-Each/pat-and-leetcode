#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct student {
    string name;
    string id;
};
map<int, student> grade;

int main()
{
    int n, m, count = 0;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string s, t;
        int g;
        student stu;
        cin >> s >> t >> g;
        stu.name = s;
        stu.id = t;
        grade[g] = stu;
    }
    cin >> m >> n;
    map<int, student>::reverse_iterator it = grade.rbegin();
    while (it != grade.rend()) {
        if (it->first >= m && it->first <= n) {
            cout << it->second.name << " " << it->second.id << endl;
            count += 1;
        }
        it ++;
    }
    if (count == 0) {
        cout << "NONE" << endl;
    }
    return 0;
}