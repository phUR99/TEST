#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct node
{
    bool isEnd;
    node* nxt[10];    
};
int idx;
node arr[100005];
string str_arr[10005];
void init(){
    idx = 1;
    for (int i = 0; i < 100005; i++)
    {
        arr[i].isEnd = false;
        fill(arr[i].nxt, arr[i].nxt+10, nullptr);
    }    
}

node* form(){
    node* ret;
    ret = &arr[idx++];
    return ret;
}
bool insert(string str){
    node* cur = &arr[0];
    for (int i = 0; i < str.size(); i++)
    {
        if(cur->isEnd) return false;
        if(cur->nxt[str[i]-'0'] == nullptr) {
            cur->nxt[str[i]-'0'] = form();            
        }
        cur = cur->nxt[str[i]-'0'];
    }
    cur->isEnd = true;    
    return true;
}

int T, N;

int main(){
    fastio;
    cin >> T;
    string str;
    for (int t = 0; t < T; t++)
    {
        init();
        cin >> N;
        string ans = "YES";
        for (int i = 0; i < N; i++)
        {
            cin >> str_arr[i];
        }
        sort(str_arr, str_arr + N);
        for (int i = 0; i < N; i++)
        {            
            if(!insert(str_arr[i])) ans = "NO";
        }
        cout << ans << '\n';
    }   
    


    return 0;
}