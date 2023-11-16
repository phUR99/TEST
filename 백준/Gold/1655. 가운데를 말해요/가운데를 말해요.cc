#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    //가장 큰 원소를 pop
    priority_queue<int> Mh;
    //가장 작은 원소를 pop
    priority_queue<int, vector<int>, greater<>> mh;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (Mh.size() <= mh.size())
        {
            Mh.push(x);
        }
        else
        {
            mh.push(x);
        }
        //원소들의 큰 쪽의 절반은 mh, 작은 쪽의 절반은 Mh
        if (!mh.empty() && mh.top() < Mh.top()) {
            mh.push(Mh.top());
            Mh.pop();
            Mh.push(mh.top());
            mh.pop();
        }
        //작은쪽에서 가장 큰 값을 계속해서 반환해주면 된다.
        cout << Mh.top() << '\n';
    }
}