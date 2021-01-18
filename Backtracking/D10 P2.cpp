/* https://leetcode.com/problems/combination-sum-ii/ */

class Solution {
public:
    
    void solve(vector<int> &A,int n,int B, int val,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(val==B) 
        {
            ans.push_back(temp);
            return;
        }
        if(n==-1 || val>B) return;
        while(n>=0 && val<=B)
        {
            temp.push_back(A[n]);
            solve(A,n-1,B,val+A[n],temp,ans);
            n--;
            temp.pop_back();
            solve(A,n-1,B,val,temp,ans);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        vector<vector<int>> ans;
        sort(A.begin(),A.end());
        reverse(A.begin(),A.end());
        int n=A.size();
        vector<int> temp;
        solve(A,n-1,B,0,temp,ans);
        set<vector<int>> s1(ans.begin(),ans.end());
        ans.assign(s1.begin(),s1.end());
        return ans;
    }
};