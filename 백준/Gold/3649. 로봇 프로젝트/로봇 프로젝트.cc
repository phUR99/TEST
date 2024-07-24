#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
int hole;
int arr[1000005];
const int nanoPerCenti = 10'000'000;

int main(){
    fastio;
        
    while(cin >> hole)
    {
        cin >> N;
        hole *= nanoPerCenti;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+N);
        int ans = -1;
        int l1, l2;

        for (int i = 0; i < N; i++)
        {
            if(binary_search(arr+i+1, arr+N, hole - arr[i])){
                l1 = arr[i];
                l2 = hole - arr[i];  
                ans = 0;
                break;
            }                        
        }
        
        cout << (ans == -1 ?  "danger" :  "yes " + to_string(l1) + " " + to_string(l2)) << '\n';

    }    
    return 0;
}