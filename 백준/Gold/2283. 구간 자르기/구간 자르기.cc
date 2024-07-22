#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k;
int arr[1000005]; // arr[i] : arr[i]에 있는 선분의 개수

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); 
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int st, en;
    cin >> st >> en;
    for (int j = st; j < en; j++)
      arr[j]++;
  }
  int en = 0;
  int tot = arr[0];
  for(int st = 0; st < 1000000; st++){
    while(en < 1000000 && tot < k){
      en++;
      if(en != 1000000) tot += arr[en];
    }
    if(en == 1000000) break;
    if(tot == k){
      cout << st << ' ' << en + 1;
      return 0;
    }
    tot -= arr[st];
  }
  cout << 0 << ' ' << 0;
  return 0;
}
