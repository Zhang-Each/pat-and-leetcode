#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int x);
int main()
{
    int a, b;
    while (cin >> a) {
        if (a < 0)
            break;
        else
            cin >> b;
        if (isPrime(a) == 0) {
            cout << "No\n";
            continue;
        }
        long int reverse = 0;
        while (a != 0) {
            reverse = b * reverse + (a % b);
            a = a / b;
        }
        //cout<<reverse<<endl;
        if (isPrime(reverse) == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

int isPrime(int x)
{
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