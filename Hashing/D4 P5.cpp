/* Question Not Found for submission */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v={4,2,2,6,4};
    int k=6;
    int n=v.size();
    int ans=0;
    map<int,int> mp;
    mp[0]=1;
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr^=v[i];
        if(mp.count(xr^k)) 
        {
            ans+=mp[xr^k];
        }
        else
        {
            mp[xr]++;
        }
    }
    cout<<ans;
}