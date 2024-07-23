#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        // reverse whole string
        reverse(s.begin(), s.end());

        int i=0, l=0, r=0;

        while(i<n){
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                i++;
                r++;
            }
            if(l<r){
                reverse(s.begin()+l, s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }

        s = s.substr(0, r-1);
        return s;
    }
};

int main(){
    string s = "a good   example", ans;

    Solution obj;
    ans = obj.reverseWords(s);

    cout << ans << endl;

    return 0;
}

// TC: O(N)
// SC: O(1)