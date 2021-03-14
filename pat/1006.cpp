#include <iostream>
#include <string>
using namespace std;

struct student {
    string id;
    int in, out;
};

int change (string s);

int main () 
{
    int n;
    cin >> n;
    student *s = new student[n];
    for (int i = 0; i < n; i++) {
        string id, in, out;
        cin >> id >> in >> out;
        s[i].id = id;
        s[i].in = change(in);
        s[i].out = change(out);
    }
    int maxi = 0, mini = 0, maxtime = s[0].out, mintime = s[0].in;
    for (int i = 0; i < n; i ++ ) {
        if (s[i].out > maxtime) {
            maxtime = s[i].out;
            maxi = i;
        }
        if (s[i].in < mintime) {
            mintime = s[i].in;
            mini = i;
        }
    }
    cout << s[mini].id << " " << s[maxi].id << endl;
    return 0;
}

int change (string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] != ':') {
            res = res * 10 + s[i] - '0';
        }
    }
    return res;
}