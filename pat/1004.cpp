#include <iostream>
#include <vector>
using namespace std;

struct node {
    int level = -1;
    vector<int> children;
    bool isNode = false;
};
node* t = new node[100];
int maxH = 0;

void setLevel(node &r, int h)
{
    r.level = h;
    maxH = max(maxH, h);
    for (int i = 0; i < r.children.size(); i ++) {
        setLevel(t[r.children[i]], h + 1);
    }
} 

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++) {
        int id, num, son;
        cin >> id >> num;
        t[id].isNode = true;
        for (int j = 0; j < num; j ++) {
            cin >> son;
            t[id].children.push_back(son);
            t[son].isNode = true;
        }
    }
    setLevel(t[1], 1);
    int l = 1;
    while (l <= maxH) {
        int count = 0;
        for (int i = 1; i < 100; i ++) {
            if (t[i].level == l && t[i].children.size() == 0) {
                count ++;
            }
        }
        if (l != 1) {
            cout << " ";
        }
        cout << count;
        l++;
    }

    return 0;
}