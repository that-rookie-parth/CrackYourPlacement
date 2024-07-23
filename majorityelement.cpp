#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate=nums[0];
        int count=1;
        
        for (int i = 1; i < n; i++)
        {
            if(nums[i]==candidate){
                count++;
            }
            else{
                if(count==0){
                    candidate=nums[i];
                }
                else{
                    count--;
                }
            }
        }
        return candidate;
    }
};

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans;

    Solution obj;
    ans = obj.majorityElement(nums); 

    cout << ans << endl;

    return 0;
}

// TC: O(N)
// SC: O(1)