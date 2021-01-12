/* https://leetcode.com/problems/find-the-duplicate-number/ */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int head=0;
        int sp=0,fp=0;
        do
        {
            sp=nums[sp]; //Moving sp 1 step
            
            fp=nums[fp];
            fp=nums[fp]; //Moding fp 2 steps
        } while(nums[sp]!=nums[fp]);
        
        while(nums[head]!=nums[sp])
        {
            sp=nums[sp];
            head=nums[head];
        }
        
        return nums[head]; 
    }
};