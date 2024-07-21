#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
		
		//First k elements in our window
        for(int i=0;i<k;i++) res+=cardPoints[i];
        
        int curr=res;
        for(int i=k-1;i>=0;i--) {
			//We remove the last visited element and add the non-visited element from the last
            curr-=cardPoints[i];
            curr+=cardPoints[cardPoints.size()-k+i];
			
            //We check the maximum value any possible combination can give
			res = max(res, curr);
        }
        
        return res;
    }
};

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k=3, ans;

    Solution obj;
    ans = obj.maxScore(cardPoints, k);

    cout << ans << endl;

    return 0;
}

// TC: O(k)
// SC: O(1)