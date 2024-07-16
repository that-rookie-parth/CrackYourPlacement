#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void markRow(int i, vector<vector<int>>& matrix){
        for (int p = 0; p < matrix.size(); p++)
        {
            if(matrix[i][p]!=0){
                matrix[i][p]=-1;
            }
        } 
    }
    void markCol(int j, vector<vector<int>>& matrix){
        for (int q = 0; q < matrix[0].size(); q++)
        {
            if(matrix[q][j]=!0){
                matrix[q][j]=-1;
            }
        }
    }
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j]==0){
                    markRow(i, matrix);
                    markCol(j, matrix);
                }
            }
        }
        return matrix;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    vector<vector<int>> ans;

    Solution obj;
    ans = obj.setZeroes(matrix);

    // Displaying the 2D vector 
    for (int i = 0; i < ans.size(); i++) { 
        for (int j = 0; j < ans[i].size(); j++) 
            cout << ans[i][j] << "\t"; 
        cout << endl; 
    }

    return 0;
}