#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> slice(const vector<int> &v, int a, int b){
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int> &preorder, const vector<int> &inorder){
    
    const int N = preorder.size();

    if(preorder.empty()) return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - 1 - L;
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
    printPostOrder(slice(preorder,L+1, N), slice(inorder, L+1, N));
    cout << root << ' ';
}
int T;

int main(){
    fastio;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> preorder(n, -1), inorder(n, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> preorder[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> inorder[i];
        }
        printPostOrder(preorder, inorder);
        cout << '\n';
    }
    

    return 0;
}