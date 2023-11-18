#include <bits/stdc++.h>

using namespace std;
#define ll long long
string arr[1005];
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (*max_element(arr, arr + n) == "0") {
        cout << 0;
        return 0;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

}