#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), count=0, sum=0;
        unordered_map<int, int> mp;

        // edge case: in the starting the cummulative sum is 0 only
        mp[0]=1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int check = sum - k;
            if(mp.find(check)!=mp.end()){
                // important to remember that we will add the count not 1
                count = count + mp[check];
            }
            mp[sum]++;
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,4,1,2,6};
    int k = 3, ans;

    Solution obj;
    ans = obj.subarraySum(nums, k);

    cout << ans << endl;

    return 0;
}

// TC: O(N)
// SC: O(N)