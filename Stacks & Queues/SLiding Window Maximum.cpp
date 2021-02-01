/* https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1 */

vector <int> max_of_subarrays(int *arr, int n, int k){
    // your code here
    vector<int> ans;
    deque<int> subarr;
    int i=0;
    for(i=0;i<k;i++)
    {
        while(subarr.size()>0 && arr[i]>=arr[subarr.back()]) subarr.pop_back();
        subarr.push_back(i);
    }
    for(i;i<n;i++)
    {
        ans.push_back(arr[subarr.front()]);
        while(subarr.size()>0 && subarr.front()<=i-k) subarr.pop_front();
        while(subarr.size()>0 && arr[i]>=arr[subarr.back()]) subarr.pop_back();
        subarr.push_back(i);
    }
    ans.push_back(arr[subarr.front()]);
    return ans;
}