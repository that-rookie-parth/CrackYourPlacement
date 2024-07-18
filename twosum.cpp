#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            int x = target - nums[i];
            if(mp.count(x)){
                return {i, mp[x]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2,7,11,15}, ans;
    int target = 9;

    Solution obj;
    ans = obj.twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << endl;

    return 0;
}

// TC: O(N)
// SC: O(N)