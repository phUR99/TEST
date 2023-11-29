 #include <bits/stdc++.h>

using namespace std;
#define ll long long

bool ans[2'000'005];
int arr[25];

int n;

void func(int pos, int sum) {
    if (pos == n) {
        ans[sum] = true;
        return;
    }    
    func(pos + 1, sum + arr[pos]);    
    func(pos + 1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(0, 0);
    for (int i = 1; i < 200'000'1; i++)
    {
        if (!ans[i]) {
            cout << i;
            return 0;
        }
    }

}