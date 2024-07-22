#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        /*
        dir = 0 -- left->right
        dir = 1 -- top->down
        dir = 2 -- right->left
        dir = 3 -- down->top
        */

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        int dir = 0;

        while (top <= down && left <= right)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                for (int i = top; i <= down; i++)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
                if(dir==2){
                for (int i = right; i >= left; i--)
                {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
                if(dir==3){
                for (int i = down; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans;

    Solution obj;
    ans = obj.spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << endl;

    return 0;
}

// TC: O(M*N)
// SC: O(1)