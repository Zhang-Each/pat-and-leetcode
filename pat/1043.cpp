#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode
{
    int val;
    Tree Left;
    Tree Right;
};

vector<int> s1, s2, post;
void Pre1(Tree T);
void Pre2(Tree T);
void showVector(vector<int> s);
void Post(Tree T, int kind);
int check(vector<int> node);
Tree Insert(int x, Tree T);

int main()
{
    Tree T = NULL;
    int a, i, n;
    vector<int> node;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        T = Insert(a, T);
        node.push_back(a);
    }
    Pre1(T);
    Pre2(T);
    if (!check(node))
    {
        cout << "NO" << endl;
    }
    else
    {
        Post(T, check(node));
        cout << "YES" << endl;
        showVector(post);
    }
    return 0;
}

void showVector(vector<int> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << s[i];
    }
    cout << endl;
}

void Pre1(Tree T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        s1.push_back(T->val);
        Pre1(T->Left);
        Pre1(T->Right);
    }
}

void Pre2(Tree T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        s2.push_back(T->val);
        Pre2(T->Right);
        Pre2(T->Left);
    }
}

Tree Insert(int x, Tree T)
{
    if (T == NULL)
    {
        T = (Tree)malloc(sizeof(struct TreeNode));
        T->val = x;
        T->Left = T->Right = NULL;
        return T;
    }
    else if (x < T->val)
    {
        T->Left = Insert(x, T->Left);
        return T;
    }
    else if (x >= T->val)
    {
        T->Right = Insert(x, T->Right);
        return T;
    }
    return NULL;
}

int check(vector<int> node)
{
    int i, dif1 = 0, dif2 = 0;
    for (i = 0; i < node.size(); i++)
    {
        if (node[i] != s1[i])
            dif1++;
        if (node[i] != s2[i])
            dif2++;
    }
    if (dif1 * dif2 != 0)
        return false;
    else if (dif1 == 0)
        return 1;
    else
        return 2;
}

void Post(Tree T, int kind)
{
    if (T == NULL)
        return;
    else
    {
        if (kind == 1)
        {
            Post(T->Left, 1);
            Post(T->Right, 1);
            post.push_back(T->val);
        }
        else
        {
            Post(T->Right, 2);
            Post(T->Left, 2);
            post.push_back(T->val);
        }
    }
}