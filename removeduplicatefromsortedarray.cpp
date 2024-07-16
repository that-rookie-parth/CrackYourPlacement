#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                i++;
                nums[i]=nums[j];
                j++;
            }
        }
        return i+1;
    }
};

int main(){
    int ans;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution obj;
    ans = obj.removeDuplicates(nums);

    cout << ans << endl;

    return 0;
}