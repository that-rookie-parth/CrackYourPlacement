#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        return index;
    }
};

int main(){
    string haystack = "sadbutsad", needle = "sad";
    int ans;

    Solution obj;
    ans = obj.strStr(haystack, needle);

    cout << ans << endl;

    return 0;
}

// TC: O(1)
// SC: O(1)