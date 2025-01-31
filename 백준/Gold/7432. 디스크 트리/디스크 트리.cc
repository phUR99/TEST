#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

struct node
{
    string id;
    vector<node *> child;

    node(string _id) { id = _id; }

    node *findChild(const string &child_id)
    {
        for (auto c : child)
        {
            if (c->id == child_id)
                return c;
        }
        return nullptr;
    }
};

list<node> adj;

node *dfs(node *cur, string &tmp)
{
    node *existingChild = cur->findChild(tmp);
    if (existingChild)
        return existingChild;

    adj.emplace_back(tmp);
    cur->child.push_back(&adj.back());
    return &adj.back();
}

void make(string &str)
{
    int pos, cur = 0;
    node *root = &adj.front();

    while ((pos = str.find('\\', cur)) != string::npos)
    {
        string tmp = str.substr(cur, pos - cur);
        cur = pos + 1;
        root = dfs(root, tmp);
    }
}

void printTree(node *cur, int depth = 0)
{
    if (cur->id != "")
    {
        cout << string(depth - 1, ' ') << cur->id << "\n";
    }
    sort(cur->child.begin(), cur->child.end(), [](node *a, node *b)
         { return a->id < b->id; });
    for (auto c : cur->child)
    {
        printTree(c, depth + 1);
    }
}

int main()
{
    fastio;
    int n;
    cin >> n;

    adj.emplace_back("");

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        str += '\\';
        make(str);
    }

    printTree(&adj.front());

    return 0;
}
