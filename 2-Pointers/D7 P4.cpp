/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/ */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=1;
        int j=1;
        while(j<nums.size())
        {
            if(nums[j]!=nums[j-1])
            {
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};