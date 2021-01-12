/* https://leetcode.com/problems/reverse-pairs/ */

class Solution {
public:
    
    vector<int> temp;
    int merge(vector<int>& nums,int s,int e)
    {
        int revpairs=0;
        int m=(s+e)/2;
        int i=s;
        int j=m+1;
        int k=s;
        int itr1=s,itr2=m+1;

        //Important part
        for(itr1=s;itr1<=m;itr1++)
        {
            while(itr2<=e && nums[itr1]>2LL*nums[itr2])
            {
                itr2++;
            }
            revpairs+=(itr2-m-1);       
        }
        
        while(i<=m && j<=e)
        {
            if(nums[i]<nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        while(i<=m) temp[k++]=nums[i++];
        while(j<=e) temp[k++]=nums[j++];
        for(int i=s;i<=e;i++)
        {
            nums[i]=temp[i];
        }
        return revpairs;
    }
    
    int mergeSort(vector<int>& nums,int s,int e)
    {
        if(e-s<=0) return 0;
        int m=(s+e)/2;
        int x=mergeSort(nums,s,m);
        int y=mergeSort(nums,m+1,e);
        int z=merge(nums,s,e);
        return x+y+z;
    }
    int reversePairs(vector<int>& nums) {
        temp.assign(nums.size()+5,0);
        return mergeSort(nums,0,nums.size()-1);
    }
};