/* https://leetcode.com/problems/merge-intervals/ */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> v=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>v[1])
            {
                ans.push_back(v);
                v=intervals[i];
            }
            else
            {
                v[1]=max(v[1],intervals[i][1]);
            }
        }
        ans.push_back(v);
        return ans;
    }
};