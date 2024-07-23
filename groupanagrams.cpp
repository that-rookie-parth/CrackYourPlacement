#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto i : strs){
            string word = i;
            sort(word.begin(), word.end());
            mp[word].push_back(i);
        }
        for(auto j : mp){
            ans.push_back(j.second);
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans;

    Solution obj;
    ans = obj.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}