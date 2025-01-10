#include<bits/stdc++.h>
using namespace std;
bool binary(vector<int> &nums, int target);
int main() 
{
    ios::sync_with_stdio(false); // 입출력 성능 향상
    cin.tie(nullptr);           // 입출력 버퍼 비우기 비활성화
    cout.tie(NULL);

    int count,n_Count;
    cin >> count;
    vector<int> f_Nums;

    for (int i = 0; i < count; i++)
    {
        int n;
        cin >> n;
        f_Nums.push_back(n);
    }

    sort(f_Nums.begin(), f_Nums.end());

    cin >> n_Count;
    for (int i = 0; i < n_Count; i++)
    {
        int n;
        cin >> n;
        
        if (binary(f_Nums, n)) {
            cout << 1 << '\n';
        }
        else
            cout << 0 << '\n';
    }

    

    
}

bool binary(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == nums[mid]) return true;

        if (target > nums[mid]) {
            low = mid + 1;
        }
        
        if (target < nums[mid])
            high = mid - 1;

    }

    return false;
}