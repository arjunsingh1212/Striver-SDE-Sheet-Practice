/* https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1 */

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
        solve(A,n,B,val+A[n],temp,ans);
        n--;
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Your code here
    vector<vector<int>> ans;
    set<int> s(A.begin(),A.end());
    A.assign(s.begin(),s.end());
    reverse(A.begin(),A.end());
    int n=A.size();
    vector<int> temp;
    solve(A,n-1,B,0,temp,ans);
    set<vector<int>> s1(ans.begin(),ans.end());
    ans.assign(s1.begin(),s1.end());
    return ans;
}