#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node {
    vector<int> son;
    int level = -1;
};
node* t;
int maxH = 0;

void setLevel(int index, int h) {
    t[index].level = h;
    maxH = maxH > h ? maxH: h;
    for (int i = 0; i < t[index].son.size(); i ++) {
        setLevel(t[index].son[i], h + 1);
    }
}

int main()
{
    int n, m, root;
    double p, r;
    cin >> n >> p >> r;
    t = new node[n];
    for (int i = 0; i < n; i ++) {
        cin >> m;
        if (m != -1) {
            t[m].son.push_back(i);
        } else {
            root = i;
        }
    }
    setLevel(root, 0);
    int count = 0;
    double price = p * pow((1 + r / 100), maxH);
    for (int i = 0; i < n; i ++) {
        if (t[i].level == maxH) {
            count += 1;
        }
    }
    printf("%.2f %d\n", price, count);
    
    return 0;
}