#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
stack<int> idx;
string str;
int arr[205];
int counter = 0;
int n;
string solve(int state){
    string ret;
    for (int i = 0; i < n; i++)
    {
        ret += str[i];
        if(arr[i] >= 0 && (state & (1<<arr[i]))){
            ret.pop_back();
        }
    }
    return ret;    
}

int main()
{
    fastio;
    memset(arr, -1, sizeof(arr));
    cin >> str;
    n = str.size();
    for (int i = 0; i < n; i++)
    {
        if(str[i] == '('){
            arr[i] = counter++;
            idx.push(i);
        }
        else if(str[i] == ')'){
            int bef = idx.top(); idx.pop();
            arr[i] = arr[bef];
        }
    }
    int full_bit = (1<<counter) - 1;
    vector<string> ret;
    for (int state = full_bit; state; state--)
    {
        ret.push_back(solve(state));
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for (auto &i : ret)
    {
        cout << i << '\n';
    }
    
    
    return 0;
}