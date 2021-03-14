#include <iostream>
#include <algorithm>

using namespace std;

struct mooncake
{
    double amount;
    double price;
    double single_price;
};

int main()
{
    int i, j, n;
    double d;
    cin >> n >> d;
    mooncake *s = new mooncake[n];
    for (i = 0; i < n; i++) {
        cin >> s[i].amount;
    }
    for (i = 0; i < n; i++) {
        cin >> s[i].price;
    }
    for (i = 0; i < n; i++) {
        s[i].single_price = s[i].price / (s[i].amount * 1.0);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].single_price <= s[j + 1].single_price) {
                mooncake t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    double result = 0;
    i = 0;
    while (d > 0 && i < n) {
        if (d >= s[i].amount) {
            d -= s[i].amount;
            result += s[i].price;
        }
        else {
            result += d * s[i].single_price;
            d = 0;
        }
        i++;
        //cout<<result<<endl;
    }
    printf("%.2f", result);
    return 0;
}