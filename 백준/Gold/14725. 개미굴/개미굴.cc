#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

class node
{
public:
    string id;
    vector<node *> children;

    node(string __id)
    {
        id = __id;
    }
    node *find(const string &obj)
    {
        for (auto &child : children)
        {
            if (child->id == obj)
                return child;
        }
        return nullptr;
    }
};
list<node> adj;

node *dfs(node *cur, string &tmp)
{
    node *exist = cur->find(tmp);
    if (exist)
        return exist;
    adj.emplace_back(node(tmp));
    cur->children.push_back(&adj.back());
    return &adj.back();
}

void make()
{
    int t;
    cin >> t;
    node *root = &adj.front();
    while (t--)
    {
        string str;
        cin >> str;
        root = dfs(root, str);
    }
}
void printAll(node *cur, int depth = 0)
{
    if (cur->id != "")
    {
        cout << string((depth - 1) * 2, '-') << cur->id << '\n';
    }
    sort(cur->children.begin(), cur->children.end(), [](node *a, node *b)
         { return a->id < b->id; });
    for (auto child : cur->children)
    {
        printAll(child, depth + 1);
    }
}

int main()
{
    fastio;
    int n;
    cin >> n;
    adj.emplace_back(node(""));
    for (int i = 0; i < n; i++)
    {
        make();
    }
    printAll(&adj.front());
    return 0;
}