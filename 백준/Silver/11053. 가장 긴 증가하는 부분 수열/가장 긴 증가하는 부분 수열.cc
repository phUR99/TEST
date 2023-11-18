#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[1005];
//d[i] : i번째의 부분 수열 중에서 가장 길이가 긴 값.
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];       
        d[i] = 1;
    }
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j])
            {
                d[i] = max(d[i], d[j] + 1);
            }

        }
    }
    cout << *max_element(d, d + n);
}