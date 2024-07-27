#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+n);
        reverse(b, b+n);
        for(int i=0 ; i<n ; i++){
            if(a[i]+b[i]<k) return 0;
        }
        return 1;
    }
};

int main(){
    int n = 3, k = 10;
    long long a[3] = {2,1,3}, b[3] = {7,8,9};
    bool ans;

    Solution obj;
    ans = obj.isPossible(a, b, n, k);

    cout << ans << endl;

    return 0;
}