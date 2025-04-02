#include<iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    for(int i =0; i < 32; i++){
        if(n &(1<<i)) cout << i << ' ';
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}