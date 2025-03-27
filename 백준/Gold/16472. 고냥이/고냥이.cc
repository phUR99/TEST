#include <iostream>

using namespace std;
string str;
int cnt[26];
int total(){
    int ret = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i])
            ret++;
        
    }
    return ret;
}
int main(){
    int n;
    cin >> n;
    cin >> str;
    int l =0; int r = 0;
    int s = str.size();
    int ret = 0;
    while (r < s)
    {
        cnt[str[r++]-'a']++;
        while (total() > n)
        {
            cnt[str[l++]-'a']--;
        }
        ret = max(ret, r-l);
    }
    cout << ret;
    return 0;
}