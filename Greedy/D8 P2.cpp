/* https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1 */

int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	vector<pair<int,char>> v;
	for(int i=0;i<n;i++) 
	{
	    v.push_back({arr[i],'a'});
	    v.push_back({dep[i],'d'});
	}
	sort(v.begin(),v.end());
    int ans=0;
    int cur=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second=='a') cur++;
        else cur--;
        ans=max(ans,cur);
    }
    return ans;
}