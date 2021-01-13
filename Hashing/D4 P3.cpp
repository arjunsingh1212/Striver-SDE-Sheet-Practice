/* https://leetcode.com/problems/longest-consecutive-sequence/ */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!mp[nums[i]-1])
            {
                int count=0;
                int v=nums[i];
                while(mp[v])
                {
                    count++;
                    v++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};