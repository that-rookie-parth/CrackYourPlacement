#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }        
        return nums;
    }
};

int main(){
    vector<int> nums = {0,1,0,3,12};
    vector<int> ans;

    Solution obj;
    ans = obj.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << endl;

    return 0;
}

// TC: O(n)
// SC: O(1)