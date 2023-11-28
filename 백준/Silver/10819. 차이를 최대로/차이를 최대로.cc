#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int n;
int ans = 0;
int arr[10];
//idea: n이 충분히 작으므로 가능한 경우를 모두 탐색할 수 있다.
//따라서 받은 배열을 순열을 이용해서 모두 찾는다.
//tip: next_permutation 함수는 오름차순으로 시작해서 내림차순으로 정렬한다. 모든 경우를 탐색하고 싶다면 초기에 배열을 오름차순으로 정렬하자.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    do
    {
        int tmp = 0;
        for (int i = 1; i < n; i++)
        {
            tmp += abs(arr[i] - arr[i - 1]);
        }
        ans = max(ans, tmp);
    } while (next_permutation(arr, arr+n));
    cout << ans;
}
