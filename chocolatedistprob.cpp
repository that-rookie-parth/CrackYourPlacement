#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long result=a[m-1] - a[0], diff=0;
        for(int i=1 ; i<=n-m ; i++){
            diff = a[i+m-1] - a[i];
            if(diff<result){
                result = diff;
            }
        }
        return result;
    }
};

int main()
{
    vector<long long> a = {11,13,7,5,13,12};
    long long n = 6, m = 4;
    long long ans;

    Solution obj;
    ans = obj.findMinDiff(a, n, m);

    cout << ans << endl;

    return 0;
}

// TC: O(N)
// SC: O(1)