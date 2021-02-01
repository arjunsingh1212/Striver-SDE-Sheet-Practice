/* https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1 */

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> ans;
        if(k==1)
        {
            for(int i=0;i<n;i++) ans.push_back(arr[i]);
            return ans;
        }
        multiset<int> s;
        int i=0;
        for(;i<k-1;i++)
        {
            ans.push_back(-1);
            s.insert(arr[i]);
        }
        s.insert(arr[i]);
        i++;
        ans.push_back(*s.begin());
        for(;i<n;i++)
        {
            s.insert(arr[i]);
            s.erase(s.begin());
            ans.push_back(*s.begin());
        }
        return ans;
    }
};