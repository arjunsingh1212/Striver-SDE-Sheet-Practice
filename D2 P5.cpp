/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int mn=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            mn=min(mn,prices[i]);
            ans=max(ans,prices[i]-mn);
        }
        return ans;
    }
};