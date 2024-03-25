#include <bits/stdc++.h>
using namespace std;

struct node
{
    int day, cost;
};
node arr[20];

int n;
//부분문제 접근??? 현재 함수의 정의는 cur ~ n까지의 최댓값..
//cache를 쓰기 위해서는 n부터 내려가는 함수의 형태로 짜야 할듯
//시간복잡도 : O(N^2)니 DP에 크게 의존하지 않았어도 상관없었을듯
int maxValue(int cur){ 
    int ret = 0;
    for (int i = cur; i < n; i++)
    {
        if(i + arr[i].day > n) continue;
        ret = max(ret, maxValue(arr[i].day + i) + arr[i].cost);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].day >> arr[i].cost;
    }
    cout << maxValue(0);

    return 0;
}