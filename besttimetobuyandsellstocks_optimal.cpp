#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar=prices[0], maxp=0, profit=0;
        for (int i = 1; i < prices.size(); i++)
        {
            if(prices[i]<minsofar){
                minsofar = prices[i];
            }
            profit = prices[i]-minsofar;
            if(maxp<profit){
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

// TC: O(n)
// SC: O(1)