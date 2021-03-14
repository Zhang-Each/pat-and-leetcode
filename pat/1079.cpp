#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node {
    vector<int> son;
    int level = -1;
    int parent = -1;
    int val = -1;
};
node* t;

void setLevel(int index, int h) {
    t[index].level = h;
    for (int i = 0; i < t[index].son.size(); i ++) {
        setLevel(t[index].son[i], h + 1);
    }
}

int main()
{
    int n, m, s;
    double p, r;
    cin >> n >> p >> r;
    t = new node[n];
    for (int i = 0; i < n; i ++) {
        cin >> m;
        if (m == 0) {
            cin >> s;
            t[i].val = s;
        } else {
            for (int j = 0; j < m; j ++) {
                cin >> s;
                t[i].son.push_back(s);
            }
        }  
    }
    int root = 0;
    setLevel(root, 0);
    double sum = 0;
    for (int i = 0; i < n; i ++) {
        if (t[i].son.size() == 0) {
            sum += p * pow((1 + r / 100), t[i].level) * t[i].val;
        }
    }
    printf("%.1f", sum);
    return 0;
}