#include <iostream>
#include <vector>
using namespace std;

bool isMax = true, isMin = true;

int *heap;
int n;
vector<int> path;

void show() {
    for (int i = 0; i < path.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << path[i];
    }
    cout << endl;
}

void travel(int index) {
    if (index >= n) {
        return;
    }
    if (2 * index + 1 >= n) {
        path.push_back(heap[index]);
        show();
        path.pop_back();
    } else {
        path.push_back(heap[index]);
        if (2 * index + 2 < n) {
            travel(2 * index + 2);
            travel(2 * index + 1);
            if (heap[2 * index + 1] < heap[index] || heap[2 * index + 2] < heap[index]) {
                isMin = false;
            }
            if (heap[2 * index + 1] > heap[index] || heap[2 * index + 2] > heap[index]) {
                isMax = false;
            }
        } else if (2 *index + 2 == n) {
            travel(2 * index + 1);
            if (heap[2 * index + 1] < heap[index]) {
                isMin = false;
            }
            if (heap[2 * index + 1] > heap[index]) {
                isMax = false;
            }
        }
        path.pop_back();
    }

}

int main()
{
    cin >> n;
    heap = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> heap[i];
    }
    travel(0);
    if (!isMax && !isMin) {
        cout << "Not Heap" << endl;
    } else if (isMax) {
        cout << "Max Heap" << endl;
    } else if (isMin){
        cout << "Min Heap" << endl;
    }
    return 0;
}