#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max=-1, maxp=0;
        vector<int> aux(n);
        for (int i=n-1 ; i>=0 ; i--)
        {
            if(prices[i]>max){
                max = prices[i];
                aux[i] = max;
            }
            else{
                aux[i]=max;
            }
        }
        for (int i = 0; i < prices.size(); i++)
        {
            int profit = aux[i]-prices[i];
            if(profit>maxp){
                maxp = profit;
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

// TC: O(n)
// SC: O(n)