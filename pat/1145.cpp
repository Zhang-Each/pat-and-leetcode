#include <iostream>
#include <vector>
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

vector<int> lost;

int main() 
{
    int size, n, m, num;
    cin >> size >> n >> m;
    while (!prime(size)) {
        size += 1;
    }
    int *a = new int[size];
    for (int i = 0; i < size; i ++) {
        a[i] = -1;
    }
    for (int i = 0; i < n; i ++) {
        cin >> num;
        bool find = false;
        for (int j = 0; j < size; j ++) {
            if (a[(num + j * j) % size] == -1) {
                a[(num + j * j) % size] = num;
                find = true;
                break;
            }
        }
        if (find == false) {
            lost.push_back(num);
        }
    }
    int total = 0;
    for (int i = 0; i < m; i ++) {
        cin >> num;
        for (int j = 0; j <= size; j ++) {
            total += 1;
            if (a[(num + j * j) % size] == num || a[(num + j * j) % size] == -1) {
                break;
            }
        }
    }
    for (int i = 0; i < lost.size(); i ++) {
        printf("%d cannot be inserted.\n", lost[i]);
    }
    printf("%.1f\n", 1.0 * total / m);
}