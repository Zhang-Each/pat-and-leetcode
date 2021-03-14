#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node {
    vector<int> son;
    int level = -1;
    int parent = -1;
};
node* t;
int minH = 1000000;

void setLevel(int index, int h) {
    t[index].level = h;
    if (t[index].son.size() == 0) {
        minH = minH > h? h: minH;
        return;
    }
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
        for (int j = 0; j < m; j ++) {
            cin >> s;
            t[i].son.push_back(s);
            t[s].parent = i;
        }
    }
    int root;
    for (int i = 0; i < n; i ++) {
        if (t[i].parent == -1) {
            root = i;
            break;
        }
    }
    setLevel(root, 0);
    int count = 0;
    long double price = p * pow((1 + r / 100), minH);
    for (int i = 0; i < n; i ++) {
        if (t[i].level == minH && t[i].son.size() == 0) {
            count += 1;
        }
    }
    printf("%.4Lf %d", price, count);
    return 0;
}