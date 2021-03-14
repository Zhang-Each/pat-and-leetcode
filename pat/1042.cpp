#include <iostream>
#include <string>
using namespace std;

int a[21][55] = {0};
int shuff[55];

string change(int x) {
    int y = (x - 1) / 13;
    x = x % 13;
    string deck[] = {"S", "H", "C", "D", "J"};
    string number[] = {"13", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
    string res = deck[y];
    res += number[x];
    return res;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= 54; i ++) {
        cin >> shuff[i];
        a[0][i] = i;
    }
    for (int i = 1; i <= k; i ++) {
        for (int j = 1; j <= 54; j ++) {
            a[i][shuff[j]] = a[i - 1][j];
        }
    }
    for (int i = 1; i <= 54; i ++) {
        if (i != 1) {
            cout << " ";
        }
        cout << change(a[k][i]);
    }
    return 0;
}