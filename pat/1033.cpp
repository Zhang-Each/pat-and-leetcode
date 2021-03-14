// 这题太难了，但是ads之前做过，所以直接复制了代码
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    double c, dist, per;
    int i, j, n;
    map<double, double> s;
    cin >> c >> dist >> per >> n;
    s[0] = 0;
    for (i = 0; i < n; i++) {
        double p, d;
        cin >> p >> d;
        if ((s[d] > 0 && p < s[d]) || (s[d] == 0))
            s[d] = p;
    }
    s[dist] = 0;
    map<double, double>::iterator it = s.begin();

    map<int, double> list;
    int count = 0;
    for (it = s.begin(); it != s.end(); it++) {
        list[count] = it->first;
        count++;
    }
    if (s[0] == 0)
        cout << "The maximum travel distance = 0.00" << endl;
    else {
        n = s.size();
        int now = 0;
        double cost = 0;
        double tank = 0;
        double range = c * per;
        while (now < n) {
            int k = -9999;
            double min = 9999999;
            for (i = now + 1; i <= n && list[i] - list[now] <= range; i++) {
                if (s[list[i]] < min) {
                    min = s[list[i]];
                    k = i;
                    if (min < s[list[now]])
                        break;
                }
            }
            double gas = (list[k] - list[now]) / per;
            if (k <= 0)
                break;
            if (min < s[list[now]]) {
                if (tank < gas) {
                    cost += (gas - tank) * s[list[now]];
                    tank = 0;
                }
                else
                    tank -= gas;
            }
            else {
                cost += (c - tank) * s[list[now]];
                tank = c - gas;
            }
            now = k;
        }
        if (now != n)
            printf("The maximum travel distance = %.2f", list[now] + range);
        else
            printf("%.2f", cost);
    }
    return 0;
}