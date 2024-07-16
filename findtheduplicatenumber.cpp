// to follow the contratint of constant space and linear time without modifying the array we use the Hare and Tortoise Approach
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // to detect a cycle we do slow==fast, but we can't do that in the starting itself
        slow = nums[slow];          // single move
        fast = nums[nums[fast]];    // double move

        // to detect cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        // once the cycle is detected
        slow = nums[0];
        while(slow!=fast){
            slow=nums[slow];    // single move
            fast=nums[fast];    // single move
        }

        return slow;
    }
};

int main(){

    vector<int> nums = {1,3,4,2,2};
    
    Solution obj;
    int ans = obj.findDuplicate(nums);

    cout << ans << endl;

    return 0;
}

// TC: O(n)
// SC: O(1)