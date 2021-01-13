/* https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1 */

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mp;
    int ans=0;
    mp[0]=0;
    mp[A[0]]=0;
    for(int i=1;i<n;i++)
    {
        A[i]+=A[i-1];
        if(A[i]==0) ans=max(ans,i+1);
        if(mp.count(A[i])) ans=max(ans,i-mp[A[i]]);
        else
        {
            mp[A[i]]=i;
        }
    }
    return ans;
}