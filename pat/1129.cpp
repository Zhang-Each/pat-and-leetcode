#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct record {
    int id;
    int count;
    record(int _id, int _count) {
        id = _id;
        count = _count;
    }
    bool operator < (const record & a) const {
        return count != a.count ? count > a.count : id < a.id;
    }
};

int num[50001] = {0};

int main()
{
    int n, k, id;
    cin >> n >> k;
    set<record> rec;
    for (int i = 0; i < n; i ++) {
        cin >> id;
        if (i >= 1) {
            cout << id << ":";
            int number = 0;
            set<record>::iterator it = rec.begin();
            while (number < k && it != rec.end()) {
                cout << " " << it->id;
                it ++;
                number ++;
            }
            cout << endl;
        }
        set<record>::iterator it = rec.find(record(id, num[id]));
        if (it != rec.end()) {
            rec.erase(it);
        }
        num[id] ++;
        rec.insert(record(id, num[id]));
    }
}