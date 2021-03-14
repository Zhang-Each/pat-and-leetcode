#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool prime(int x) {
    if (x <= 1) {
        return false;
    } else if (x == 2) {
        return true;
    }
    for (int i = 2; i <= x / 2; i ++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int size, n, m, num;
    cin >> size >> n;
    while (!prime(size)) {
        size += 1;
    }
    map<int, int> hash;
    vector<int> res;
    int *a = new int[size];
    for (int i = 0; i < size; i ++) {
        a[i] = -1;
    }
    for (int i = 0; i < n; i ++) {
        cin >> num;
        res.push_back(num);
        int find = 0;
        for (int j = 0; j < size; j ++) {
            if (a[(num + j * j) % size] == -1) {
                a[(num + j * j) % size] = num;
                hash[num] = (num + j * j) % size;
                find = 1;
                break;
            }
        }
        if (!find) {
            hash[num] = -1;
        }
    }
    for (int i = 0; i < res.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        if (hash[res[i]] != -1) {
            cout << hash[res[i]];
        } else {
            cout << '-';
        }
    }
    return 0;
}