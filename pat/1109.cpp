#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct p {
    string name;
    int h;
    p(string x, int y) {
        name = x;
        h = y;
    }
};

bool cmp(p &a, p &b) {
    if (a.h > b.h) {
        return true;
    } else if (a.h == b.h && a.name < b.name) {
        return true;
    }
    return false;
}

vector<p> res;

void println(int begin, int end) {
    int len = end - begin + 1;
    string *a = new string[len];
    int mid = len / 2;
    int left = mid - 1, right = mid + 1, count = 0;
    a[mid] = res[begin].name;
    for (int i = begin + 1; i <= end; i ++) {
        if (count % 2 == 1 && right < len) {
            a[right++] = res[i].name;
        } else if (left >= 0){
            a[left--] = res[i].name;
        }
        count += 1;
    }
    for (int i = 0; i < len; i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int n, k, h;
    cin >> n >> k;
    string name;
    for (int i = 0; i < n; i ++) {
        cin >> name >> h;
        p temp(name, h);
        res.push_back(temp);
    }
    sort(res.begin(), res.end(), cmp);
    int num = n / k;
    int last_num = n - num * (k - 1);
    println(0, last_num - 1);
    for (int i = 0; i < k - 1; i ++) {
        println(last_num + i * num, last_num + (i + 1) * num - 1);
    }
    return 0;
}
