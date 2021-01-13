/* https://leetcode.com/problems/longest-substring-without-repeating-characters/ */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int l=0,r=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            r=i;
            if(mp.count(s[i]))
            {
                l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=i;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};