#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //시작시간 기준으로 정렬한 뒤에, 끝나는 시간이 시작시간보다 크다면 우선순위 큐에 계속해서 넣어줌.
    //만약에 끝나는 시간이 시작시간보다 작거나 같다면 큐의 top을 제거한다.
    //이렇게 함으로써 끝나는 시간 내의 모든 경우의 수를 체크할 수 있음.
    priority_queue<int, vector<int>, greater<>> end;
    vector<pair<int, int>> sc;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        sc.push_back({ st, ed });
    }
    sort(sc.begin(), sc.end());
    end.push(sc[0].second);
    for (int i = 1; i < n; i++)
    {
        end.push(sc[i].second);
        if (sc[i].first >= end.top()) end.pop();
        
        
    }
    cout << end.size();
}
