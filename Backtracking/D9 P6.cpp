/* https://practice.geeksforgeeks.org/problems/word-break1352/1 */

int solve(string A,vector<string> &B)
{
    for(string x:B)
    {
        if(x==A) return 1;
    }
    if(A.length()<=1) return 0;
    for(int i=0;i<A.length()-1;i++)
    {
        if(solve(A.substr(0,i+1),B) && solve(A.substr(i+1,A.length()-1),B)) return 1;
    }
    return 0;
}

int wordBreak(string A, vector<string> &B) {
    //code here
    int ans=solve(A,B);
    return ans;
}