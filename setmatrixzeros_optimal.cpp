#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;   // this is the cell which overlaps
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // mark the col 0
                    matrix[i][0]=0;
                    // mark the row 0, remember the overlap
                    if(j!=0)
                        matrix[0][j]=0;
                    else
                        col0=0;
                }
            }
        }
        // this is for the sub matrix
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j]!=0)
                {
                    // check the col
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    } 
                }
            }
        }
        // this is for the row
        if(matrix[0][0]==0){
            for (int j = 0; j < n; j++)
            {
                matrix[0][j]=0;
            }
        }
        // this is for the column
        if(col0==0){
            for (int i = 0; i < m; i++)
            {
                matrix[i][0]=0;
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
// SC: O(1)