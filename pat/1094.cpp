#include <iostream>
#include <vector>
using namespace std;

struct node {
    int parent = -1;
    int level = -1;
    vector<int> son;
};

node * family;

void setLevel(int index, int level) {
    family[index].level = level;
    for (int i = 0; i < family[index].son.size(); i ++) {
        setLevel(family[index].son[i], level + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    family = new node[n + 1];
    int a[100] = {0};
    for (int i = 0; i < m; i ++) {
        int id, num, son;
        cin >> id >> num;
        for (int j = 0; j < num; j ++) {
            cin >> son;
            family[id].son.push_back(son);
            family[son].parent = id;
        }
    }
    int root = 0;
    for (int i = 1; i <= n; i ++) {
        if (family[i].parent == -1) {
            root = i;
        }
    }
    setLevel(root, 1);
    for (int i = 1; i <= n; i ++) {
        a[family[i].level] += 1;
    }
    int maxNum = 0, maxGene = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > maxNum) {
            maxNum = a[i];
            maxGene = i;
        }
    } 
    cout << maxNum << " " << maxGene << endl;
    return 0;
}