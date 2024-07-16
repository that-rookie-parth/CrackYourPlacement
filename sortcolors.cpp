// since we need the SC: O(1), we can't use any sorting algo, that's why we use this approach also known as Duth National Fla Approach
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int k = n-1;

        while (j<=k)
        {
            if(nums[j]==1)
                j++;
            else if(nums[j]==2){
                swap(nums[j], nums[k]);
                k--;
            }   
            else{
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }

        return nums;
    }
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    vector<int> ans;

    Solution obj;
    ans = obj.sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << endl;
    
    return 0;
}

// TC: O(n)
// SC: O(1)