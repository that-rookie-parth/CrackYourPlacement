#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, n=nums.size();
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == n;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    bool ans;

    Solution obj;
    ans = obj.canJump(nums);

    cout << ans << endl;

    return 0;
}