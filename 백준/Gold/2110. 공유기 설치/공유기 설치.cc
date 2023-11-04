#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>

using namespace std;
#define ll long long
int cnt, n, c;
int x[200'005];
//idea : 최대 길이를 찾는 문제? 길이마다 yes or no로 변환 가능 -> 매개변수 탐색 가능
//l 마다 잘랐을 때 cnt가 c 이상이 될 수 있는 지를 체크하기
bool solve(int l) {
    int idx = 0, cnt = 0;
    while (idx != n)
    {
        idx = lower_bound(x + idx, x + n, x[idx] + l) - x;
        cnt++;
    }
    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    int st = 1; int ed = 1e9;
    while (st < ed)
    {
        int mid = (st + ed + 1) / 2;
        if (solve(mid)) st = mid;
        else ed = mid - 1;
    }
    cout << st;
}