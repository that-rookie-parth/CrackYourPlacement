#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int x = 0, y = n-1, maxVol=0;

        while(x<y){
            int smaller = (height[x]<height[y])?height[x]:height[y];
            int vol = (y-x)*smaller;
            if(vol>maxVol){
                maxVol = vol;
            }
            if(height[x]<height[y])
                x++;
            else
                y--;
        }
        return maxVol;
    }
};

int main(){
    vector<int> height = {2,3,4,5,18,17,6};
    int ans;

    Solution obj;
    ans = obj.maxArea(height);

    cout << ans << endl;    

    return 0;
}

// TC: O(N)
// SC: O(1)