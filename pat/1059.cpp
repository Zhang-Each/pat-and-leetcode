#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
vector<int> prime;
void findPrime(int n);
int isPrime(int x);

int main()
{
    int i, n;
    map<int, int> result;
    cin >> n;
    if (n <= 1) {
        cout << n << "=" << n;
        return 0;
    }
    cout << n << "=";
    if (isPrime(n)) {
        cout << n;
        return 0;
    }
    findPrime(n);
    for (i = 0; i < prime.size(); i++) {
        while (n % prime[i] == 0) {
            n /= prime[i];
            result[prime[i]]++;
        }
    }
    map<int, int>::iterator j;
    for (j = result.begin(); j != result.end(); j++) {
        if (j != result.begin())
            cout << "*";
        cout << j->first;
        if (j->second >= 2)
            cout << "^" << j->second;
    }
    return 0;
}

int isPrime(int x) {
    if (x <= 1)
        return 0;
    else if (x == 2 || x == 3)
        return 1;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void findPrime(int n) {
    prime.push_back(2);
    int i;
    for (i = 3; i <= sqrt(n); i += 2)
    {
        if (isPrime(i) == 1)
            prime.push_back(i);
    }
}