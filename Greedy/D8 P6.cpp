/* https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1 */

bool cmp(struct Job j1, struct Job j2)
{
    return j1.profit>=j2.profit;
}
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr,arr+n,cmp);
    vector<int> mark(101);
    int prof=0;
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead;j>=1;j--)
        {
            if(mark[j]==0)
            {
                mark[j]=1;
                prof+=arr[i].profit;
                break;
            }
        }
    }
    pair<int,int> ans;
    ans.first=accumulate(mark.begin(),mark.end(),0);
    ans.second=prof;
    return ans;
} 