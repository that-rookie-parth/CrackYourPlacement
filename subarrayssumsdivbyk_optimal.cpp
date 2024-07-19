#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), result=0, sum=0;

        // we will use a map to store the remainder and it's count, remember is the rem is -ve then rem = -n+k
        unordered_map<int, int> mp;
        mp[0] = 1;  // here in the start the count of rem 0 will be 1 by default and then we will start

        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            int rem = sum%k;
            if(rem<0)
                rem = rem + k;
            // check if the rem already exist in the map
            if(mp.find(rem)!=mp.end())
                result = result + mp[rem];
            mp[rem]++;
        }
        return result;
    }
};

int main(){
    vector<int> nums = {2,-6,3,1,2,8,2,1,1};
    int k = 7, ans;

    Solution obj;
    ans = obj.subarraysDivByK(nums, k); 

    cout << ans << endl;

    return 0;
}

// TC: O(n)
// SC: O(1)