#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int profit = 0;
            int max=prices[i];
            for (int j = i+1; j < prices.size(); j++)
            {
                if(max < prices[j]){
                    max = prices[j];
                }
            }
            profit = max - prices[i];
            if(profit>maxp){
                maxp = profit;
            }
        }
        return maxp;
    }
};

int main(){
    vector<int> prices = {7,6,4,3,1};
    int ans;

    Solution obj;
    ans = obj.maxProfit(prices);

    cout << ans << endl;

    return 0;
}

// TC: O(n^2)
// SC: O(1)