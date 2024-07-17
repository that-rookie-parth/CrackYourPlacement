#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();    // row
        int n = matrix[0].size(); // col

        int row[n] = {0};
        int col[m] = {0};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i]==1 || col[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
        return matrix;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    vector<vector<int>> ans;

    Solution obj;
    ans = obj.setZeroes(matrix);

    // Displaying the 2D vector
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << "\t";
        cout << endl;
    }

    return 0;
}

// TC: O(n*m)
// SC: O(n) + O(m)