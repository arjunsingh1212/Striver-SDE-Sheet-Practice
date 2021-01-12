/* https://leetcode.com/problems/4sum/ */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<4) 
        {
            return ans;
        }
        for(int i=0;i<nums.size();)
        {
            for(int j=i+1;j<nums.size();)
            {
             
                int val=target-(nums[i]+nums[j]);
                int left=j+1,right=nums.size()-1;
                while(1)
                {
                    if(left>=right) break;
                    if(nums[left]+nums[right]==val)
                    {
                        vector<int> v={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(v);
                        left++;
                        while(left<nums.size() && nums[left]==nums[left-1]) left++;
                        right--;
                        while(right>=0 && nums[right]==nums[right+1]) right--;
                    }
                    else if(nums[left]+nums[right]<val)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                    if(left>=nums.size() || right<0) break;
                }
                j++;
                while(j<nums.size() && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};