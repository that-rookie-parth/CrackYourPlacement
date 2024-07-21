#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        // base case
        if (n < 4)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int fix1 = nums[i];
            long long p = target - fix1;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int fix2 = nums[j];
                long long q = p - fix2;

                int x = j + 1;
                int y = n - 1;

                while (x < y)
                {
                    int sum = nums[x] + nums[y];
                    if (sum == q)
                    {
                        result.push_back({nums[x], nums[y], nums[j], nums[i]});
                        while (x < y && nums[x] == nums[x + 1])
                            x++;
                        while (x < y && nums[y] == nums[y - 1])
                            y--;
                        x++;
                        y--;
                    }
                    else if (sum > q)
                    {
                        y--;
                    }
                    else
                    {
                        x++;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans;

    Solution obj;
    ans = obj.fourSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

// TC: O(N*N*N)
// SC:O(1)