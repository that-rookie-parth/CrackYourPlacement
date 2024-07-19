#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = abs(nums[i]);
            int idx = num-1;
            if(nums[idx]<0){
                result.push_back(num);
            }
            else{
                nums[idx] = nums[idx]*-1;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1}, ans;

    Solution obj;
    ans = obj.findDuplicates(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << endl;

    return 0;
}

// TC:O(n)
// SC: O(1)