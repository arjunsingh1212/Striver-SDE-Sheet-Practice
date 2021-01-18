/* https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0 */

#include<bits/stdc++.h>
using namespace std;
void perm(string s,int l,int r, vector<string> &ans)
{
    if(l==r) ans.push_back(s);
    for(int i=l;i<=r;i++)
    {
        swap(s[l],s[i]);
        perm(s,l+1,r,ans);
        swap(s[l],s[i]);
    }
}
int main()
 {
	//code
	int t; cin>>t;
	while(t--)
	{
	    string s; cin>>s;
	    vector<string> ans;
	    perm(s,0,s.length()-1,ans);
	    sort(ans.begin(),ans.end());
	    for(auto x:ans) cout<<x<<" ";
	    cout<<endl;
	}
	return 0;
}