/* https://leetcode.com/problems/3sum/ */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size())
        {
            int left=i+1, right=nums.size()-1;
            while(1)
            {
                if(left>=right || right<=i) break;
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    vector<int> x={nums[i],nums[left],nums[right]};
                    ans.push_back(x);
                    left++;
                    while(left<nums.size() && nums[left]==nums[left-1])
                    {
                        left++;
                    }

                    right--;
                    while(right>i && nums[right]==nums[right+1])
                    {
                        right--;
                    }
                }
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else right--;
                
            }
            i++;
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};