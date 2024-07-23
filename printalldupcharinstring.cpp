#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    unordered_map<char, int> dupInString(string s){
        unordered_map<char, int> mp;
        for(char &str : s){
            mp[str]++;
        }
        return mp;
    }
};

int main(){
    string s = "geeksforgeeks";
    unordered_map<char, int> ans;

    Solution obj;
    ans = obj.dupInString(s);

    for(auto i:ans){
        if(i.second>1)
            cout << i.first << ", count = " << i.second << endl;
    }

    return 0;
}

// TC: O(N)
// SC: O(N)