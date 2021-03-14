#include <iostream>
#include <string>
using namespace std;

struct student {
    string name, id;
    int grade;
};


int main()
{
    student man, woman;
    man.grade = 101;
    woman.grade = -1;
    int n, g;
    string a, b, c;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a >> b >> c >> g;
        if (b == "M" && g < man.grade) {
            man.name = a;
            man.id = c;
            man.grade = g;
        } else if (b == "F" && g > woman.grade) {
            woman.grade = g;
            woman.name = a;
            woman.id = c;
        }
    }
    int flag = 1;
    if (woman.grade == -1) {
        cout << "Absent" << endl;
        flag = 0;
    } else {
        cout << woman.name << " " << woman.id << endl;
    }
    if (man.grade == 101) {
        cout << "Absent" << endl;
        flag = 0;
    } else {
        cout << man.name << " " << man.id << endl;
    }
    if (flag) {
        cout << woman.grade - man.grade << endl;
    } else {
        cout << "NA" << endl;
    }
    return 0;
}