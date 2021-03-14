#include <iostream>
#include <string>
using namespace std;

string m[8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int get(char x) {
    if (x >= '0' && x <= '9') {
        return x - '0';
    }
    return x - 'A' + 10;
}

bool is_character(char x) {
    if (x >= 'A' && x <= 'Z' || (x >= 'a' && x <= 'z')) {
        return true;
    }
    return false;
}

int main()
{
    string a, b, c, d;
    int count = 0;
    char same[2];
    cin >> a >> b >> c >> d;
    for (int i = 0; i < a.size() && count < 2; i ++) {
        if (a[i] == b[i]) {
            if (count == 0 && (a[i] >= 'A' && a[i] <= 'G')) {
                same[count] = a[i];
                count += 1;
            } else if (count == 1 && ((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9'))) {
                same[count] = a[i];
                count += 1;
            }
        }
    }
    printf("%s %02d:", m[same[0] - 'A'].c_str(), get(same[1]));
    for (int i = 0; ; i ++) {
        if (c[i] == d[i] && is_character(c[i])) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}