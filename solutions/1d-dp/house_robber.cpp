// house_robber.cpp
// Time Complexity: O(n)
// Space Complexity: O(n) -> Space optimized O(1)
#include <bits/stdc++.h>
using namespace std;
int dp[101];
int house_robber_recursive(int ind, vector<int>& a){
    if(ind < 0) return 0;
    if(dp[ind] !=- 1) return dp[ind];

    return dp[ind] = max(mxrob(ind-1, a), a[ind] + mxrob(ind-2, a));
}
int house_robber_optimized(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    
    for (int i = 2; i < nums.size(); i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout<< house_robber_recursive(nums.size()-1, nums) <<endl;

    cout << house_robber_optimized(nums) << endl;
    return 0;
}