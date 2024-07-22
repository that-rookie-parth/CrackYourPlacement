#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,1,1};
    int k = 2, ans;

    Solution obj;
    ans = obj.subarraySum(nums, k);

    cout << ans << endl;

    return 0;
}
