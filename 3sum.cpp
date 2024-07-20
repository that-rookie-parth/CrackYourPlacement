// this will be an important question as here we also find out how to solve 2Sum if we have to return elements instead of index and also how to we can avoid duplicated, which is the contratint of this question
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // base case
        if(nums.size()<3){
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            // this is also important to avoid duplicates, that we do not fix the same elemnt again
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -(nums[i]);

            int x = i+1, y = nums.size()-1;
            while(x<y){
                int sum = nums[x]+nums[y];
                if(sum==target){
                    result.push_back({nums[x], nums[y], nums[i]});
                    while(x<y && nums[x]==nums[x+1]) x++;
                    while(x<y && nums[y]==nums[y-1]) y--;
                    x++;
                    y--;
                }
                else if(sum > target){
                    y--;
                }
                else{
                    x++;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans;

    Solution obj;
    ans = obj.threeSum(nums);

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(N*N)
// SC: O(1)