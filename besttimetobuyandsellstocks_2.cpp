#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0, num=prices[0], profit=0;
        for (int i = 1; i < prices.size(); i++)
        {
            if(num>prices[i]){
                num = prices[i];
            }
            else{
                profit = prices[i]-num;
                maxp = profit + maxp;
                num = prices[i];
            }
        }
        return maxp;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int ans;

    Solution obj;
    ans = obj.maxProfit(prices);
    cout << ans << endl;

    return 0;
}

// TC: O(N)
// SC: O(1)