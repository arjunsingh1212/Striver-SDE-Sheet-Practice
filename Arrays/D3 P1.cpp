/* https://leetcode.com/problems/search-a-2d-matrix/ */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i=0,j=matrix[0].size()-1;
        bool ans=false;
        while(i<=matrix.size()-1 && j>=0)
        {
            if(matrix[i][j]==target)
            {
                ans=true;
                break;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};