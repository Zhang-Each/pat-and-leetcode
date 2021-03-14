#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int add, next;
    char val;
    Node (int x, int y, char z) {
        add = x;
        next = y;
        val = z;
    }
    Node() {}
};

map<int, Node> list;

int main()
{
    int head1, head2, n, x, y;
    char z;
    cin >> head1 >> head2 >> n;
    for (int i = 0; i < n; i ++) {
        scanf("%d %c %d", &x, &z, &y);
        Node temp(x, y, z);
        list[x] = temp;
    }
    vector<Node> list1, list2;
    while (head1 != -1) {
        list1.push_back(list[head1]);
        head1 = list[head1].next;
    }
    while (head2 != -1) {
        list2.push_back(list[head2]);
        head2 = list[head2].next;
    }
    int res = -1;
    for (int i = list1.size() - 1, j = list2.size() - 1; i >= 0 && j >= 0; i--, j--) {
        if (list1[i].val == list2[j].val && list1[i].add == list2[j].add) {
            res = list1[i].add;
        } else {
            break;
        }
    }
    if (res != -1) {
        printf("%05d\n", res);
    } else {
        printf("-1\n");
    }
    return 0;
}