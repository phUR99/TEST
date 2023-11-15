#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<int> s;
        while (n--)
        {
            char c;
            int l;
            cin >> c;
            if (c == 'I')
            {
                cin >> l;
                s.insert(l);
            }
            else
            {
                cin >> l;
                //주의점 1: 비었을 때 erase를 실행하려고 하면 RE가 뜬다. empty일 경우의 예외처리가 필요
                if (s.empty()) continue;
                //주의점 2: s.end()는 마지막 원소의 한칸 더를 가리키는 것을 주의한다. 최댓값을 가져오고 싶으면 prev(s.end())의 형태로 봐야한다.
                //주의점 3: iterator가 아니라 iterator가 가리키는 값을 erase로 주었을 경우 mulitset에서 해당하는 값이 전부 삭제될 수 있다.
                if (l == 1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            }

        }
        if (s.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
}
