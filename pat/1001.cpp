#include <iostream>
#include <string>

using namespace std;

int main () 
{
    int a, b, res, count = 0;
    cin >> a >> b;
    res = a + b;
    if (res < 0) {
        res *= -1;
        cout << "-";
    } else if (res == 0) {
        cout << "0" << endl;
        return 0;
    }
    string out = "";
    while (res > 0) {
        out += '0' + res % 10;
        res /= 10;
        count += 1;
        if (count % 3 == 0 && res != 0) {
            out += ",";
        }
    }
    for (int i = out.size() - 1; i >= 0; i -- ) {
        cout << out[i];
    }
    cout << endl;
    return 0;
}