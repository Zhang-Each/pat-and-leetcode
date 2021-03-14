#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    double *a = new double[n];
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    long double sum = 0.0;
    for (int i = 0; i < n ; i ++ ) {
        sum += a[i] * (i + 1) * (n - i);
    }
    printf("%.2Lf", sum);
    return 0;
}