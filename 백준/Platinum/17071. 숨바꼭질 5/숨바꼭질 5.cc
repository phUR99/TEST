#include <bits/stdc++.h>
using namespace std;
// 모든 방문했던 자리는 2초 후에 재방문 가능하다.
// 짝수 시간일 때 방문 가능한 배열과 홀수 시간일 때 방문 가능한 배열을 나누어서 방문
const int LMT = 500'000;

int vis[2][LMT + 2];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int bro, sis, ans = 0;
  queue<pair<int, int>> Q;
  cin >> sis >> bro;
  Q.push({sis, 0});
  for (int i = 0; i < 2; i++)
    fill(vis[i], vis[i] + LMT + 2, -1);
  vis[0][sis] = 0;
  while (!Q.empty()) {
    int v, vt, nvt;
    tie(v, vt) = Q.front();
    nvt = vt + 1;
    Q.pop();
    for (int nv : {2 * v, v + 1, v - 1}) {
      if (nv < 0 || LMT < nv) continue;
      if (vis[nvt % 2][nv] != -1) continue;
      vis[nvt % 2][nv] = nvt;
      Q.push({nv, nvt});
    }
  }
  bool found = false;
  while (bro <= LMT) {
    if (vis[ans % 2][bro] <= ans) {
      found = true;
      break;
    }
    bro += ++ans;
  }
  if (found) cout << ans;
  else
    cout << -1;
}
