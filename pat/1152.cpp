#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool isPrime(int x) 
{
    for (int i = 2; i <= sqrt(x); i ++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n - k; i ++) {
        int num = atoi(s.substr(i, k).c_str());
        if (isPrime(num)) {
            cout << s.substr(i, k) << endl;
            return 0;
        }
    }
    cout << 404 << endl;
    return 0;
}