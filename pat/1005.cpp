#include <iostream>
#include <string>
#include <vector>

using namespace std;
string map[10] = {"zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"};

int main ()
{
    string s;
    int sum = 0;
    vector<string> res;
    cin >> s;
    if (s == "0") {
        cout << "zero" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i ++ ) {
        sum += s[i] - '0';
    }
    while (sum > 0) {
        res.push_back(map[sum % 10]);
        sum /= 10;
    }
    for (int i = res.size() - 1; i >= 0; i --) {
        cout << res[i];
        if (i != 0) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}