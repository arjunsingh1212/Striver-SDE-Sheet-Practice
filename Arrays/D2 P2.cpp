/* https://leetcode.com/problems/pascals-triangle/ */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows>=1)
            v.push_back(vector<int> (1,1));
        if(numRows>=2)
            v.push_back(vector<int> (2,1));
        for(int i=2;i<numRows;i++)
        {
            v.push_back(vector<int> (1,1));
            for(int j=1;j<i;j++)
            {
                v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v[i].push_back(1);
        }
        return v;
    }
};