#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct rich {
    string name;
    int age;
    int w;
    rich(string x, int y, int z) {
        name = x;
        age = y;
        w = z;
    }
};

bool cmp(rich &a, rich &b) {
    if (a.w != b.w) {
        return a.w > b.w;
    }
    return a.age == b.age ? a.name < b.name: a.age < b.age;
}

vector<rich> res;

int main()
{
    int n, k, a, b;
    string s;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> s >> a >> b;
        rich temp(s, a, b);
        res.push_back(temp);
    }
    sort(res.begin(), res.end(), cmp);
    
    int amin, amax, num;
    for (int i = 1; i <= k; i ++) {
        scanf("%d %d %d", &num, &amin, &amax);
        printf("Case #%d:\n", i);
        int count = 0;
        for (int j = 0; j < res.size(); j ++) {
            if (res[j].age >= amin && res[j].age <= amax) {
                printf("%s %d %d\n", res[j].name.c_str(), res[j].age, res[j].w);
                count += 1;
            }
            if (count >= num) {
                break;
            }
        }
        if (count == 0) {
            printf("None\n");
        }
    }
    
    return 0;
}