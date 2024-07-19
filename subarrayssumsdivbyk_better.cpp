#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), result=0;

        // to find the sum we will use the numsulative sum vector, instead of the nums vector provided, this will save the TC from being O(n^3) to O(n^2)
        for (int i = 1; i < n; i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int n = (i==0)?nums[j]:nums[j]-nums[i-1];
                if(n%k==0){
                    result++;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5, ans;

    Solution obj;
    ans = obj.subarraysDivByK(nums, k); 

    cout << ans << endl;

    return 0;
}

// TC: O(n^2)
// SC: O(1)

// this is better than the Brute force which is O(n^3) because in that when we will do the sum that will also be O(N)